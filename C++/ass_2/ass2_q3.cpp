#include<iostream>
using namespace std;
class employee
{
	int emp_no;
	char * name;
	int sal;

public:
	employee()
	{
		emp_no = 0;
		sal = 0;
		name = NULL;
	}
	~employee()
	{
		cout << "im in destructor";
	}
	void set_val()
	{
		cout << "enter name";
		cin >> name;
		cout << "emoployee id";
		cin >> emp_no;
		cout << "salary";
		cin >> sal;
	}
	friend ostream& operator<<(ostream &,employee &s1);
	//friend istream& operator >> (istream &, employee &s1);
};

ostream& operator<<(ostream &cout, employee &s1)
{
	cout << s1.emp_no;
	cout << s1.name << s1.sal;
	return cout;
}
/*istream& operator >> (istream &cin,employee &s1)
{
	cin >> s1.rol_num;
	for (int i = 0; i < 6; i++)
		cin >> s1.marks[i];
	cin >> s1.avg >> s1.grade;
	return cin;
}*/
int main()
{
	employee s[5];
	cout << "enter student details";
	for (int i = 0; i < 5; i++)
		s[i].set_val ();
	for (int i = 0; i < 5; i++)
		cout << s[i];
}