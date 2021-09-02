#include "..\MyHeader.h"
#include <iostream>
//int main()
//{
//	cout << "Hello C plus plus World!\n\n";
//	int a, b;
//	int* pa, * pb;
//	a = 10;
//	b = 20;
//	//pa = &a, pb = &b;
//
//
//	cout << "초기값 a = " << a << ", b = " << b << endl;
//
//	swapValue(a, b);
//	cout << "결과값(swapValue) a = " << a << ", b = " << b << endl;
//
//	swapRef(a, b);
//	printf("결과값(swapRef:ref) a = %d, b = %d\n\n", a, b);
//
//	swapRef(&a, &b);
//	printf("결과값(swapRef:포인터) a = %d, b = %d\n\n", a, b);
//}
void swapValue(int a, int b)
{
	int c = a;
	a = b;
	b = c;
}

void swapRef(int& a, int& b) // 포인터 사용 X
{
	int c = a;    // int &c하게 되면, a의 다른 이름이 c, 아랫줄에서 b에 저장하는 건 a가 되어서 전부 20이 됨.
	a = b;
	b = c;
}

void swapRef(int* pa, int* pb)  // 포인터 사용, 오버로딩, 인자로 주소 받아옴
{
	int temp = *pa;  // *pa == pa[0]
	*pa = *pb;
	*pb = temp;
}
double Point::distance(Point p) // Point p 와의 거리를 계산해서 되돌려주는 함수
{
	int x2 = (x - p.x) * (x - p.x);
	int y2 = (y - p.y) * (y - p.y);
	return sqrt(x2 + y2);
}

double Point3D::distance(Point3D p) // Point3D p 와의 거리
{
	int x2 = (GetX() - p.GetX()) * (GetX() - p.GetX());
	int y2 = (GetY() - p.GetY()) * (GetY() - p.GetY());
	int z2 = (GetZ() - p.GetZ()) * (GetZ() - p.GetZ());			// z는 private이지만, Local변수라서 사용 가능
	return sqrt(x2 + y2 + z2);
}