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

class UnivStudent : public Person // Person class ����� �ǹ�
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
		delete[]name;			// �Ҹ��ڴ� �� �����ڿ��� �Ҵ��� �޸� ������ �����ϵ��� ����
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
		delete[]major;			// �ڽ��� �����ڿ��� �Ҵ��� �޸� ������ ���� ������ å������ ����. ������ ����Ŭ������ �Ҹ��� ȣ��Ǹ�
	}							// ���� Ŭ������ �����ڿ��� �Ҵ��� �޸� ������ �����ϱ� ����.
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
	cout << drv.num3 << endl;			// Base class�� num3�� ���� �Ұ�
	return 0;
}
#endif

#if 0
// ISAInheritance.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Computer			// ��� ��ǻ���� �������� Ư��
{
private:
	char owner[50];				// ������ ����
public:
	Computer(const char* name)
	{
		strcpy(owner, name);
	}
	void Calculate()			// ���
	{
		cout << "��û ������ ����մϴ�." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int Battery;				// ���͸� �־ �̵��ϸ鼭 ��� ����
public:
	NotebookComp(const char * name, int initChag) 
		: Computer(name), Battery(initChag)		
	{ }
	void Charging() { Battery += 5; }
	void UseBattery() { Battery += 1; }
	void MovingCal()						// ��ǻ�� ��� �ø��� ���͸� �Ҹ�
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp		// �� �ִ� ��ǻ��
{
private: 
	char regstPenModel[50];
public:
	TabletNotebook(const char* name, int initChag, const char* pen)
		: NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, pen);
	}
	void Write(const char* penInfo)			// ��ϵ� �� ����ؾ� �ʱⰡ ����
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("�̼���", 5);
	TabletNotebook tn("������", 5, "ISE-241-242");
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
	int bullet;		// ������ �Ѿ� ��
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
	int handcuffs;	 // ������ ������ ��
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
	Gun* pistol;			// ����� �ƴ϶� ��ü �����ؼ� �̸� ����
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);		// ����� �ƴ϶� ��ü �����ؼ� �̸� ����
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()			//	����� �ƴ϶�, Gun ��ü�� ��������� ���� �����ϴ� ������, ������ �Լ� �����ؾ� ��
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

	Police pman2(0, 3);			// �� �������� ���� ���� ��ü�� ����.
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
	Person* ptr1 = new Student();		// Student�� Person�� ����ϹǷ�, Person�� ������ ������ Student ��ü�� ����ų �� ����.
	Person* ptr2 = new PartTimeStudent();	// PartTimeStudent�� Person�� ���� ����ϹǷ�, Person�� ������ ������ PartTimeStudent ��ü�� ����ų �� ����.
	Student* ptr3 = new PartTimeStudent();	// PartTimeStudent�� Student�� ����ϹǷ�, Student�� ������ ������ PartTimeStudent ��ü�� ����ų �� ����.
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

class Employee		// ����� Ŭ���� 
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

