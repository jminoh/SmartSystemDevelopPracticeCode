#include <stdio.h>
#include <conio.h>

  // Function Test 프로그램
  // 기능 : 키보드에서 단일 문자를 입력받고
  //		해당 문자가 대문자/소문자/특수문자/숫자 임을 분류
  // -- 함수를 선언하고 호출할 것.


int sub(char a);  // sub function의 prototype(함수의 원형)

int main(void)
{
	char a;
	int re;
	while (1)
	{
		printf("아무키나 누르세요: \n");
		a = getch();
		//re = sub(a);

		switch (sub(a))
		{
		case 0:
			printf("> 입력하신 Key [%c]는 대문자입니다.\n", a);
			break;
		case 1:
			printf("> 입력하신 Key [%c]는 소문자입니다.\n", a);
			break;
		case 2:
			printf("> 입력하신 Key [%c]는 특수문자입니다.\n", a);
			break;
		case 3:
			printf("> 입력하신 Key [%c]는 숫자입니다.\n", a);
			break;
		case 4:
			printf("> 입력하신 Key는 제어문자입니다. 다른 키를 입력해 주세요.\n");
			break;
		default:
			break;
		}

		if (a == 'z') break;
	}
	return 0;
}

int sub(char a)
{
	int para = a;
	int ret= 0;

	if ((para >= 65) && (para <= 90)) // A~Z
	{
		printf("> 입력하신 Key [%c]는 대문자입니다.\n", para);
		ret = 0;
	}
	else if ((para >= 97) && (para <= 122)) // a~z
	{
		printf("> 입력하신 Key [%c]는 소문자입니다.\n", para);
		ret = 1;
	}
	else if (((para >= 32) && (para <= 47)) || ((para >= 58) && (para <= 64)) || ((para >= 91) && (para <= 96))
		|| ((para >= 123) && (para <= 127)))
	{
		printf("> 입력하신 Key [%c]는 특수문자입니다.\n", para);
		ret = 2;
	}
	else if ((para >= 48) && (para <= 57)) // 0~9
	{
		printf("> 입력하신 Key [%c]는 숫자입니다.\n", para);
		ret = 3;
	}
	else
	{
		printf("> 입력하신 Key는 제어문자입니다. 다른 키를 입력해 주세요.\n");
		ret = 4;
	}

	return ret;
}