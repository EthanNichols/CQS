
#include "Debug\Tracker.h"

int main(int argc, char* argv[]) {

	tracker_openFile("Log.txt");

	tracker_openFile("Log.txt");

	printf("Hello1");


	_getch();

	printf("Hello2");

	tracker_log("Hello Test");

	tracker_closeFile();

	tracker_log("Hello Test");
	
	_getch();

	tracker_openFile("Name");

	tracker_log("Hello Test");

	printf("Hello3");

	_getch();

	tracker_closeFile();

	return 0;
}