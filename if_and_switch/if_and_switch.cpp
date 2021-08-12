#if 0
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int a;

	while (1)
	{
		printf("숫자를 입력하세요: ");
		scanf("%d", &a);

		if (a == 1)
		{
			printf(">1 : One\n");
		}
		else if (a == 2)
		{
			printf(">2 : Two\n");
		}
		else if (a == 3)
		{
			printf(">3 : Three\n");
		}
		else if (a == 4)
		{
			printf(">4 : Four\n");
		}
		else if (a == 5)
		{
			printf(">5 : Five\n");
		}
		else if (a == 6)
		{
			printf(">6 : Six\n");
		}
		else if (a == 7)
		{
			printf(">7 : Seven\n");
		}
		else if (a == 8)
		{
			printf(">8 : Eight\n");
		}
		else if (a == 9)
		{
			printf(">9 : Nine\n");
		}
		else
		{
			break;
		}
	}
	printf("프로그램을 종료하려면 아무 키나 누르세요..."); getch();
}
#endif

#if 1
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int a;
	int b = 1;
	while (1) {
		printf("숫자를 입력하시오: ");
		//a = getch();
		scanf("%d", &a); // 'a' 일 경우 scanf 의 오류

		switch (a)
		{
			case 1:
				printf(">1 : one\n");
				break;
			case 2:
				printf(">2 : two\n");
				break;
			case 3:
				printf(">3 : Three\n");
				break;
			case 4:
				printf(">4 : Four\n");
				break;
			case 5:
				printf(">5 : Five\n");
				break;
			case 6:
				printf(">6 : Six\n");
				break;
			case 7:
				printf(">7 : Seven\n");
				break;
			case 8:
				printf(">8 : Eight\n");
				break;
			case 9:
				printf(">9 : Nine\n");
				break;
			default:
				break;
		}
		if (a == 0) break;
	}
}
#endif