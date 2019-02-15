#include<iostream>
using namespace std;
class Matrix
{
	int **ptr;
	int m;
	int n;
public:
	Matrix(int a, int b)
	{
		m = a;
		n = b;
		ptr = new int*[m];
		for (int i = 0; i < m; i++)
			ptr[i] = new int[n];
	}
	void insert()
	{
		cout << "Enter values of matrix in row mjor order";
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> ptr[i][j];
	}
	void display()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << ptr[i][j];
			cout << endl;
		}
	}
	friend Matrix multiply(Matrix a, Matrix b);
};
Matrix multiply(Matrix a, Matrix b)
{
	Matrix temp(a.m,b.n);
	if (a.n == b.m)
	{
		for (int i = 0; i < a.m; i++)
		{
			for (int j = 0; j < b.n; j++)
			{
				temp.ptr[i][j] = 0;
				for (int k = 0; k < a.n; k++)
				{
					temp.ptr[i][j]+= a.ptr[i][k] * b.ptr[k][j];
				}
			}
		}
		return temp;
	}
	else
		cout << "Incompatible matrices";
}
int main()
{
	Matrix a(2, 3), b(3, 2);
	a.insert();
	b.insert();
	Matrix c = multiply(a, b);
	cout << "First matrix" << endl;
	a.display();
	cout << endl << "Second matrix:" << endl;
	b.display();
	cout << endl << "a*b=" << endl;
	c.display();
	return 0;

}