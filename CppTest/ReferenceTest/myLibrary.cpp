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
//	cout << "�ʱⰪ a = " << a << ", b = " << b << endl;
//
//	swapValue(a, b);
//	cout << "�����(swapValue) a = " << a << ", b = " << b << endl;
//
//	swapRef(a, b);
//	printf("�����(swapRef:ref) a = %d, b = %d\n\n", a, b);
//
//	swapRef(&a, &b);
//	printf("�����(swapRef:������) a = %d, b = %d\n\n", a, b);
//}
void swapValue(int a, int b)
{
	int c = a;
	a = b;
	b = c;
}

void swapRef(int& a, int& b) // ������ ��� X
{
	int c = a;    // int &c�ϰ� �Ǹ�, a�� �ٸ� �̸��� c, �Ʒ��ٿ��� b�� �����ϴ� �� a�� �Ǿ ���� 20�� ��.
	a = b;
	b = c;
}

void swapRef(int* pa, int* pb)  // ������ ���, �����ε�, ���ڷ� �ּ� �޾ƿ�
{
	int temp = *pa;  // *pa == pa[0]
	*pa = *pb;
	*pb = temp;
}
double Point::distance(Point p) // Point p ���� �Ÿ��� ����ؼ� �ǵ����ִ� �Լ�
{
	int x2 = (x - p.x) * (x - p.x);
	int y2 = (y - p.y) * (y - p.y);
	return sqrt(x2 + y2);
}

double Point3D::distance(Point3D p) // Point3D p ���� �Ÿ�
{
	int x2 = (GetX() - p.GetX()) * (GetX() - p.GetX());
	int y2 = (GetY() - p.GetY()) * (GetY() - p.GetY());
	int z2 = (GetZ() - p.GetZ()) * (GetZ() - p.GetZ());			// z�� private������, Local������ ��� ����
	return sqrt(x2 + y2 + z2);
}