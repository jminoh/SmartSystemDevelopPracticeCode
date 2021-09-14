#if 0
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	int age;
	char name[50];
public:
	Person(int myage, const char* myname) : age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old" << endl;
	}
};

class UnivStudent : public Person // Person class 상속을 의미
{
private:
	char major[50];
public:
	UnivStudent(const char* myname, int myage, const char* mymajor) : Person(myage, myname)
	{
		strcpy(major, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electeng.");
	ustd2.WhoAreYou();
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30)
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n)
	{
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
	{
		cout << "soDerived(int n1, int n2)" << endl;
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};
int main(void)
{
	cout << "case1..... " << endl;
	SoDerived dr1;
	dr1.ShowDerivData();
	cout << "---------------------------" << endl;
	cout << "case2..... " << endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "---------------------------" << endl;
	cout << "case3..... " << endl;
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	cout << "---------------------------" << endl;
}
#endif

#if 0
#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase() : " << baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << endl;
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main(void)
{
	SoDerived drv1(15);
	SoDerived drv2(27);
	return 0;
}
#endif

#if 0
// DestModel.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
public:
	Person(const char* myname)
	{
		name = new char[strlen(myname) + 1];		
		strcpy(name, myname);
	}
	~Person()
	{
		delete[]name;			// 소멸자는 위 생성자에서 할당한 메모리 공간을 해제하도록 정의
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
};

class UnivStudent : public Person
{
private:
	char* major;
public:
	UnivStudent(const char* myname, const char* mymajor)
		: Person(myname)
	{
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}
	~UnivStudent()
	{
		delete[]major;			// 자신의 생성자에서 할당한 메모리 공간에 대한 해제만 책임지고 있음. 어차피 기초클래스의 소멸자 호출되며
	}							// 기초 클래스의 생성자에서 할당한 메모리 공간을 해제하기 때문.
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent st1("Kim", "Mathematics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
	return 0;
}
#endif

#if 0
// ProtectedHeri.cpp
#include <iostream>
using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() : num1(1), num2(2), num3(3)
	{ }
};

class Derived : protected Base { };	// empty

int main(void)
{
	Derived drv;
	cout << drv.num3 << endl;			// Base class의 num3에 접근 불가
	return 0;
}
#endif

#if 0
// ISAInheritance.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Computer			// 모든 컴퓨터의 공통적인 특성
{
private:
	char owner[50];				// 소유자 정보
public:
	Computer(const char* name)
	{
		strcpy(owner, name);
	}
	void Calculate()			// 계산
	{
		cout << "요청 내용을 계산합니다." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int Battery;				// 배터리 있어서 이동하면서 사용 가능
public:
	NotebookComp(const char * name, int initChag) 
		: Computer(name), Battery(initChag)		
	{ }
	void Charging() { Battery += 5; }
	void UseBattery() { Battery += 1; }
	void MovingCal()						// 컴퓨터 사용 시마다 배터리 소모
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp		// 펜 있는 컴퓨터
{
private: 
	char regstPenModel[50];
public:
	TabletNotebook(const char* name, int initChag, const char* pen)
		: NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, pen);
	}
	void Write(const char* penInfo)			// 등록된 펜 사용해야 필기가 가능
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("이수종", 5);
	TabletNotebook tn("정수영", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
	return 0;
}
#endif

#if 0
// HASInheritance.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;		// 장전된 총알 수
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police : public Gun
{
private:
	int handcuffs;	 // 소유한 수갑의 수
public:
	Police(int bnum, int bcuff)
		: Gun(bnum), handcuffs(bcuff)
	{ }
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
};

int main(void)
{
	Police pman(5, 3);
	pman.Shot();
	pman.PutHandcuff();
	return 0;
}
#endif

#if 0
//HASComposite.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shot()
	{
		cout << "BBANG" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;			// 상속이 아니라 객체 생성해서 이를 참조
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);		// 상속이 아니라 객체 생성해서 이를 참조
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()			//	상속이 아니라, Gun 객체를 멤버변수를 통해 참조하는 구조라서, 별도의 함수 정의해야 함
	{
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main(void)
{
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0, 3);			// 총 소유하지 않은 경찰 객체로 생성.
	pman2.Shot();
	pman2.PutHandcuff();
	return 0;
}
#endif

#if 0
// ObjectPointer.cpp
#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
public:
	void Study() { cout << "Study" << endl; }
};

class PartTimeStudent : public Student
{
public:
	void Work() { cout << "Work" << endl; }
};

int main(void)
{
	Person* ptr1 = new Student();		// Student는 Person을 상속하므로, Person형 포인터 변수는 Student 객체를 가리킬 수 있음.
	Person* ptr2 = new PartTimeStudent();	// PartTimeStudent는 Person을 간접 상속하므로, Person형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있음.
	Student* ptr3 = new PartTimeStudent();	// PartTimeStudent는 Student를 상속하므로, Student형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있음.
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}
#endif

#if 0
// EmployeeManager3.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Employee		// 고용인 클래스 
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
};

class PermanentWorker : public Employee		//	Employee 클래스 상속
{
private:
	int salary;	// 월급
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)
	{	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee		// 임시직
{
private:
	int workTime;		// 이 달의 근무시간 합계
	int payPerHour;		// 시간 당 급여
public:
	TemporaryWorker(char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}

};

class SalesWorker : public PermanentWorker		// 영업직도 정규직의 일종이기 때문에, Employee가 아닌 PermanentWorker 상속
{
private:
	int salesResult;		// 월 판매실적
	double bonusRatio;		// 상여금 비율
public:
	SalesWorker(char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay()		// PermanentWorker의 GetPay 함수 호출
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;	// SalesWorker의 GetPay 함수가 호출됨
	}
};

class EmployeeHandler			// 저장의 대상이 Employee 객체. (PermanentWorker 객체도 Employee 객체의 일종)
{
private:
	Employee* empList[50];		// Employee 객체의 주소 값을 저장하는 방식으로 객체 저장. 따라서, **Employee 클래스를 상속하는 클래스의 객체도 함께 저장 가능.**
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)	// 함수 인자로 Employee 객체의 주소 값을 전달해야 하므로, PermanentWorker 객체의 주소 값도 전달 가능.
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		/*
		for(int i = 0; i < empNum; i++)
			empList[i]->ShowsalaryInfo();			// 컴파일 에러
		*/
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		/*
		for(int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();			// 컴파일 에러
		*/
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};


int main(void)
{
	// 직원관리 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	// 정규직 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// 임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// 영업직 등록
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}
#endif


#if 0
// FunctionOverride.cpp
// FunctionVirtualOverride.cpp
#include <iostream>
using namespace std;

class First
{
public:
	//void MyFunc() { cout << "FirstFunc" << endl; }
	virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
	//void MyFunc() { cout << "SecondFunc" << endl; }
	virtual void MyFunc() { cout << "SecondFunc" << endl; }	// 굳이 virtual 안 써도 가상함수 되나, 사용해서 알리는 것이 좋음
};

class Third : public Second
{
public:
	//void MyFunc() { cout << "ThirdFunc" << endl; }
	virtual void MyFunc() { cout << "ThirdFunc" << endl; }	// 굳이 virtual 안 써도 가상함수 되나, 사용해서 알리는 것이 좋음
};

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}
#endif

