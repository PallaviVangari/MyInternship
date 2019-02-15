#include<iostream>
using namespace std;
class Student
{
	int rollnum;
	int m1;
	int m2;
	int total;
	char grade;
public:
	Student()
	{
		rollnum = 0;
		m1 = 0;
		m2 = 0;
		total = 0;
		grade = 'N';
	}
	
	friend void generate_results (Student s[], int n);
	friend ostream& operator<<(ostream& a, Student s);
	friend istream& operator>> (istream& c,Student &s);
};
ostream& operator<<(ostream& cout, Student s)
{
	cout << "Student details:" << endl;
	cout << "Roll num" << s.rollnum << "  Marks1:" << s.m1 << "  Marks2:" << s.m2 << endl;
	cout << "Total marks:" << s.total << "  Grade:" << s.grade;
	return cout;
}
istream& operator >> (istream& cin, Student &s)
{
	cin >> s.rollnum;
	cin >> s.m1 >> s.m2;
	return cin;
}
void generate_results(Student s[], int n)
{
	for (int i = 0; i < n; i++)
	{
		s[i].total = s[i].m1 + s[i].m2;
		if ((s[i].total)/2 >= 75)
			s[i].grade = 'A';
		else if ((s[i].total)/2 >= 50)
			s[i].grade = 'B';
		else
			s[i].grade = 'C';

	}
}
int main()
{
	Student s[5];
	cout << "Enter 5 student details";
	for (int i = 0;i < 5; i++)
		cin >> s[i];
	generate_results(s, 5);
	cout << "\nStudent details";
	for (int i = 0; i < 5; i++)
	{
		cout << s[i] << endl;
	}
	return 0;

}