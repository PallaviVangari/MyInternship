#include<iostream>
using namespace std;

class Person
{
	char *name;
	int age;
public:
	void setValuesPerson(char* n, int a)
	{
		name = new char[strlen(n)+1];
		strcpy(name, n);
		age = a;
	}
	void displayPerson()
	{
		cout << "Name=" << name << " Age=" << age << endl;
	}
};
class Physique :virtual public Person
{
	int height;
	int width;
public:
	void setValuesPhysique(int h, int w)
	{
		height = h;
		width = w;
	}
	void displayPhysique()
	{
		cout << "Height=" << height << "Width=" << width << endl;
	}
};
class Family :virtual public Person
{
	int numChildren;
	char *religion;
public:
	void setValuesFamily(int n, char r[10])
	{
		numChildren = n;
		religion = new char[strlen(r) + 1];
		strcpy(religion, r);
	}
	void displayFamily()
	{
		cout << "Num of children=" << numChildren << " religion=" << religion << endl;
	}
};
class Employee :public Physique, Family
{
	int empno, salary;
public:
	Employee()
	{
		empno = 0;
		salary = 0;
	}
	void setValues(char name[10], int age, int ht, int wt, int numOfChild, char religion[10], int empn, int _salary)
	{
		setValuesPerson(name, age);
		setValuesPhysique(ht, wt);
		setValuesFamily(numOfChild, religion);
		empno = empn;
		salary = _salary;
	}
	void display()
	{
		displayPerson();
		displayPhysique();
		displayFamily();
		cout << "Employee number=" << empno << " Salary=" << salary << endl;
	}
	
};
int main()
{
	Employee emp;
	emp.setValues("Pallavi", 21, 5.2, 48, 0, "Hindu", 11, 20000);
	emp.display();
	return 0;

}