#if 0
// EmployeeManager4.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Employee		// 고용인 클래스 
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const { return 0; }
	virtual void ShowSalaryInfo() const { }
};

class PermanentWorker : public Employee		//	Employee 클래스 상속
{
private:
	int salary;	// 월급
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)
	{	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee		// 임시직
{
private:
	int workTime;		// 이 달의 근무시간 합계
	int payPerHour;		// 시간 당 급여
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}

};

class SalesWorker : public PermanentWorker		// 영업직도 정규직의 일종이기 때문에, Employee가 아닌 PermanentWorker 상속
{
private:
	int salesResult;		// 월 판매실적
	double bonusRatio;		// 상여금 비율
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay()		// PermanentWorker의 GetPay 함수 호출
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;	// SalesWorker의 GetPay 함수가 호출됨
	}
};

class EmployeeHandler			// 저장의 대상이 Employee 객체. (PermanentWorker 객체도 Employee 객체의 일종)
{
private:
	Employee* empList[50];		// Employee 객체의 주소 값을 저장하는 방식으로 객체 저장. 따라서, **Employee 클래스를 상속하는 클래스의 객체도 함께 저장 가능.**
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)	// 함수 인자로 Employee 객체의 주소 값을 전달해야 하므로, PermanentWorker 객체의 주소 값도 전달 가능.
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for(int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();			// 가상함수. 가장 마지막에 오버라이딩한 함수가 호출됨.
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for(int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();			// 가상함수. 가장 마지막에 오버라이딩한 함수가 호출됨.
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};


int main(void)
{
	// 직원관리 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	// 정규직 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// 임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// 영업직 등록
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}
#endif

#if 0
// VirtualDestructor2.cpp
#include <iostream>
using namespace std;

class First
{
private:
	char* strOne;
public:
	First(const char* str)
	{
		strOne = new char[strlen(str) + 1];
	}
	virtual ~First()
	{
		cout << "~First()" << endl;
		delete[]strOne;		// 생성자에서 동적할당이 있었기에 적절한 소멸자
	}
};

class Second : public First
{
private:
	char* strTwo;
public:
	Second(const char* str1, const char* str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	virtual ~Second()
	{
		cout << "~Second()" << endl;
		delete[]strTwo;		// 생성자에서 동적할당이 있었기에 적절한 소멸자
	}
};

int main(void)
{
	First* ptr = new Second("simple", "complex");
	delete ptr;		// 바로 윗행에서 생성한 객체 소멸. 이 경우 First와 Second클래스 소멸자가 동시에 호출되어야
	return 0;
}
#endif


// ReferenceAttribute.cpp
#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj; // obj는 Second를 상속하는 Third객체이므로, Second형 참조자로 참조 가능
	sref.FirstFunc();	// 컴파일러는 참조자의 자료형을 가지고 함수의 호출 가능성 판단, First 클래스에 정의된 FirstFunc 함수와 
	sref.SecondFunc();	// Second 클래스에 정의된 SecondFunc함수는 호출이 가능하지만, ThirdFunc는 불가
	sref.SimpleFunc();		// SimpleFunc는 가상함수이므로, Third 클래스에 정의된 SimpleFunc()가 호출됨.

	First& fref = obj;	// obj는 First를 간접 상속하는 Third 객체이므로, First형 참조자로 참조 가능
	fref.FirstFunc();	// 컴파일러는 참조자 자료형 갖고 함수 호출 가능성 판단하므로, First 클래스에 정의된 함수만 호출 
	fref.SimpleFunc();	// 가능. 이 중 SimpleFunc는 가상함수이므로, Third 클래스에 정의된 SimpleFunc()가 호출
	return 0;
}