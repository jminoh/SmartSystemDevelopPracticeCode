#if 0
#include <stdio.h>

int main(void)
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
#endif

#if 0
// Pointer Test
#include <stdio.h>
int main(void)
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
	printf("a+1 : %d \n", a+1);
	printf("a+2 : %d \n\n\n\n", a + 2);
	printf("%d", a + 1);
	return 0;
}
#endif

#if 0
// 실습 1
#include <stdio.h>
// function define
// Prototype: int str_len(char *str)	문자열(문자 배열, 포인터)을 파라미터로 받을 때 * 사용
// 문자열 str을 받아서 해당 문자열의 길이를 되돌려 줌.
int str_len(char* str);
int main(void)		
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
}
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
	
#endif

#if 0
// 실습 2
// 입력한 숫자에 해당하는 인덱스가 가지고 있는 값 반환
#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(void)
{
	char s[11], click;
	printf("10자 내로 문자열을 입력하시오.\n");
	scanf("%s", s);

	printf("0~9의 숫자 중 하나를 입력하시오.\n");
	while (1)							// 인덱스에 해당하는 숫자 바로바로 출력을 계속 함.
	{
		click = getch() - 48;             // 0~9 숫자 키 (아스키 코드)입력
		if (click >= 0 && click <= 9)
		{
			printf("%c", s[click]);       // click - 48 = 아스키 코드값으로 숫자
			continue;
		}
		else                                   // click 반환형이 char이기 때문
		{
			break;
		}
	}
	switch (click)             
	{									
	case 0:
		printf("%c", s[0]); break;
	case 1:
		printf("%c", s[1]); break;
	case 2:
		printf("%c", s[2]); break;
	case 3:
		printf("%c", s[3]); break;
	case 4:
		printf("%c", s[4]); break;
	case 5:
		printf("%c", s[5]); break;
	case 6:
		printf("%c", s[6]); break;
	case 7:
		printf("%c", s[7]); break;
	case 8:
		printf("%c", s[8]); break;
	case 9:
		printf("%c", s[9]); break;
	default: break;
	}

}
#endif

#if 0
// 다양한 형태의 배열 요소 접근 방법
#include <stdio.h>
int main(void)
{
	int a[3][2] = { {1,2}, {3,4}, {5,6} };
	int b[7] = { 1,2,3,4,5,6 };
	printf("a[0]   : %d \n", a[0]);
	printf("*(a+0) : %d \n", *(a + 0));

	printf("a[1]   : %d \n", a[1]);
	printf("(a+1) : %d \n", (a + 1));
	printf("*(a+1) : %d \n", *(a + 1));

	printf("a[2]   : %d \n", a[2]);
	printf("*(a+2) : %d \n", *(a + 2));

	printf("%d, %d \n", a[1][0], (*(a + 1))[0]);
	printf("%d, %d \n", a[1][2], *(a[1]+2));
	printf("%d, %d \n", a[2][1], *(*(a + 2)+1));

	return 0;
}
#endif

#if 0
//4강 마지막 실습
//두 과목의 성적이 다음과 같을 때 배열을 이용하여 초기화하고,
//각각의 성적에 가중치를 곱한 후 개인별 합계를 구하여 합이 큰 순서대로
//정렬하여 출력하라.
//- 자료(예)
//이름 A   B   C   D   E   F   G
//국어 82  93  71  69  78  84  75 - 가중치 0.3
//영어 76  91  67  73  86  63  83 - 가중치 0.7
#include <stdio.h>
const int students = 10;
void swapTest(double sorting[][students]);  // 선언, 정의 때는 배열정보도!!!
int main(void)
{
	int kor[] = { 82, 93, 71, 69, 78, 84, 75, 45, 100, 66 };
	int eng[] = { 76, 91, 67, 73, 86, 63, 83, 95, 62, 81 }; // 배열 개수: sizeof(배열명)/sizeof(배열요소)
	double sort[2][students];
	int i, j;

	for (i = 0; i < students; i++)
	{
		sort[0][i] = (kor[i] * 0.3) + (eng[i] * 0.7);
		sort[1][i] = i + 65;    // 아스키코드 A
	}

	swapTest(sort);      // 호출 때는 무조건 배열명만!!!

	// 안 되는 거.
	//for (j = 0; j < students; j++)
	//{
	//	sort[1][i] = (int)sort[1][i];		// 배열이 double, (int)형변환 이후 다시 double에 넣어주면 
	//	printf("%d\n", sort[1][i]);			// 소수점만 없애고 double에 다시 넣은 격. 안 됨.
	//}

	printf("순위:  이름  국어  영어  합계\n");
	for (i = 0; i < students; i++)
	{
		printf("%4d:%5c%7d%7d%7.2lf\n", i+1, (int)sort[1][i], kor[(int)sort[1][i] - 65], eng[(int)sort[1][i] - 65], sort[0][i]);
	}										// 다른 배열이기 때문에 직접적으로 표시할 수는 없으나, 이름도 최초에 정렬되었기 때문에 이름을 이용
}							// 이름 표현 위해 붙어있는 아스키코드 사용. int로 바꾸고 -65 하면 최초의 인덱스 나옴. 해당 인덱스를 kor배열에 사용.

