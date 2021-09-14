#if 0
#include <iostream>
using namespace std;
// EmployeeManager1.cpp�� class PermanentWorker ����
class PermanentWorker
{
private:
	char name[100];
	int salary; // �Ŵ� ���ҵǴ� �޿�
public:
	PermanentWorker(const char* name, int money) : salary(money)	// const �ٿ���
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

// EmployeeManager1.cpp�� class EmployeeHandler ����
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

//EmployeeManager1.cpp�� main
int main(void)
{
	EmployeeHandler handler;

	//�������
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	//�̹� �޿� �����ؾ� �� �޿� ����
	handler.ShowAllSalaryInfo();

	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;
}
#endif