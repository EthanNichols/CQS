#include <conio.h>

#include "../Include/Math/Matrix/matrix2x2.h"

int main(int argc, char* argv[]) {

	matrix2x2 mat = matrix2x2_identity;

	matrix2x2_printInt(mat);

	_getch();

	return 0;
}