void swapTest(double sorting[][students])
{
	double temp, tempch;
	int i,j;
	/*for (j = 0; j < students; j++)
	{
		for (i = 0; i < students; i++)
		{
			if (sorting[0][i] < sorting[0][i + 1])
			{
				temp = sorting[0][i];
				sorting[0][i] = sorting[0][i + 1];
				sorting[0][i + 1] = temp;

				tempch = sorting[1][i];
				sorting[1][i] = sorting[1][i + 1];
				sorting[1][i + 1] = tempch;

			}
		}
	}*/
	for (i = 0; i < students; i++)
	{
		for (j = i; j < students; j++)
		{
			if (sorting[0][i] < sorting[0][j])
			{
				temp = sorting[0][i];
				sorting[0][i] = sorting[0][j];
				sorting[0][j] = temp;

				tempch = sorting[1][i];
				sorting[1][i] = sorting[1][j];
				sorting[1][j] = tempch;
			}
		}
	}
}
#endif

#if 0
// 4강 마지막 실습 강사님
#include <stdio.h>
void sortEx(double* arr, int n); 
void swap(int* a, int* b);
void swapEx(double* a, double* b);
void swapEx1(char* a, char* b);
void swapEx2(const char** a, const char** b);
void SWAP(void* a, void* b, int op);

int kor[] = {67, 70, 77, 65, 68, 72, 79, 55, 85, 61};  //  전역 변수화: 이하의 함수에서 사용 가능
int eng[] = {70, 75, 80, 60, 65, 55, 80, 95, 67, 84};
const int nArr = 10;
char nam[] = "ABCDEFGHIJK";
const char* name[] = { "김씨", "이씨", "박씨", "최씨", "안씨", "정씨", "소씨", "조씨", "허씨", "심씨" };  // 포인터 배열, String Array

