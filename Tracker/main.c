#include <stdbool.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	printf(argv[0]);
	while (true);
	return 0;
}

/*
void read_from_pipe(int file) {
	FILE* stream;
	int c;
	stream = fdopen(file, "r");
	while ((c = fgetc(stream)) != EOF) {
		putchar(c);
	}

	fclose(stream);
}
*/