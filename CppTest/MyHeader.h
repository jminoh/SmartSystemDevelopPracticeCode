#include <iostream>
using namespace std;
void swapValue(int a, int b); // �Լ��� ����(proto type) ����
void swapRef(int& a, int& b);
void swapRef(int* a, int* b);
#define MAX(X,Y) (X>Y)?X:Y		//	��ũ�� �Լ�
#define MIN(X,Y) (X<Y)?X:Y
#define ABS(X) ((X)<0)?((-1) * X):(X)

template <typename A>
A Add(A n1, A n2)
{
	return n1 + n2;
}

class Point
{
private:

	int x;  // �⺻ �������� �����ڴ� private			// ��������
	int y;
public:

	Point(int x = 0, int y = 0) : x(x)		// Point(int x = 0, int y = 0) : x(x), y(y) {}  // ���� ���� ������ �̴ϼȶ������� ��
	{
		this->y = y;
	}
	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }

	double distance(Point p); // Point p ���� �Ÿ��� ����ؼ� �ǵ����ִ� �Լ�
	Point operator+(Point p)			// 
	{
		int x = this->x + p.x;
		int y = this->y + p.y;
		return *this;
	}
	Point operator*(int n)
	{
		return Point(this->x * n, this->y * n);
	}
};

class Point3D : public Point					// 3����, 2D Point class ���
{
private:
	int z;  // z��
public:
	Point3D(int x = 0, int  y = 0, int z = 0) : Point(x, y), z(z)  // z(z)��� �߰�ȣ �ȿ� this-> = z;�� ����
	{

	}
	int GetZ() { return z; }
	void SetZ(int z) { this->z = z; }
	double distance(Point3D p); // Point3D p ���� �Ÿ�

};

class Person
{
private:
	int Number;		// ������ȣ
	char Name[20];		// ���ڿ�, �ѱ� 10���ڱ���
	int Age;

public:			// new�� ���� ������ �⺻ �Ҹ��ڷ� �Ҹ�			// age�� �Ķ���ͷ� �޴� �����ڵ� ����( �Ű����� ���̳� 0 ���)
	Person(int num, char* str = NULL, int a = 0) : Number(num), Age(a)		// str�� �����������(���ڿ� ����� ���� ������� �� �ִٸ�) Name(str) ����, ����� �� ���� ������ ����
	{															// ���� ���۷� �������� �ӽ� ������ ����ϴµ�, �̴� stack�����̶� overwrite�� ���̱� ������ ����
		strcpy(Name, str);
	}

	Person(int num, const char* str = NULL, int a = 0) : Number(num), Age(a)	
	{														
		strcpy(Name, str);
	}

	int age() { return Age; }
	char* name() { return Name; }
	int number() { return Number; }
	void SetAge(int a) { Age = a; }
	void SetName(char* str)		// ���� �� ����(delete) �� ���� ����. 	
	{
		strcpy(Name, str);
	}
};

class PersonEx				// �������� ����
{
private:
	int Number;
	char* Name;	// ���ڿ� ���� �׸��� malloc�̳� new�� �̿��� �������� �Ҵ� 
	int Age;

public:			
	PersonEx(int num, char* str, int a) : Number(num), Age(a)		// str�� �����������(���ڿ� ����� ���� ������� �� �ִٸ�) Name(str) ����, ����� �� ���� ������ ����
	{															// ���� ���۷� �������� �ӽ� ������ ����ϴµ�, �̴� stack�����̶� overwrite�� ���̱� ������ ����
		Name = new char[strlen(str)];				// new�� ���� �Ҵ��ϱ� ������ �迭���̸� ���� Ÿ������ ���� ����  / ���� �����ʹ� new�� Ȯ���� ������ ��
		strcpy(Name, str);
	}
	~PersonEx()
	{
		delete[]Name;
	}
	int age() { return Age; }
	char* name() { return Name; }
	void SetAge(int a) { Age = a; }
	void SetName(char* str)		// ���� �� ����(delete) �� ���� ����. (���ڿ� �����Ҵ��̴ٺ���, ���Ҵ� �ʿ�)	
	{ 
		delete[]Name;						// ���Ҵ� ���� delete
		Name = new char[strlen(str)];		// �޸� ���Ҵ�
		strcpy(Name, str);
	}
};

class Student : public Person
{
private:
	int Kor;
	int Eng;
	int Tot;
	double Avg;
	int Rank;
	void calc() //�ܺο��� ȣ������ �ʵ���		// ���� data�� ���Ἲ ����
	{
		Tot = Kor + Eng;
		Avg = Tot / 2.0;
	}
public:
	Student(int num, int kor, int eng, char *str = NULL, int age = 0) :Person(num, str, age)		// Person�� �������� �� �ִ� ��-> Number			// �����ڿ��� �ʱ�ȭ, ���� ����
	{
		this->Kor = kor;		// �����̸��� ���� �ʱ� ������ this-> �� �ᵵ ��
		this->Eng = eng;
		calc();
	}
	Student(int num, int kor, int eng, const char* str = NULL, int age = 0) :Person(num, str, age)	// char*, const char* �Ѵ� ���ڿ� ó�� ���� ���� type
	{
		this->Kor = kor;	
		this->Eng = eng;
		calc();
	}
	Student(int num, int kor, int eng, string str, int age = 0) :Person(num, str.c_str(), age)	
	{
		this->Kor = kor;		
		this->Eng = eng;
		calc();
	}
	int kor() { return Kor; }
	int eng() { return Eng; }
	int tot() { return Tot; }
	double avg() { return Avg; }
	int rank() { return Rank; }
	void SetKor(int k) { Kor = k; calc(); }			// Tot�� Avg�� Kor�� Eng ������������ �ڵ����� �����ǰ� �ؾ� ����
	void SetEng(int e) { Eng = e; calc(); }
	void SetRank(int r) { Rank = r; }
};