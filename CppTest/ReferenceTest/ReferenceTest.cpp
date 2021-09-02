#include <iostream>
#include <stdio.h>
#include "..\MyHeader.h"  // "" -> 절대경로(C:\users\snows\source...\MyHeader.h) 필요함.
#include <math.h>
using namespace std;

int main()
{
	Point p1;  // p(0, 0)			구조체로 쓰려면 struct -> typedef -> 사용
	Point p2(10, 20);
	Point* pp3 = new Point(20, 30); // 동적 할당
	Point& p3 = *pp3;

	int i = MAX(10, 20);
	double d = MAX(1., 2.1);
	int j = ABS(-1); // 1
	double e = ABS(-2.2); // 2.2
	string s1 = "abcd", s2 = "----efgh";
	cout << Add(i, j) << endl;
	cout << Add(d, e) << endl;
	cout << Add<string>(s1, s2) << endl;			// "abcd", "----efgh"는 string type이 아니라 char* type이라 연산 안 됨. -> string s1으로 초기화 후 변수명으로 연산


	printf("Point class 변수의 동적 할당: p3(%d, %d)\n\n", pp3->GetX(), pp3->GetY());				// 포인터변수 사용 시 ->
	printf("Point class 변수의 동적 할당: p3(%d, %d)\n\n", p3.GetX(), p3.GetY());
	printf("두 점 p1(%d, %d)과 p2(%d, %d)의 거리는 %f 입니다\n", p1.GetX(), p1.GetY(), p2.GetX(), p2.GetY(), p1.distance(p2));   // p1 클래스 변수의 distance 호출, p1,p2는 실 변수라 '.'
	Point p4 = p2 + p3;	// a = b + c;		c = (a += b) + d
	Point p5 = p2 * 3;

	printf("두 점 p2(% d, % d)과 p3(%d,%d)의 합은 p4(%d, %d) 입니다\n", p2.GetX(), p2.GetY(), (*pp3).GetX(), pp3->GetY(), p4.GetX(), p4.GetY()); // (*pp3).  <- 포인터가 가리키는 값(실 변수)
	printf("두 점 p2(% d, % d)과 p3(%d,%d)의 합은 p4(%d, %d) 입니다\n", p2.GetX(), p2.GetY(), pp3->GetX(), pp3->GetY(), p4.GetX(), p4.GetY());




	Point3D pp1;
	Point3D pp2(10, 20, 30);
	Point3D* ppp3 = new Point3D(40, 50, 60);
	printf("Point3D class 변수의 동적 할당: p3(%d, %d, %d)\n\n", ppp3->GetX(), ppp3->GetY(), ppp3->GetZ());
	printf("두 점 pp3(%d, %d, %d)과 pp2(%d, %d, %d)의 거리는 %f 입니다\n", ppp3->GetX(), ppp3->GetY(), ppp3->GetZ(),
		pp2.GetX(), pp2.GetY(), pp2.GetZ(), pp3->distance(pp2));   // pp2.distance(*pp3))

}
