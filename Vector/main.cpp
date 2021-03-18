#include "vector.h"

int main()
{
	Vector<int>* a = new Vector<int>(2);

	a->components[0] = 1;
	a->components[1] = 2;
	a->components[2] = '\0';
	a->VecPrint();
}