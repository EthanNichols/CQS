#include <conio.h>

#include "../Include/Math/Matrix/matrix.h"

int main(int argc, char* argv[]) {

	matrix* mat = matrix_init(8, 8);
	matrix_identity(mat);

	matrix_printInt(*mat);

	_getch();

	return 0;
}