#include <stdio.h>

int main()
{
	// char, short, int, long, float, double 변수를 선언하고
	// 해당 data type의 byte 수를 출력하시오.
	char ch = 'a';
	short sho = 1;
	int age = 10;
	long lo = 123456789;
	float pi = 3.141592;
	double db = 1.414;
	printf("ch = %5c	sizeof(ch) = %d\n", ch, sizeof(ch));
	printf("sho = %5d	sizeof(sho) = %d\n", sho, sizeof(sho));
	printf("age = %5d	sizeof(age) = %d\n", age, sizeof(age));
	printf("lo = %5d	sizeof(lo) = %d\n", lo, sizeof(lo));
	printf("flo = %5f	sizeof(flo) = %d\n", pi, sizeof(pi));
	printf("db = %5lf	sizeof(db) = %d\n", db, sizeof(db));

	return 0;
}