int main(void)
{
	double f_kor = 0.3, f_eng = 0.7;

	double tot[nArr];
	int i, j, k;

	for (i = 0; i < nArr; i++)
	{
		tot[i] = kor[i] * f_kor + eng[i] * f_eng;
	}
	printf("Original :\n");
	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7c ", nam[i]); printf("\n\n");
	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("국어: "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("영어: "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("합계: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");
	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7c ", nam[i]); printf("\n\n");
	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("국어: "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("영어: "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("합계: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");
	return 0;
}
void sortEx(double* arr, int nArr) 
{							
	int i, j, temp;
	for (i = 0; i < nArr; i++)
	{
		for (j = i; j < nArr; j++) 
		{
			if (arr[i] < arr[j])                              // swap 함수 사용해도 됨.
			{
				/*temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

				temp = kor[i];
				kor[i] = kor[j];
				kor[j] = temp;

				temp = eng[i];
				eng[i] = eng[j];
				eng[j] = temp;

				temp = nam[i];
				nam[i] = nam[j];
				nam[j] = temp;*/

				swapEx(arr + i, arr + j);    // = swap(&a[i], &a[j]); // tot: double
				swap(kor + i, kor + j);      // kor: int
				swap(eng + i, eng + j);      // eng: int
				swapEx1(nam + i, nam + j);     
				swapEx2(name + i, name + j);
			}
		}
	}
}
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
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
void swapEx2(const char** a, const char** b)   // Data type 맞춰주는 것이 우선. // parameter: string*(4byte 변수), 주소가 전달된 것.
{											// 내용 바뀐 것 없음, 값이 바뀌려면 * 필요    // const char* a[], const char* b[]
	const char *c = *a;		// c* = a[]
	*a = *b;				// a[0] = b[0]
	*b = c;					// b[0] = c
}
void SWAP(void* a, void* b, int op)  // 포인터 받아주는 쪽에서 void 하면, 함수 호출시 void포인터에 넣을 필요 없음. 포인터만 던지면 됨.
{										//	op는 자료형의 크기
	if (op == 1)			//char
	{
		char c = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = c;
	}
	else if (op == 4)		//int, float,
	{
		int c = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = c;
	}
	else if (op == 8)			//double
	{
		double c = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = c;
	}
}
#endif


#if 0
// Sort, 이중 반복문이 기준. 가장 normal한 정렬방식
#include <stdio.h>
void sort(int *arr, int nArr);
int main(void)
{
	int nArr = 11;
	int arr[] = { 25, 27, 30, 47, 35, 68, 40, 79, 45, 85, 50 };

	printf("Original : "); for (int i = 0; i < nArr; i++) printf("%d  ", arr[i]);
	printf("\n\n");
	
	sort(arr, nArr);
	printf("Sorted : "); for (int i = 0; i < nArr; i++) printf("%d  ", arr[i]);
	printf("\n\n");

}

void sort(int *arr, int nArr)  // a[i]기준으로 그 뒤의 것들 비교
{								// a[i] 이전 것들은 이미 큰 것부터 정렬됨.
	int i, j, temp;
	for (i = 0; i < nArr; i++)
	{
		for (j = i; j < nArr; j++) // j = i;여도 됨
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			// if(a[i] < a[j]) swap(&a[i], &a[j]); // swap(a +  i, a + j);
		}
	}
}
#endif

#if 0
// Void Test
#include <stdio.h>

void VoidPrint(void* p, int i)
{
	if (i == 1)
	{
		char* cp = (char*)p;
		printf("%c\n", *cp);
	}
	if (i == 2) printf("%d\n", *(int*)p);
	if (i == 3) printf("%f\n", *(double*)p);


}
int main(void)
{
	char c = 'z';
	int n = 10;
	double a = 1.414;

	void* vp;
	VoidPrint(vp = &c, 1);
	VoidPrint(vp = &n, 2);
	VoidPrint(vp = &a, 3);
}
#endif

#if 0
//void 포인터로 swap함수 재정의
#include <stdio.h>
void SWAP(void *p1, void *p2, int op);   // op는 자료형 크기
int main(void)
{

	int n[] = { 1,2,3,4,5 };
	SWAP(n+1, n+2, 4);

	for (int i = 0; i < sizeof(n) / sizeof(n[0]); i++)
		printf("%d  ", n[i]);
}

void SWAP(void* a, void* b, int op)  // 포인터 받아주는 쪽에서 void 하면, 함수 호출시 void포인터에 넣을 필요 없음. 포인터만 던지면 됨.
{
	if (op == 1)			//char
	{
		char c = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = c;
	}
	else if (op == 4)		//int, float, char*
	{
		int c = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = c;
	}
	else if (op == 8)			//double
	{
		double c = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = c;
	}
}
#endif

#if 0
// 6장 마지막 성적처리 프로그램 구조체로 재구성하기


#include <stdio.h>
#include <string.h>
void sortEx(double* arr, int n);
void swap(int* a, int* b);
void swapEx(double* a, double* b);
void swapEx1(char* a, char* b);
void swapEx2(const char** a, const char** b);
void SWAP(void* a, void* b, int op);
void inpuStruct(struct student a[], int b[], int c[], const char* d[]);

struct student {
	int kor;
	int eng;
	char name[10];
}; 

struct student st[10];


int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };  //  전역 변수화: 이하의 함수에서 사용 가능
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
const int nArr = 10;
char nam[] = "ABCDEFGHIJK";
const char* name[] = { "김씨", "이씨", "박씨", "최씨", "안씨", "정씨", "소씨", "조씨", "허씨", "심씨" };  // 포인터 배열, String Array


int main(void)
{
	inpuStruct(st, kor, eng, name);
	double f_kor = 0.3, f_eng = 0.7;

	double tot[nArr];
	int i, j, k;
	printf("%d %d ", st[0].kor, st[0].eng);

//	for (i = 0; i < nArr; i++)
//	{
//		tot[i] = kor[i] * f_kor + eng[i] * f_eng;
//	}
//	printf("Original :\n");
//	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7c ", nam[i]); printf("\n\n");
//	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
//	printf("국어: "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
//	printf("영어: "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
//	printf("합계: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");
//
//	sortEx(tot, nArr);
//
//	printf("Sorted :\n");
//	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7c ", nam[i]); printf("\n\n");
//	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
//	printf("국어: "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
//	printf("영어: "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
//	printf("합계: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");
//	return 0;
//}
//void sortEx(double* arr, int nArr)
//{
//	int i, j, temp;
//	for (i = 0; i < nArr; i++)
//	{
//		for (j = i; j < nArr; j++)
//		{
//			if (arr[i] < arr[j])                              // swap 함수 사용해도 됨.
//			{
//				/*temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//
//				temp = kor[i];
//				kor[i] = kor[j];
//				kor[j] = temp;
//
//				temp = eng[i];
//				eng[i] = eng[j];
//				eng[j] = temp;
//
//				temp = nam[i];
//				nam[i] = nam[j];
//				nam[j] = temp;*/
//
//				swapEx(arr + i, arr + j);    // = swap(&a[i], &a[j]); // tot: double
//				swap(kor + i, kor + j);      // kor: int
//				swap(eng + i, eng + j);      // eng: int
//				swapEx1(nam + i, nam + j);
//				swapEx2(name + i, name + j);
//			}
//		}
//	}
}
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
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
void swapEx2(const char** a, const char** b)   // Data type 맞춰주는 것이 우선. // parameter: string*(4byte 변수), 주소가 전달된 것.
{											// 내용 바뀐 것 없음, 값이 바뀌려면 * 필요    // const char* a[], const char* b[]
	const char* c = *a;		// c* = a[]
	*a = *b;				// a[0] = b[0]
	*b = c;					// b[0] = c
}
void SWAP(void* a, void* b, int op)  // 포인터 받아주는 쪽에서 void 하면, 함수 호출시 void포인터에 넣을 필요 없음. 포인터만 던지면 됨.
{										//	op는 자료형의 크기
	if (op == 1)			//char
	{
		char c = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = c;
	}
	else if (op == 4)		//int, float,
	{
		int c = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = c;
	}
	else if (op == 8)			//double
	{
		double c = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = c;
	}
}
void inpuStruct(struct student a[], int b[], int c[], const char* d[])
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		st[i] = { b[i], c[i], strcpy(st[i].name, d[i]) };
	}
}
#endif

