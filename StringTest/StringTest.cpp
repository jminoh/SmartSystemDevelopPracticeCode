#include <stdio.h>

int main(void)
{
	char str1[5] = "Good";
	char str2[] = "morning";
	char str3[] = "afternoon";
	char str4[] = "evening";
	int t;

	printf("지금 시각은? 24시간 기준으로 입력해 주세요.");
	scanf("%d", &t);

	if ((t >= 6) && (t < 12))
	{
		printf("%s %s", str1, str2);
	}
	else if ((t >= 12) && (t < 20))
	{
		printf("%s %s", str1, str3);
	}
	else if (((t >= 0) && (t < 6)) || ((t >= 20) && (t <= 24)))
	{
		printf("%s %s", str1, str4);
	}
	else
	{
		printf("잘못 입력하셨습니다.");
	}

	return 0;
}