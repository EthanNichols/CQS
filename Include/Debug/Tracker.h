#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

#define BUF_SIZE 2048
#define FILE_PATH "Pipe.txt"

static STARTUPINFO si;
static PROCESS_INFORMATION pi;
static SECURITY_ATTRIBUTES sa;
static HANDLE childStdOut_r = NULL;
static HANDLE childStdOut_w = NULL;
static HANDLE childStdIn_r = NULL;
static HANDLE childStdIn_w = NULL;

static HANDLE inputFile = NULL;

static TCHAR cmdLine[] = TEXT("Child");
static TCHAR inputPipe[] = TEXT("Child");

static bool tracker_exists = false;

static void tracker_write() {
	DWORD read = "";
	DWORD write = "";
	char cBuf[BUF_SIZE];
	bool success = false;

	while (true)
	{
		success = ReadFile(inputFile, cBuf, BUF_SIZE, &read, NULL);

		if (!success || read == 0 || !tracker_exists) break;

		success = WriteFile(childStdIn_w, cBuf, read, &write, NULL);

		if (!success || !tracker_exists) break;
	}

	CloseHandle(childStdIn_w);
}

static void tracker_read() {
	DWORD read = "";
	DWORD write = "";
	char cBuf[BUF_SIZE];
	bool success = false;
	HANDLE parentStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true)
	{
		success = ReadFile(childStdOut_r, cBuf, BUF_SIZE, &read, NULL);

		if (!success || read == 0 || !tracker_exists) break;

		success = WriteFile(parentStdOut, cBuf, read, &write, NULL);

		if (!success || !tracker_exists) break;
	}
}

static void tracker_stop() {

	tracker_exists = false;
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

static void tracker_startprocess() {

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	si.cb = sizeof(STARTUPINFO);
	si.hStdOutput = childStdOut_w;
	si.hStdInput = childStdIn_r;
	si.dwFlags |= STARTF_USESTDHANDLES;

	inputFile = CreateFile(
		FILE_PATH,
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_READONLY,
		NULL);

	if (CreateProcess(
		"../_Binary/Tracker_d.exe",
		cmdLine,
		NULL,
		NULL,
		false,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi
	)) {
	}
	else if (CreateProcess(
		"../_Binary/Tracker.exe",
		cmdLine,
		NULL,
		NULL,
		false,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi)) {
	}
	else {
		tracker_stop();

		printf("The tracker exe does not exist\n");
		printf("Build the tracker project\n");
		printf("Or move the tracker exe to the build folder\n");
	}
}

static void tracker_create() {

	if (tracker_exists) {
		printf("A tracker already exists!\n");
		return;
	}
	tracker_exists = true;

	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = true;
	sa.lpSecurityDescriptor = NULL;

	CreatePipe(&childStdOut_r, &childStdOut_w, &sa, 0);
	//SetHandleInformation(childStdOut_r, HANDLE_FLAG_INHERIT, 0);

	CreatePipe(&childStdOut_r, &childStdOut_w, &sa, 0);
	//SetHandleInformation(childStdIn_r, HANDLE_FLAG_INHERIT, 0);

	tracker_startprocess();
	tracker_write();
	tracker_read();
}