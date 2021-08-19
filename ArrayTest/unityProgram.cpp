#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

const int students = 20;
int score()
{
	int i, j, k;
	double kortotal = 0, engtotal = 0, mattotal = 0, koravg = 0, engavg = 0, matavg = 0, tot = 0, avg = 0;
	double kor[students], eng[students], mat[students];

	srand(time(NULL));
	printf("   KOSTA 학생들 국어, 영어, 수학 점수 현황\n================================================\n\n\n");
	for (i = 0; i < students; i++)
	{
		kor[i] = ((rand() % 1000) + 1) / 10.0;  // rand: 난수 발생기 (정수) 0 ~ 100.0   %1000하면 0~999, 1 더해주고 /10
		eng[i] = ((rand() % 1000) + 1) / 10.0;												// 0.1 ~ 100
		mat[i] = ((rand() % 1000) + 1) / 10.0;
		kortotal += kor[i];
		engtotal += eng[i];
		mattotal += mat[i];
		printf("%2d번째 학생 국어점수: %4.1lf  영어점수: %4.1lf  수학점수: %4.1lf  ", i + 1, kor[i], eng[i], mat[i]);
		printf("총점: %5.1lf  평균: %4.1lf\n", kor[i] + eng[i] + mat[i], (kor[i] + eng[i] + mat[i]) / 3);
	}
	koravg = kortotal / students;
	engavg = engtotal / students;
	matavg = mattotal / students;
	tot = kortotal + engtotal + mattotal;
	avg = tot / (students * 3);
	printf("국어 총점: %6.1lf, 평균: %4.1lf\n", kortotal, koravg);
	printf("영어 총점: %6.1lf, 평균: %4.1lf\n", engtotal, engavg);
	printf("수학 총점: %6.1lf, 평균: %4.1lf\n", mattotal, matavg);
	printf("전체 총점: %6.1lf, 전체 평균: %4.1lf\n", tot, avg);

	return 0;
}
int Good()
{
	char good[5] = "Good";
	char mon[] = "morning"; // [8]
	char noon[] = "afternoon"; // [10]
	char even[] = "evening"; // [8]
	int t;


	printf("지금 시각은? 24시간 기준으로 입력해 주세요.");
	scanf("%d", &t);

	if ((t >= 6) && (t < 12))
	{
		printf("%s %s\n", good, mon);
	}
	else if (t < 20)  // (t >= 12) && (t < 20)
	{
		printf("%s %s\n", good, noon);
	}
	else if (((t >= 0) && (t < 6)) || (t <= 24))  // ((t >= 20)&&(t <= 24))
	{
		printf("%s %s\n", good, even);
	}
	else
	{
		printf("잘못 입력하셨습니다.\n");
	}

	return 0;
}
int PointerTest()
{
	int a[3][2] = { 1,2,3,4,5,6 };
	int b[3] = { 1,2,3 };
	int(*pa)[2] = a;

	printf("a[0] : %d \n", a[0]);
	printf("a[0] : %d \n", a[0]);
	printf("a[1] : %d \n", a[1]);
	printf("a[2] : %d \n", a[2]);
	printf("a    : %d \n\n\n\n", a);

	printf("a   : %d \n", a);
	printf("a+1 : %d \n", a + 1);
	printf("a+2 : %d \n\n\n\n", a + 2);
	printf("%d", a + 1);
	return 0;
}

// function define 
//     Prototype  :  int str_len(char *str)
// 문자열 str을 받아서 해당 문자열의 길이를 되돌려 줌.
int str_len(char* str)  // parameter로 배열이 아닌 포인터로 받음, [] == *, str[]도 가능
{						// 전제: 마지막에 '\0'이 붙어있다.
	int i, res = 0;
	// while (*(str + res++)); return res; // 아래 함수 한 줄로. 아무것도 안 하고 루프만 돌게
	while (1)
	{
		if (str[res] != 0) res++;   // '0' -> 문자열의 마지막에 존재하는 NULL
		else break;
	}
	return res;
}

