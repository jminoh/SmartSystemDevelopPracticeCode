#include <iostream>
using namespace std;
void swapValue(int a, int b); // 함수의 원형(proto type) 선언
void swapRef(int& a, int& b);
void swapRef(int* a, int* b);
#define MAX(X,Y) (X>Y)?X:Y		//	매크로 함수
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

	int x;  // 기본 접근제어 지시자는 private			// 정보은닉
	int y;
public:

	Point(int x = 0, int y = 0) : x(x)		// Point(int x = 0, int y = 0) : x(x), y(y) {}  // 위와 같은 내용을 이니셜라이저로 씀
	{
		this->y = y;
	}
	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }

	double distance(Point p); // Point p 와의 거리를 계산해서 되돌려주는 함수
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

class Point3D : public Point					// 3차원, 2D Point class 상속
{
private:
	int z;  // z축
public:
	Point3D(int x = 0, int  y = 0, int z = 0) : Point(x, y), z(z)  // z(z)대신 중괄호 안에 this-> = z;도 가능
	{

	}
	int GetZ() { return z; }
	void SetZ(int z) { this->z = z; }
	double distance(Point3D p); // Point3D p 와의 거리

};

class Person
{
private:
	int Number;		// 고유번호
	char Name[20];		// 문자열, 한글 10글자까지
	int Age;

public:			// new가 없기 때문에 기본 소멸자로 소멸			// age만 파라미터로 받는 생성자도 가능( 매개변수 널이나 0 대신)
	Person(int num, char* str = NULL, int a = 0) : Number(num), Age(a)		// str가 전역변수라면(문자열 상수라서 오래 살아있을 수 있다면) Name(str) 가능, 장담할 수 없기 때문에 위함
	{															// 파일 버퍼로 가져오며 임시 변수를 사용하는데, 이는 stack영역이라서 overwrite될 것이기 때문에 위험
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
	void SetName(char* str)		// 기존 방 비우고(delete) 새 방을 잡자. 	
	{
		strcpy(Name, str);
	}
};

class PersonEx				// 수정사항 존재
{
private:
	int Number;
	char* Name;	// 문자열 담을 그릇은 malloc이나 new를 이용해 동적으로 할당 
	int Age;

public:			
	PersonEx(int num, char* str, int a) : Number(num), Age(a)		// str가 전역변수라면(문자열 상수라서 오래 살아있을 수 있다면) Name(str) 가능, 장담할 수 없기 때문에 위함
	{															// 파일 버퍼로 가져오며 임시 변수를 사용하는데, 이는 stack영역이라서 overwrite될 것이기 때문에 위험
		Name = new char[strlen(str)];				// new로 동적 할당하기 때문에 배열길이를 변수 타입으로 선언 가능  / 실제 데이터는 new로 확보된 공간에 들어감
		strcpy(Name, str);
	}
	~PersonEx()
	{
		delete[]Name;
	}
	int age() { return Age; }
	char* name() { return Name; }
	void SetAge(int a) { Age = a; }
	void SetName(char* str)		// 기존 방 비우고(delete) 새 방을 잡자. (문자열 동적할당이다보니, 재할당 필요)	
	{ 
		delete[]Name;						// 재할당 위한 delete
		Name = new char[strlen(str)];		// 메모리 재할당
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
	void calc() //외부에서 호출하지 않도록		// 연결 data의 무결성 보장
	{
		Tot = Kor + Eng;
		Avg = Tot / 2.0;
	}
public:
	Student(int num, int kor, int eng, char *str = NULL, int age = 0) :Person(num, str, age)		// Person과 연결지을 수 있는 것-> Number			// 생성자에서 초기화, 연산 가능
	{
		this->Kor = kor;		// 변수이름이 같지 않기 때문에 this-> 안 써도 됨
		this->Eng = eng;
		calc();
	}
	Student(int num, int kor, int eng, const char* str = NULL, int age = 0) :Person(num, str, age)	// char*, const char* 둘다 문자열 처리 위한 변수 type
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
	void SetKor(int k) { Kor = k; calc(); }			// Tot와 Avg는 Kor와 Eng 수정과정에서 자동으로 수정되게 해야 맞음
	void SetEng(int e) { Eng = e; calc(); }
	void SetRank(int r) { Rank = r; }
};