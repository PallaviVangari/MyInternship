#include<iostream>
using namespace std;
class Point
{
	int x;
	int y;
public:
	void insert()
	{
		cout << "Enter x and y";
		cin >> x >> y;
	}
	friend float distance(Point a, Point b);
};
float distance(Point a, Point b)
{
	return sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y)));
}
int main()
{
	Point p1, p2;
	p1.insert();
	p2.insert();
	cout << "Distance=" << distance(p1, p2);
	return 0;

}