int solution1()
{
	char s[80];				// 배열명은 포인터
	int i, funcres;
	printf("문자열을 입력하시오.");
	scanf("%s", s);

	funcres = str_len(s);
	printf("입력문자열 [%s]의 길이는 %d 입니다 \n", s, funcres);

	for (i = 0; i < funcres; i++)     // 비교문 내에 함수 있으면 별로 안 좋음
	{									// loop돌 때마다 함수 계산, 속도 느려짐
		if (s[i] != 0)
			printf("%c ", s[i]);
		else
			break;
	}
	return 0;
}
// function define 
//     Prototype  :  void swap(int a, int b)
// 정수 변수 a와 b의 값을 교환.
void swap(int* a, int* b)	// a,b를 포인터로 선언하고 전달된 매개변수 값으로 설정 (초기화)
{							// 포인터 사용방법 : 포인터가 가리키는 주소의 값 : *p
							//					 주소 자체 : p
	int c = *a;
	//	printf("	Input  > a(%08x) : %d, b(%08x) : %d\n", a, *a, b, *b);
	*a = *b;
	*b = c;
	//	printf("	Result > a(%08x) : %d, b(%08x) : %d\n", a, *a, b, *b);
}

int SwapTest()
{
	int a = 50, b = 60;
	printf("Original> a(%08x) : %d,  b(%08x) : %d\n", &a, a, &b, b);

	swap(&a, &b);

	printf("After swap> a(%08x) : %d,  b(%08x) : %d\n", &a, a, &b, b);

	return 0;
}

void  sort(int* a, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[i] < a[j]) swap(a + i, a + j); // =swap(&a[i], &a[j]); 
		}
	}
}

void swapEx(double* a, double* b)
{
	double c = *a;
	*a = *b;
	*b = c;
}

void swapEx1(char* a, char* b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void swapEx2(const char** a, const char** b)
{
	const char* c = *a;
	*a = *b;
	*b = c;
}

//struct student {
//	int kor;
//	int eng;
//	char name[10];
//};
//typedef struct student STU;
typedef struct {
	char name[10];
	int kor;
	int eng;
	double tot;
	double avg;
} STU;

void SWAP(void* a, void* b, int op)
{
	if (op == 1)	// char
	{
		char c = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = c;
	}
	if (op == 4)	// int, flo
	{
		int c = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = c;
	}
	if (op == 8)	// double
	{
		double c = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = c;
	}
	if (op == sizeof(STU))	// STU
	{
		STU c = *(STU*)a;
		*(STU*)a = *(STU*)b;
		*(STU*)b = c;
	}
}
// 전역변수 : 이하의 함수에서 사용 가능
const int nArr = 10;
int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
char nam[] = "ABCDEFGHIJK";//문자열 포인터로 변경 : "홍길동" "홍길이" "홍길삼" "홍길사" "홍길오" "길육" 길칠 길팔 길구 
const char* name[] = { "홍길동", "홍길이", "홍길삼", "홍길사", "홍길오", "맹일", "맹이", "맹삼", "맹사", "맹오" };
STU student[nArr];

void  sortEx(double* a, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[i] < a[j])
			{
				//swapEx(a + i, a + j); // =swap(&a[i], &a[j]);  // tot : double
				//swap(kor + i, kor + j);
				//swap(eng + i, eng + j);
				//swapEx2(name + i, name + j);
				SWAP(a + i, a + j, 8);
				SWAP(student + i, student + j, 18);
				//SWAP(kor + i, kor + j, 4);
				//SWAP(eng + i, eng + j, 4);
				//SWAP(name + i, name + j, 4);
			}
		}
	}
}
void  sortSTU(STU* a, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if ((a + i)->avg < (a + j)->avg)	// 구조체 포인터의 값  ===> a[i].avg < a[j].avg
			{
				SWAP(a + i, a + j, sizeof(STU));
			}
		}
	}
}

