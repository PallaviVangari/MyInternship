#include<iostream>
using namespace std;

class Student
{
	char name[20];
	char grade[15];
	int s1;
	int s2;
	int s3;
public:
	friend class CollegeCourse;
};
class CollegeCourse
{
	Student s;
public:
	CollegeCourse(Student &s1)
	{
		s = s1;
	}

	void set_data(char name_temp[20], char grade_temp[15], int m1, int m2, int m3)
	{
		strcpy(s.name, name_temp);
		strcpy(s.grade, grade_temp);
		s.s1 = m1;
		s.s2 = m2;
		s.s3 = m3;
	}
	void calculateAverage()
	{
		cout << "Average=" << (s.s1 + s.s2 +s.s3) / 3;
	}
	void computeGrade()
	{
		int avg = (s.s1 + s.s2 + s.s3) / 3;
		if (avg > 60)
		{
			cout << "First class";
			strcpy(s.grade, "First class");
		}
		else if (avg > 50)
		{
			cout << "second class";
			strcpy(s.grade, "Second class");
		}
		else if (avg > 40)
		{
			cout << "Thirs class";
			strcpy(s.grade, "Third class");
		}
		if (s.s1 < 40 || s.s2 < 40 || s.s3 < 40)
		{
			cout << "Fail";
			strcpy(s.grade, "Fail");
		}
	}
	void display()
	{
		cout << "Name:" << s.name << "  Grade:" << s.grade << "  Marks1:" << s.s1 << " Marks2:" << s.s2 << "  Marks3:" << s.s3;
	}
};
int main()
{
	Student s1;
	CollegeCourse c1(s1);
	c1.set_data("Pallavi","First class", 78, 55, 45);
	c1.calculateAverage();
	c1.computeGrade();
	c1.display();
	return 0;

}