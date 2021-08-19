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
	printf("   KOSTA �л��� ����, ����, ���� ���� ��Ȳ\n================================================\n\n\n");
	for (i = 0; i < students; i++)
	{
		kor[i] = ((rand() % 1000) + 1) / 10.0;  // rand: ���� �߻��� (����) 0 ~ 100.0   %1000�ϸ� 0~999, 1 �����ְ� /10
		eng[i] = ((rand() % 1000) + 1) / 10.0;												// 0.1 ~ 100
		mat[i] = ((rand() % 1000) + 1) / 10.0;
		kortotal += kor[i];
		engtotal += eng[i];
		mattotal += mat[i];
		printf("%2d��° �л� ��������: %4.1lf  ��������: %4.1lf  ��������: %4.1lf  ", i + 1, kor[i], eng[i], mat[i]);
		printf("����: %5.1lf  ���: %4.1lf\n", kor[i] + eng[i] + mat[i], (kor[i] + eng[i] + mat[i]) / 3);
	}
	koravg = kortotal / students;
	engavg = engtotal / students;
	matavg = mattotal / students;
	tot = kortotal + engtotal + mattotal;
	avg = tot / (students * 3);
	printf("���� ����: %6.1lf, ���: %4.1lf\n", kortotal, koravg);
	printf("���� ����: %6.1lf, ���: %4.1lf\n", engtotal, engavg);
	printf("���� ����: %6.1lf, ���: %4.1lf\n", mattotal, matavg);
	printf("��ü ����: %6.1lf, ��ü ���: %4.1lf\n", tot, avg);

	return 0;
}
int Good()
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
// ���ڿ� str�� �޾Ƽ� �ش� ���ڿ��� ���̸� �ǵ��� ��.
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

int solution1()
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
	return 0;
}
// function define 
//     Prototype  :  void swap(int a, int b)
// ���� ���� a�� b�� ���� ��ȯ.
void swap(int* a, int* b)	// a,b�� �����ͷ� �����ϰ� ���޵� �Ű����� ������ ���� (�ʱ�ȭ)
{							// ������ ����� : �����Ͱ� ����Ű�� �ּ��� �� : *p
							//					 �ּ� ��ü : p
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
// �������� : ������ �Լ����� ��� ����
const int nArr = 10;
int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
char nam[] = "ABCDEFGHIJK";//���ڿ� �����ͷ� ���� : "ȫ�浿" "ȫ����" "ȫ���" "ȫ���" "ȫ���" "����" ��ĥ ���� �汸 
const char* name[] = { "ȫ�浿", "ȫ����", "ȫ���", "ȫ���", "ȫ���", "����", "����", "�ͻ�", "�ͻ�", "�Ϳ�" };
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
			if ((a + i)->avg < (a + j)->avg)	// ����ü �������� ��  ===> a[i].avg < a[j].avg
			{
				SWAP(a + i, a + j, sizeof(STU));
			}
		}
	}
}

void sortTest()	//  �迭�� �̿��� ����ó��
{
	double f_kor = 0.3, f_eng = 0.7;
	double tot[nArr];
	int i, j, k;

	for (i = 0; i < nArr; i++)
	{
		tot[i] = kor[i] * f_kor + eng[i] * f_eng;
	}
	printf("Original :\n");
	printf("�̸� : "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("���� : "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("���� : "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("�հ� : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");
	printf("�̸� : "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("���� : "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("���� : "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("�հ� : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
}

void sortTestNew()		// ����ü�� �̿��� ����ó��
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
	printf("�̸� : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("���� : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("���� : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("�հ� : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");
	printf("�̸� : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("���� : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("���� : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("�հ� : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
}

void sortTestEx()		// ����ü�� �̿��� ����ó�� - ���� �����
{
	double f_kor = 0.3, f_eng = 0.7;
	double tot[nArr];
	int i, j, k;

	int m, n;
	char buf[1024];
	FILE* fin = fopen("C:\\Users\\snows\\table3.txt", "r");  // "r": read()  // table2�� data ������ �� �ְ�	
	FILE* fout = fopen("C:\\Users\\snows\\table4.txt", "w+b");  // table4�̶�� ���� �����ؼ� ������ �� �ֵ���

	for (i = 0; i < nArr; i++) fscanf(fin, "%s", student[i].name);
	for (i = 0; i < nArr; i++) fscanf(fin, "%d", &student[i].kor);
	for (i = 0; i < nArr; i++) fscanf(fin, "%d", &student[i].eng);
	for (i = 0; i < nArr; i++)
	{
		student[i].tot = student[i].kor + student[i].eng;
		student[i].avg = student[i].tot / 2;
	}
	printf("Original :\n");
	printf("�̸�: "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("����: "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("�հ�: "); for (int i = 0; i < nArr; i++) printf("%7.2lf ", student[i].tot); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n");

	printf("�̸�	����	����	�հ�	\n");
	fprintf(fout, "�̸�	����	����	�հ�	\n");  // table4�� ���� ����
	for (int i = 0; i < nArr; i++)
	{
		printf("%7s%7d%7d%7.2lf\n", student[i].name, student[i].kor, student[i].eng, student[i].tot);
		fprintf(fout, "%7s%7d%7d%7.2lf\n", student[i].name, student[i].kor, student[i].eng, student[i].tot);   // table4�� ���� ����
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
	FILE* f = fopen("C:\\Users\\snows\\aa", "r");  // "r": read()  // ���� �����̸� NULL ��ȯ
	FILE* fout0 = fopen("C:\\Users\\snows\\aa.o0", "w");  // "w": write,  fout0�� file pointer, write�� �� ����� ����ġ�� !=append
	FILE* fout1 = fopen("C:\\Users\\snows\\aa.o1", "a");  // 
	FILE* fout2 = fopen("C:\\Users\\snows\\aa.o2", "a+b");  // append: �� ����� ���� ��� �ؿ� ������
	if (f != NULL)
	{
		while (1)										// "w": write()
		{
			if (fgets(buf, 1024, f) == NULL) break;		// ���� �Է� �Լ�  , �� �� ������ �о��
			//if (strlen(buf) < 3) break;  // ���͵� 0 �ƴ�. Ctrl+C�� Ż��
			//fputs("==== �Է¹��ڿ� =====>", stdout);
			fputs(buf, stdout); // ȭ�� ���
			fputs(buf, fout0);
			fputs(buf, fout1);
			fputs(buf, fout2);
		}
	}
	else printf("�Է� ������ �������� �ʽ��ϴ�.\n");
}


int main()
{
	int pick = 0, stop = 1;

	while (stop)
	{
		printf("\n\n***** ���α׷� ��� *****\n\n");
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