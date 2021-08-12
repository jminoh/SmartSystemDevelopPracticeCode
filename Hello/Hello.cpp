#include <stdio.h>
#include <conio.h>
int main()
{
	char name[20];
	int age;
	int height;
	float factor = 100.0;
	//int index = 0;  // while 문의 수행 횟수를 정의

	// while (index < 2)
	for(int index = 0; index < 2; index++)
	{
		printf("당신의 이름을 입력하세요: ");
		scanf("%s", name);

		printf("당신의 키를 cm단위로 입력하세요\n나이도 입력해 주세요: ");
		scanf("%d %d", &height, &age);

		printf("안녕하세요.\n%s씨\n", name);
		printf("반갑습니다.\n");
		printf("저는    %5d    살이에요.\n", age); // %d 10진 정수
		printf("제 키는 %5d    cm이에요.\n", height);
		printf("제 키는 %5.2f   m이에요.\n", (float)(height) / factor);

		//index++;
	}
	getch();
	
	return 0;
}
