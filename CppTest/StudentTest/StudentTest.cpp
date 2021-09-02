#if 1
#include <iostream>
#include "..\MyHeader.h"
using namespace std;

void ShowClass(Student &st1)
{
	cout << "st1.Number: " << st1.number() << "    ";
	cout << "st1.Name: " << st1.name() << "    ";
	cout << "st1.Age: " << st1.age() << "    ";
	cout << "st1.Kor: " << st1.kor() << "    ";
	cout << "st1.Eng: " << st1.eng() << "    ";
	cout << "st1.Tot: " << st1.tot() << "    ";
	cout << "st1.Avg: " << st1.avg() << endl;
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void swapRef(int& a, int& b) // 포인터 사용 X
{
	int c = a;    // int &c하게 되면, a의 다른 이름이 c, 아랫줄에서 b에 저장하는 건 a가 되어서 전부 20이 됨.
	a = b;
	b = c;
}

int main()
{
	string fname;		//	object
	fname = "C:\\Users\\snows\\student.csv";

	string nm = "감씨";			// nm = string("감씨"); 와 같음
	string strAdded = fname + nm;
	cout << strAdded << endl << endl;
	Student st(0, 80, 76, nm, 15);
	ShowClass(st);
	cout << endl << endl << endl << endl;

	//Student st1(1, 80, 75, "김씨", 15);	// Student(const Student&)
	//ShowClass(st1);

	int num, age, kor, eng;
	char name[100];
	int cnt = 0;
	Student* stu[100];			// 포인터 배열, 실 데이터 공간이 없다는 약점(주소만 존재) , 실데이터 저장공간은 그대로, 포인터만 교환하겠다

	FILE* fp = fopen(fname.c_str(), "r");		// const char*와 string 호환 X -> c_str로 변환(string object 사용법)
	fgets(name, 250, fp);		// 첫 줄 제거 -> file read pointer를 다음 줄로 이동시킴
	while (1)
	{
		if (fscanf(fp, "%d %s %d %d %d", &num, name, &age, &kor, &eng) < 1) break; // 읽어온 데이터가 0이면(읽을 게 없으면) break  // scanf 문장 구분을 화이트 스페이스로// , 안 됨
		stu[cnt++] = new Student(num, kor, eng, name, age);			// 포인터 배열에 객체 넣는 중
		ShowClass(*stu[cnt - 1]);
	}

	cout << "\n\n\n\n";
	
	for (int i = 0; i < cnt; i++)
	{
		for (int k = i; k < cnt; k++)
		{
			if (stu[i]->avg() < stu[k]->avg())		// stu[i]가 포인터 타입 -> 필요
			{
				swapRef((int&)stu[i], (int&)stu[k]);
				//swap((int*)&stu[i], (int*)&stu[k]);
			}
		}
	}

	for (int i = 0; i < cnt; i++)
	{
		ShowClass(*stu[i]);
	}
}
#endif


