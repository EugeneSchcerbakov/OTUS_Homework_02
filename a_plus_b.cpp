#include "a_plus_b.h"

int A_Plus_B(int a, int b)
{
	return a + b;
}

bool A_Plus_B_Test()
{
	int a = 1;
	int b = 5;
	int result = 6;

	return A_Plus_B(a, b) == result;
}