class PermanentWorker : public Employee		//	Employee Ŭ���� ���
{
private:
	int salary;	// ����
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

class TemporaryWorker : public Employee		// �ӽ���
{
private:
	int workTime;		// �� ���� �ٹ��ð� �հ�
	int payPerHour;		// �ð� �� �޿�
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

class SalesWorker : public PermanentWorker		// �������� �������� �����̱� ������, Employee�� �ƴ� PermanentWorker ���
{
private:
	int salesResult;		// �� �ǸŽ���
	double bonusRatio;		// �󿩱� ����
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
		return PermanentWorker::GetPay()		// PermanentWorker�� GetPay �Լ� ȣ��
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;	// SalesWorker�� GetPay �Լ��� ȣ���
	}
};

class EmployeeHandler			// ������ ����� Employee ��ü. (PermanentWorker ��ü�� Employee ��ü�� ����)
{
private:
	Employee* empList[50];		// Employee ��ü�� �ּ� ���� �����ϴ� ������� ��ü ����. ����, **Employee Ŭ������ ����ϴ� Ŭ������ ��ü�� �Բ� ���� ����.**
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)	// �Լ� ���ڷ� Employee ��ü�� �ּ� ���� �����ؾ� �ϹǷ�, PermanentWorker ��ü�� �ּ� ���� ���� ����.
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		/*
		for(int i = 0; i < empNum; i++)
			empList[i]->ShowsalaryInfo();			// ������ ����
		*/
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		/*
		for(int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();			// ������ ����
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
	// �������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
	EmployeeHandler handler;

	// ������ ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// �ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// ������ ���
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
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
	virtual void MyFunc() { cout << "SecondFunc" << endl; }	// ���� virtual �� �ᵵ �����Լ� �ǳ�, ����ؼ� �˸��� ���� ����
};

class Third : public Second
{
public:
	//void MyFunc() { cout << "ThirdFunc" << endl; }
	virtual void MyFunc() { cout << "ThirdFunc" << endl; }	// ���� virtual �� �ᵵ �����Լ� �ǳ�, ����ؼ� �˸��� ���� ����
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

class Employee		// ����� Ŭ���� 
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

class PermanentWorker : public Employee		//	Employee Ŭ���� ���
{
private:
	int salary;	// ����
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

class TemporaryWorker : public Employee		// �ӽ���
{
private:
	int workTime;		// �� ���� �ٹ��ð� �հ�
	int payPerHour;		// �ð� �� �޿�
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

class SalesWorker : public PermanentWorker		// �������� �������� �����̱� ������, Employee�� �ƴ� PermanentWorker ���
{
private:
	int salesResult;		// �� �ǸŽ���
	double bonusRatio;		// �󿩱� ����
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
		return PermanentWorker::GetPay()		// PermanentWorker�� GetPay �Լ� ȣ��
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;	// SalesWorker�� GetPay �Լ��� ȣ���
	}
};

class EmployeeHandler			// ������ ����� Employee ��ü. (PermanentWorker ��ü�� Employee ��ü�� ����)
{
private:
	Employee* empList[50];		// Employee ��ü�� �ּ� ���� �����ϴ� ������� ��ü ����. ����, **Employee Ŭ������ ����ϴ� Ŭ������ ��ü�� �Բ� ���� ����.**
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)	// �Լ� ���ڷ� Employee ��ü�� �ּ� ���� �����ؾ� �ϹǷ�, PermanentWorker ��ü�� �ּ� ���� ���� ����.
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for(int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();			// �����Լ�. ���� �������� �������̵��� �Լ��� ȣ���.
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for(int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();			// �����Լ�. ���� �������� �������̵��� �Լ��� ȣ���.
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
	// �������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
	EmployeeHandler handler;

	// ������ ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// �ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// ������ ���
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
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
		delete[]strOne;		// �����ڿ��� �����Ҵ��� �־��⿡ ������ �Ҹ���
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
		delete[]strTwo;		// �����ڿ��� �����Ҵ��� �־��⿡ ������ �Ҹ���
	}
};

int main(void)
{
	First* ptr = new Second("simple", "complex");
	delete ptr;		// �ٷ� ���࿡�� ������ ��ü �Ҹ�. �� ��� First�� SecondŬ���� �Ҹ��ڰ� ���ÿ� ȣ��Ǿ��
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

	Second& sref = obj; // obj�� Second�� ����ϴ� Third��ü�̹Ƿ�, Second�� �����ڷ� ���� ����
	sref.FirstFunc();	// �����Ϸ��� �������� �ڷ����� ������ �Լ��� ȣ�� ���ɼ� �Ǵ�, First Ŭ������ ���ǵ� FirstFunc �Լ��� 
	sref.SecondFunc();	// Second Ŭ������ ���ǵ� SecondFunc�Լ��� ȣ���� ����������, ThirdFunc�� �Ұ�
	sref.SimpleFunc();		// SimpleFunc�� �����Լ��̹Ƿ�, Third Ŭ������ ���ǵ� SimpleFunc()�� ȣ���.

	First& fref = obj;	// obj�� First�� ���� ����ϴ� Third ��ü�̹Ƿ�, First�� �����ڷ� ���� ����
	fref.FirstFunc();	// �����Ϸ��� ������ �ڷ��� ���� �Լ� ȣ�� ���ɼ� �Ǵ��ϹǷ�, First Ŭ������ ���ǵ� �Լ��� ȣ�� 
	fref.SimpleFunc();	// ����. �� �� SimpleFunc�� �����Լ��̹Ƿ�, Third Ŭ������ ���ǵ� SimpleFunc()�� ȣ��
	return 0;
}