void sortTest()	//  배열을 이용한 성적처리
{
	double f_kor = 0.3, f_eng = 0.7;
	double tot[nArr];
	int i, j, k;

	for (i = 0; i < nArr; i++)
	{
		tot[i] = kor[i] * f_kor + eng[i] * f_eng;
	}
	printf("Original :\n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
}

void sortTestNew()		// 구조체를 이용한 성적처리
{
	double f_kor = 0.3, f_eng = 0.7;
	double tot[nArr];
	int i, j, k;

	for (i = 0; i < nArr; i++)
	{
		student[i].kor = kor[i];
		student[i].eng = eng[i];
		strcpy(student[i].name, name[i]);

		tot[i] = student[i].kor * f_kor + student[i].eng * f_eng;
	}
	printf("Original :\n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
}

void sortTestEx()		// 구조체를 이용한 성적처리 - 파일 입출력
{
	double f_kor = 0.3, f_eng = 0.7;
	double tot[nArr];
	int i, j, k;

	int m, n;
	char buf[1024];
	FILE* fin = fopen("C:\\Users\\snows\\table3.txt", "r");  // "r": read()  // table2의 data 가져올 수 있게	
	FILE* fout = fopen("C:\\Users\\snows\\table4.txt", "w+b");  // table4이라는 파일 생성해서 저장할 수 있도록

	for (i = 0; i < nArr; i++) fscanf(fin, "%s", student[i].name);
	for (i = 0; i < nArr; i++) fscanf(fin, "%d", &student[i].kor);
	for (i = 0; i < nArr; i++) fscanf(fin, "%d", &student[i].eng);
	for (i = 0; i < nArr; i++)
	{
		student[i].tot = student[i].kor + student[i].eng;
		student[i].avg = student[i].tot / 2;
	}
	printf("Original :\n");
	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", student[i].tot); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");

	printf("이름	국어	영어	합계	\n");
	fprintf(fout, "이름	국어	영어	합계	\n");  // table4에 써질 내용
	for (int i = 0; i < nArr; i++)
	{
		printf("%7s%7d%7d%7.2lf\n", student[i].name, student[i].kor, student[i].eng, student[i].tot);
		fprintf(fout, "%7s%7d%7d%7.2lf\n", student[i].name, student[i].kor, student[i].eng, student[i].tot);   // table4에 써질 내용
	}
}

void VoidPrint(void* p, int i)
{
	if (i == 1)
	{
		char* cp = (char*)p;
		printf("%c\n", *cp);
	}
	if (i == 2)	printf("%d\n", *(int*)p);
	if (i == 3)	printf("%f\n", *(double*)p);
}

void VoidTest()
{
	char c = 'z';
	int  n = 10;
	double a = 1.414;

	void* vp;
	VoidPrint(&c, 1);
	VoidPrint(&n, 2);
	VoidPrint(&a, 3);
}

void StreamTest()
{
	char buf[1024];
	FILE* f = fopen("C:\\Users\\snows\\aa", "r");  // "r": read()  // 없는 파일이면 NULL 반환
	FILE* fout0 = fopen("C:\\Users\\snows\\aa.o0", "w");  // "w": write,  fout0은 file pointer, write는 새 결과로 갈아치움 !=append
	FILE* fout1 = fopen("C:\\Users\\snows\\aa.o1", "a");  // 
	FILE* fout2 = fopen("C:\\Users\\snows\\aa.o2", "a+b");  // append: 새 결과는 기존 결과 밑에 덧붙임
	if (f != NULL)
	{
		while (1)										// "w": write()
		{
			if (fgets(buf, 1024, f) == NULL) break;		// 파일 입력 함수  , 한 줄 단위로 읽어옴
			//if (strlen(buf) < 3) break;  // 엔터도 0 아님. Ctrl+C로 탈출
			//fputs("==== 입력문자열 =====>", stdout);
			fputs(buf, stdout); // 화면 출력
			fputs(buf, fout0);
			fputs(buf, fout1);
			fputs(buf, fout2);
		}
	}
	else printf("입력 파일이 존재하지 않습니다.\n");
}


int main()
{
	int pick = 0, stop = 1;

	while (stop)
	{
		printf("\n\n***** 프로그램 목록 *****\n\n");
		printf("	1. score();\n");
		printf("	2. Good();\n");
		printf("	3. PointerTest();\n");
		printf("	4. solution1();\n");
		printf("	5. SwapTest();\n");
		printf("	6. sortTestNew();\n");
		printf("	7. VoidTest();\n");
		printf("	8. StreamTest();\n");
		printf("	9. sortTestEx();\n");
		printf("	0. Exit\n");
		printf("=========================\n");
		printf("	Select Menu\n\n");

		scanf("%d", &pick);
		switch (pick)
		{
		case 1: score(); break;
		case 2: Good(); break;
		case 3: PointerTest(); break;
		case 4: solution1(); break;
		case 5: SwapTest(); break;
		case 6: sortTestNew(); break;
		case 7: VoidTest(); break;
		case 8: StreamTest(); break;
		case 9: sortTestEx(); break;
		case 0: stop = 0; break;
		default: stop = 0; break;
		}
	}
}
#endif