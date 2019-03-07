#include<iostream>
using namespace std;

class Shape
{
	int numOfSides;
	char* colour;
public:
	Shape()
	{
		numOfSides = -1;
		colour = "colourless";
	}
	Shape(int n, char* temp_colour)
	{
		numOfSides = n;
		colour = new char[strlen(temp_colour) + 1];
		strcpy(colour, temp_colour);
	}
	void setValues(int n, char* temp_colour)
	{
		numOfSides = n;
		colour = new char[strlen(temp_colour) + 1];
		strcpy(colour, temp_colour);

	}
	virtual double calculate_area()
	{
		cout << "In area calculation of base class";
		return 0;
	}
};
class Triangle : public Shape
{
	int base,height;
public:
	Triangle(int b, int h)
	{
		base = b;
		height = h;
	}
	double calculate_area()
	{
		return 0.5*base*height;
	}
};
class Rectangle :public Shape
{
	int width, length;
public:
	Rectangle(int w, int l)
	{
		width = w;
		length = l;
	}
	double calculate_area()
	{
		return width*length;
	}
};
class Square :public Shape
{
	int side;
public:
	Square(int s)
	{
		side = s;
	}
	double calculate_area()
	{
		return side*side;
	}
};
int main()
{
	Shape *s;
	int a=0, b=0;  //variables taken for input

	char c[10];
	s = new Shape;
	cout << "Enter the base,height and colour of the triangle";
	cin >> a >> b >> c;
	
	Triangle t(a, b);
	s = &t;
	s->setValues(3, c);
	cout << "Area of the triangle=" << s->calculate_area();

	cout << "Enter the width,height and colour of the rectangle";
	cin >> a >> b >> c;

	Rectangle r(a, b);
	s = &r;
	s->setValues(4, c);
	cout << "Area of the rectangle=" << s->calculate_area();

	cout << "Enter the side and colour of the square";
	cin >> a >>  c;

	Square sq(a);
	s = &sq;
	s->setValues(4, c);
	cout << "Area of the square=" << s->calculate_area();
	return 0;
}