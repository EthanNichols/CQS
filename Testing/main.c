#include <conio.h>

#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

#include "../Include/Debug/Tracker.h"

int main(int argc, char* argv[]) {

	printf("hi");

	tracker_create();
	tracker_create();

	printf("hi");

	_getch();

	tracker_stop();
	
	_getch();

	return 0;
}