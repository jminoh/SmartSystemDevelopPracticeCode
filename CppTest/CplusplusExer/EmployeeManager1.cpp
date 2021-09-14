#if 0
#include <iostream>
using namespace std;
// EmployeeManager1.cpp의 class PermanentWorker 정의
class PermanentWorker
{
private:
	char name[100];
	int salary; // 매달 지불되는 급여
public:
	PermanentWorker(const char* name, int money) : salary(money)	// const 붙여줌
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "slalry: " << GetPay() << endl << endl;
	}
};

// EmployeeManager1.cpp의 class EmployeeHandler 정의
class EmployeeHandler
{
private:
	PermanentWorker* empList[80];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(PermanentWorker* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

//EmployeeManager1.cpp의 main
int main(void)
{
	EmployeeHandler handler;

	//직원등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	//이번 달에 지불해야 할 급여 정보
	handler.ShowAllSalaryInfo();

	//이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}
#endif