#if 1
// 6장 구조체 실습 강사님
/*struct student {
	int kor;
	int eng;
	char name[10];
};*/

#include <stdio.h>
#include <string.h>
typedef struct student {
	int kor;
	int eng;
	char name[10];
} STU;


void sortEx(double* arr, int n);
void swap(int* a, int* b);
void swapEx(double* a, double* b);
void swapEx1(char* a, char* b);
void swapEx2(const char** a, const char** b);
void SWAP(void* a, void* b, int op);

int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };  //  전역 변수화: 이하의 함수에서 사용 가능
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
const int nArr = 10;
char nam[] = "ABCDEFGHIJK";
const char* name[] = { "김씨", "이씨", "박씨", "최씨", "안씨", "정씨", "소씨", "조씨", "허씨", "심씨" };  // 포인터 배열, String Array
STU student[nArr];

int main(void)
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
		//tot[i] = (student[i].kor = kor[i]) * f_kor + (student[i].eng = eng[i]) * f_eng; // 위 세 주석 한 줄로 합침.
	}											// 점수를 구조체의 멤버변수에 대입하고, 가중치 곱함. 가중치 곱해진 두 점수를 더해 tot에 대입.
	printf("Original :\n");
	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");
	printf("이름: "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");
	return 0;
}
void sortEx(double* arr, int nArr)
{
	int i, j, temp;
	for (i = 0; i < nArr; i++)
	{
		for (j = i; j < nArr; j++)
		{
			if (arr[i] < arr[j])                              // swap 함수 사용해도 됨.
			{
				/*temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

				temp = kor[i];
				kor[i] = kor[j];
				kor[j] = temp;

				temp = eng[i];
				eng[i] = eng[j];
				eng[j] = temp;

				temp = nam[i];
				nam[i] = nam[j];
				nam[j] = temp;*/

				//swapEx(arr + i, arr + j);    // = swap(&a[i], &a[j]); // tot: double
				//swap(kor + i, kor + j);      // kor: int
				//swap(eng + i, eng + j);      // eng: int
				//swapEx1(nam + i, nam + j);
				//swapEx2(name + i, name + j);
				SWAP(arr + i, arr + j, 8);
				SWAP(student + i, student + j, 18);  //
				//SWAP(kor + i, kor + j, 4);
				//SWAP(eng + i, eng + j, 4);  
				//SWAP(name + i, name + j, 4);  // 위와 의미적으로 동일, name이 문자열의 배열 == 포인터(주소 값)
			}
		}
	}
}
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
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
void swapEx2(const char** a, const char** b)   // Data type 맞춰주는 것이 우선. // parameter: string*(4byte 변수), 주소가 전달된 것.
{											// 내용 바뀐 것 없음, 값이 바뀌려면 * 필요    // const char* a[], const char* b[]
	const char* c = *a;		// c* = a[]
	*a = *b;				// a[0] = b[0]
	*b = c;					// b[0] = c
}
void SWAP(void* a, void* b, int op)  // 포인터 받아주는 쪽에서 void 하면, 함수 호출시 void포인터에 넣을 필요 없음. 포인터만 던지면 됨.
{										//	op는 자료형의 크기
	if (op == 1)			//char
	{
		char c = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = c;
	}
	else if (op == 4)		//int, float,
	{
		int c = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = c;
	}
	else if (op == 8)			//double
	{
		double c = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = c;
	}
	else if (op == 18)			//double
	{
		STU c = *(STU*)a;
		*(STU*)a = *(STU*)b;
		*(STU*)b = c;
	}
}

#endif