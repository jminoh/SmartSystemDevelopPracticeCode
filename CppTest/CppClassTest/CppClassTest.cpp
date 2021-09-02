#if 0
#include <iostream>
#include <stdio.h>

class Person
{
private:
	char name[10];
	int age;

public:
	Person(char name[10] = 0, int age = 0)
	{
		strcpy(this->name, name);
		this->age = age;
	}
	int GetName() { return name[10]; }
	int GetAge() { return age; }
	void SetName(char* name) { *this->name = *name; }
	void SetAge(int age) { this->age = age; }
};

class Student : public Person
{
private:
	int kor;
	int eng;

	
public:
	Student(char name[10] = 0, int age = 0, int kor = 0, int eng = 0): Person(name, age)
	{
		this->kor = kor;
		this->eng = eng;
	}
	double tot;
	double avg;
	int GetKor() { return kor; }
	int GetEng() { return eng; }
	void SetKor(int kor) { this->kor= kor; }
	void SetEng(int eng) { this->eng = eng; }
	
};

const int nArr = 10;

int main(void)
{
	double f_kor = 0.3, f_eng = 0.7;
	int i, j, k;
	//****************************************************************************
	//****************************************************************************
	//****************************************************************************
	int num;  //file에서 read
	Student student = new Student[nArr];        
	//****************************************************************************
	//****************************************************************************
	//****************************************************************************

	FILE* fin = fopen("C:\\Users\\snows\\table1.txt", "r");  // "r": read()  // table2의 data 가져올 수 있게	
	FILE* fout = fopen("C:\\Users\\snows\\table2.txt", "w+b");  // table2이라는 파일 생성해서 저장할 수 있도록
	fscanf(fin, "%d", &num);		// file에서 num 받아옴


	for (i = 0; i < num; i++) fscanf(fin, "%s", students[i].name);  // 배열처럼 . 연산, 포인터로 하려면 화살표
	for (i = 0; i < num; i++) fscanf(fin, "%d", &students[i].kor);
	for (i = 0; i < num; i++) fscanf(fin, "%d", &students[i].eng);
	for (i = 0; i < num; i++)
	{
		students[i].tot = students[i].kor + students[i].eng;
		students[i].avg = students[i].tot / 2;
	}

	printf("Original :\n");
	printf("%-7s %-7s %-7s %-7s %-7s\n\n", "이름", "국어", "영어", "총점", "평균");
	for (int i = 0; i < num; i++)
	{
		printf("%7s %7d %7d %7.2f %7.2f\n", students[i].name, students[i].kor, students[i].eng,
			students[i].tot, students[i].avg);
	}

	sortSTU(students, num);

	printf("Sorted :\n");
	printf("%-7s %-7s %-7s %-7s %-7s\n\n", "이름", "국어", "영어", "총점", "평균");
	fprintf(fout, "%-7s %-7s %-7s %-7s %-7s\n\n", "이름", "국어", "영어", "총점", "평균");
	for (int i = 0; i < num; i++)
	{
		printf("%7s %7d %7d %7.2f %7.2f\n", (students + i)->name, (students + i)->kor, (students + i)->eng,
			(students + i)->tot, (students + i)->avg);    // 포인터로 멤버 변수 접근 시, 화살표 사용
		fprintf(fout, "%7s %7d %7d %7.2f %7.2f\n", (students + i)->name, (students + i)->kor, (students + i)->eng,
			(students + i)->tot, (students + i)->avg);    // fout -> stdout: printf와 같은 효과
	}
	fclose(fout);
	fclose(fin);

	return 0;
}
void sortSTU(STU* a, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if ((a + i)->avg < (a + j)->avg)  // 구조체 포인터의 값 =>a[i].avg < a[j].avg, a+i: i번째 구조체, ->avg:의 avg 멤버
			{
				SWAP(a + i, a + j, sizeof(STU));  // 구조체의 size => sizeof(구조체), 포인터 두 개 받아서 교환
			}
		}
	}
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

				SWAP(arr + i, arr + j, 8);
				SWAP(student + i, student + j, 18);

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
	else if (op == sizeof(STU))			//double
	{
		STU c = *(STU*)a;
		*(STU*)a = *(STU*)b;
		*(STU*)b = c;
	}

}
#endif