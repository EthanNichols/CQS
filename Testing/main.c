#include <conio.h>

#include "../Include/Math/Vectors/vector2.h"

int main(int argc, char* argv[]) {

	vector2* vec = vector2_init(13.245, 10);
	vector2_printInt(*vec);
	vector2_printFloat(*vec);
	vector2_printFormat(*vec, 2);

	_getch();

	return 0;
}