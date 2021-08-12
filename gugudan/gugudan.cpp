#include <stdio.h>
#include <conio.h>
int main(void)
{
	int dan = 1, nDan = 9, i, j;
	int hDan = 3;  // horizontal


	for (; dan <= 9; dan += hDan) // 2 ~ 9단
	{
		for (j = 1; j <= 9; j++) // 1 ~ 9까지 반복
		{
			for (i = 0; i < hDan; i++)
			{
				printf("%2d x %2d = %3d\t", dan + i, j, (dan + i) * j); // 해당 단 * 1~9까지 반복
			}
			printf("\n");
		}
		printf("\n");
	}

	getch();
}