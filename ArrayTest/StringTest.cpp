#if 0
#include <stdio.h>

int main(void)
{
	char good[5] = "Good"; 
	char mon[] = "morning"; // [8]
	char noon[] = "afternoon"; // [10]
	char even[] = "evening"; // [8]
	int t;
	

	printf("���� �ð���? 24�ð� �������� �Է��� �ּ���.");
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
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
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
// �ǽ� 1
#include <stdio.h>
// function define
// Prototype: int str_len(char *str)	���ڿ�(���� �迭, ������)�� �Ķ���ͷ� ���� �� * ���
// ���ڿ� str�� �޾Ƽ� �ش� ���ڿ��� ���̸� �ǵ��� ��.
int str_len(char* str);
int main(void)		
{
	char s[80];				// �迭���� ������
	int i, funcres;
	printf("���ڿ��� �Է��Ͻÿ�.");
	scanf("%s", s);

	funcres = str_len(s);
	printf("�Է¹��ڿ� [%s]�� ���̴� %d �Դϴ� \n", s, funcres);

	for (i = 0; i < funcres; i++)     // �񱳹� ���� �Լ� ������ ���� �� ����
	{									// loop�� ������ �Լ� ���, �ӵ� ������
		if (s[i] != 0)
			printf("%c ", s[i]);
		else
			break;
	}
}
int str_len(char* str)  // parameter�� �迭�� �ƴ� �����ͷ� ����, [] == *, str[]�� ����
{						// ����: �������� '\0'�� �پ��ִ�.
	int i, res = 0;
	// while (*(str + res++)); return res; // �Ʒ� �Լ� �� �ٷ�. �ƹ��͵� �� �ϰ� ������ ����
	while (1)
	{
		if (str[res] != 0) res++;   // '0' -> ���ڿ��� �������� �����ϴ� NULL
		else break;
	}
	return res;
}
	
#endif

#if 0
// �ǽ� 2
// �Է��� ���ڿ� �ش��ϴ� �ε����� ������ �ִ� �� ��ȯ
#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(void)
{
	char s[11], click;
	printf("10�� ���� ���ڿ��� �Է��Ͻÿ�.\n");
	scanf("%s", s);

	printf("0~9�� ���� �� �ϳ��� �Է��Ͻÿ�.\n");
	while (1)							// �ε����� �ش��ϴ� ���� �ٷιٷ� ����� ��� ��.
	{
		click = getch() - 48;             // 0~9 ���� Ű (�ƽ�Ű �ڵ�)�Է�
		if (click >= 0 && click <= 9)
		{
			printf("%c", s[click]);       // click - 48 = �ƽ�Ű �ڵ尪���� ����
			continue;
		}
		else                                   // click ��ȯ���� char�̱� ����
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
// �پ��� ������ �迭 ��� ���� ���
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
//4�� ������ �ǽ�
//�� ������ ������ ������ ���� �� �迭�� �̿��Ͽ� �ʱ�ȭ�ϰ�,
//������ ������ ����ġ�� ���� �� ���κ� �հ踦 ���Ͽ� ���� ū �������
//�����Ͽ� ����϶�.
//- �ڷ�(��)
//�̸� A   B   C   D   E   F   G
//���� 82  93  71  69  78  84  75 - ����ġ 0.3
//���� 76  91  67  73  86  63  83 - ����ġ 0.7
#include <stdio.h>
const int students = 10;
void swapTest(double sorting[][students]);  // ����, ���� ���� �迭������!!!
int main(void)
{
	int kor[] = { 82, 93, 71, 69, 78, 84, 75, 45, 100, 66 };
	int eng[] = { 76, 91, 67, 73, 86, 63, 83, 95, 62, 81 }; // �迭 ����: sizeof(�迭��)/sizeof(�迭���)
	double sort[2][students];
	int i, j;

	for (i = 0; i < students; i++)
	{
		sort[0][i] = (kor[i] * 0.3) + (eng[i] * 0.7);
		sort[1][i] = i + 65;    // �ƽ�Ű�ڵ� A
	}

	swapTest(sort);      // ȣ�� ���� ������ �迭��!!!

	// �� �Ǵ� ��.
	//for (j = 0; j < students; j++)
	//{
	//	sort[1][i] = (int)sort[1][i];		// �迭�� double, (int)����ȯ ���� �ٽ� double�� �־��ָ� 
	//	printf("%d\n", sort[1][i]);			// �Ҽ����� ���ְ� double�� �ٽ� ���� ��. �� ��.
	//}

	printf("����:  �̸�  ����  ����  �հ�\n");
	for (i = 0; i < students; i++)
	{
		printf("%4d:%5c%7d%7d%7.2lf\n", i+1, (int)sort[1][i], kor[(int)sort[1][i] - 65], eng[(int)sort[1][i] - 65], sort[0][i]);
	}										// �ٸ� �迭�̱� ������ ���������� ǥ���� ���� ������, �̸��� ���ʿ� ���ĵǾ��� ������ �̸��� �̿�
}							// �̸� ǥ�� ���� �پ��ִ� �ƽ�Ű�ڵ� ���. int�� �ٲٰ� -65 �ϸ� ������ �ε��� ����. �ش� �ε����� kor�迭�� ���.

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
// 4�� ������ �ǽ� �����
#include <stdio.h>
void sortEx(double* arr, int n); 
void swap(int* a, int* b);
void swapEx(double* a, double* b);
void swapEx1(char* a, char* b);
void swapEx2(const char** a, const char** b);
void SWAP(void* a, void* b, int op);

int kor[] = {67, 70, 77, 65, 68, 72, 79, 55, 85, 61};  //  ���� ����ȭ: ������ �Լ����� ��� ����
int eng[] = {70, 75, 80, 60, 65, 55, 80, 95, 67, 84};
const int nArr = 10;
char nam[] = "ABCDEFGHIJK";
const char* name[] = { "�达", "�̾�", "�ھ�", "�־�", "�Ⱦ�", "����", "�Ҿ�", "����", "�㾾", "�ɾ�" };  // ������ �迭, String Array

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
	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7c ", nam[i]); printf("\n\n");
	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("�հ�: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");
	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7c ", nam[i]); printf("\n\n");
	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("�հ�: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");
	return 0;
}
void sortEx(double* arr, int nArr) 
{							
	int i, j, temp;
	for (i = 0; i < nArr; i++)
	{
		for (j = i; j < nArr; j++) 
		{
			if (arr[i] < arr[j])                              // swap �Լ� ����ص� ��.
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
void swapEx2(const char** a, const char** b)   // Data type �����ִ� ���� �켱. // parameter: string*(4byte ����), �ּҰ� ���޵� ��.
{											// ���� �ٲ� �� ����, ���� �ٲ���� * �ʿ�    // const char* a[], const char* b[]
	const char *c = *a;		// c* = a[]
	*a = *b;				// a[0] = b[0]
	*b = c;					// b[0] = c
}
void SWAP(void* a, void* b, int op)  // ������ �޾��ִ� �ʿ��� void �ϸ�, �Լ� ȣ��� void�����Ϳ� ���� �ʿ� ����. �����͸� ������ ��.
{										//	op�� �ڷ����� ũ��
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
// Sort, ���� �ݺ����� ����. ���� normal�� ���Ĺ��
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

void sort(int *arr, int nArr)  // a[i]�������� �� ���� �͵� ��
{								// a[i] ���� �͵��� �̹� ū �ͺ��� ���ĵ�.
	int i, j, temp;
	for (i = 0; i < nArr; i++)
	{
		for (j = i; j < nArr; j++) // j = i;���� ��
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
//void �����ͷ� swap�Լ� ������
#include <stdio.h>
void SWAP(void *p1, void *p2, int op);   // op�� �ڷ��� ũ��
int main(void)
{

	int n[] = { 1,2,3,4,5 };
	SWAP(n+1, n+2, 4);

	for (int i = 0; i < sizeof(n) / sizeof(n[0]); i++)
		printf("%d  ", n[i]);
}

void SWAP(void* a, void* b, int op)  // ������ �޾��ִ� �ʿ��� void �ϸ�, �Լ� ȣ��� void�����Ϳ� ���� �ʿ� ����. �����͸� ������ ��.
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
// 6�� ������ ����ó�� ���α׷� ����ü�� �籸���ϱ�


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


int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };  //  ���� ����ȭ: ������ �Լ����� ��� ����
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
const int nArr = 10;
char nam[] = "ABCDEFGHIJK";
const char* name[] = { "�达", "�̾�", "�ھ�", "�־�", "�Ⱦ�", "����", "�Ҿ�", "����", "�㾾", "�ɾ�" };  // ������ �迭, String Array


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
//	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7c ", nam[i]); printf("\n\n");
//	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
//	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
//	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
//	printf("�հ�: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");
//
//	sortEx(tot, nArr);
//
//	printf("Sorted :\n");
//	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7c ", nam[i]); printf("\n\n");
//	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
//	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
//	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
//	printf("�հ�: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");
//	return 0;
//}
//void sortEx(double* arr, int nArr)
//{
//	int i, j, temp;
//	for (i = 0; i < nArr; i++)
//	{
//		for (j = i; j < nArr; j++)
//		{
//			if (arr[i] < arr[j])                              // swap �Լ� ����ص� ��.
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
void swapEx2(const char** a, const char** b)   // Data type �����ִ� ���� �켱. // parameter: string*(4byte ����), �ּҰ� ���޵� ��.
{											// ���� �ٲ� �� ����, ���� �ٲ���� * �ʿ�    // const char* a[], const char* b[]
	const char* c = *a;		// c* = a[]
	*a = *b;				// a[0] = b[0]
	*b = c;					// b[0] = c
}
void SWAP(void* a, void* b, int op)  // ������ �޾��ִ� �ʿ��� void �ϸ�, �Լ� ȣ��� void�����Ϳ� ���� �ʿ� ����. �����͸� ������ ��.
{										//	op�� �ڷ����� ũ��
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
// 6�� ����ü �ǽ� �����
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

int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };  //  ���� ����ȭ: ������ �Լ����� ��� ����
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
const int nArr = 10;
char nam[] = "ABCDEFGHIJK";
const char* name[] = { "�达", "�̾�", "�ھ�", "�־�", "�Ⱦ�", "����", "�Ҿ�", "����", "�㾾", "�ɾ�" };  // ������ �迭, String Array
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
		//tot[i] = (student[i].kor = kor[i]) * f_kor + (student[i].eng = eng[i]) * f_eng; // �� �� �ּ� �� �ٷ� ��ħ.
	}											// ������ ����ü�� ��������� �����ϰ�, ����ġ ����. ����ġ ������ �� ������ ���� tot�� ����.
	printf("Original :\n");
	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("�հ�: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");
	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("�հ�: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", tot[i]); printf("\n\n");
	return 0;
}
void sortEx(double* arr, int nArr)
{
	int i, j, temp;
	for (i = 0; i < nArr; i++)
	{
		for (j = i; j < nArr; j++)
		{
			if (arr[i] < arr[j])                              // swap �Լ� ����ص� ��.
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
				//SWAP(name + i, name + j, 4);  // ���� �ǹ������� ����, name�� ���ڿ��� �迭 == ������(�ּ� ��)
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
void swapEx2(const char** a, const char** b)   // Data type �����ִ� ���� �켱. // parameter: string*(4byte ����), �ּҰ� ���޵� ��.
{											// ���� �ٲ� �� ����, ���� �ٲ���� * �ʿ�    // const char* a[], const char* b[]
	const char* c = *a;		// c* = a[]
	*a = *b;				// a[0] = b[0]
	*b = c;					// b[0] = c
}
void SWAP(void* a, void* b, int op)  // ������ �޾��ִ� �ʿ��� void �ϸ�, �Լ� ȣ��� void�����Ϳ� ���� �ʿ� ����. �����͸� ������ ��.
{										//	op�� �ڷ����� ũ��
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