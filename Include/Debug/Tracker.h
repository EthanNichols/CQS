#define __STDC_WANT_LIB_EXT1__ 1
#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define TIME_STRING_LENGTH 32
#define PATH_STRING_LENGTH 64
#define INFO_STRING_LENGTH 512
#define MSG_STRING_LENGTH 1024
#define LOG_FILE_PATH "Log_Files/"

#define LOG "Log"
#define WARNING "Warning"
#define ERROR "Error"
#define INFO "Info"
#define TYPE_SEPERATOR ": "
#define TIME_SEPEARTOR " - "

static FILE* file;
static char filePath[TIME_STRING_LENGTH];
static char strTime[TIME_STRING_LENGTH];

/// Get a formatted time for a timestamp
static char* tracker_time() {
	time_t t = time(NULL);

	struct tm tmTime;
	localtime_s(&tmTime, &t);
	asctime_s(strTime, TIME_STRING_LENGTH, &tmTime);

	strftime(strTime, TIME_STRING_LENGTH, "%D %H:%M:%S", &tmTime);

	return strTime;
}

/// Get a custom formatted time
static char* tracker_timeFormat(char* format) {
	time_t t = time(NULL);

	struct tm tmTime;
	localtime_s(&tmTime, &t);
	asctime_s(strTime, TIME_STRING_LENGTH, &tmTime);

	strftime(strTime, TIME_STRING_LENGTH, format, &tmTime);

	return strTime;
}

/// Format the message with a time and message type before the message
static char* tracker_formatMsg(const char* msgType, const char* msg) {
	char formattedMsg[MSG_STRING_LENGTH];
	char* strTime = tracker_time();
	strcpy_s(formattedMsg, MSG_STRING_LENGTH, strTime);
	strcat_s(formattedMsg, MSG_STRING_LENGTH, TIME_SEPEARTOR);
	strcat_s(formattedMsg, MSG_STRING_LENGTH, msgType);
	strcat_s(formattedMsg, MSG_STRING_LENGTH, TYPE_SEPERATOR);
	strcat_s(formattedMsg, MSG_STRING_LENGTH, msg);
	strcat_s(formattedMsg, MSG_STRING_LENGTH, "\n");

	return formattedMsg;
}

/// Log a normal message
static void tracker_log(const char* msg) {
	if (file != NULL) {
		fprintf(file, tracker_formatMsg(LOG, msg));
	}
}

/// Log a warning
static void tracker_warning(const char* msg) {
	if (file != NULL) {
		fprintf(file, tracker_formatMsg(WARNING, msg));
	}
}

/// Log and error
static void tracker_error(const char* msg) {
	if (file != NULL) {
		fprintf(file, tracker_formatMsg(ERROR, msg));
	}
}

/// Log information about the location of this function call
/* Finish implementing later
static void tracker_codeInfo(const char* file, const int line, const char* function, const char* msg) {
	if (file != NULL) {

		char fullMsg[INFO_STRING_LENGTH];
		strcpy_s(fullMsg, INFO_STRING_LENGTH, file);
		//strcat_s(fullMsg, INFO_STRING_LENGTH, line);
		//strcat_s(fullMsg, INFO_STRING_LENGTH, function);
		//strcat_s(fullMsg, INFO_STRING_LENGTH, msg);


		fprintf(file, tracker_formatMsg(INFO, fullMsg));
	}
}
*/

/// Create and open a log file names to the current time
/// One log file is created the first time this function is called in a program
static void tracker_openFile(const char* fileName) {

	if (file != NULL) {
		tracker_warning("File has already been created, but a new file was going to be made");
		return;
	}

	printf("Opening");

	// Set the file path if there wasn't one already
	if (filePath[0] == NULL) {
		char fileNamePath[PATH_STRING_LENGTH];
		strcpy_s(fileNamePath, PATH_STRING_LENGTH, LOG_FILE_PATH);
		strcat_s(fileNamePath, PATH_STRING_LENGTH, tracker_timeFormat("%d.%m.%y %H.%M.%S "));
		strcat_s(fileNamePath, PATH_STRING_LENGTH, fileName);

		strcpy_s(filePath, PATH_STRING_LENGTH, fileNamePath);
	}

	fopen_s(&file, filePath, "w");

	tracker_log("File Opened");
}

/// Close the file that has been logged to
static void tracker_closeFile() {
	if (file != NULL) {
		tracker_log("File Closed");
		fclose(file);
		file = NULL;
	}
}