#include<iostream>
using namespace std;
template<class T>
int linear_search(T* a, T k,int n=0)
{
	//cout << "num of elements=" << n;
	//cout << "k=" << k;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == k)
			return i;
		//cout << "a[" << i << "]=" << a[i];
	}
	return -1;
}
int linear_search(char** s, char* c,int l)
{
	for (int i = 0; i < l; i++)
	{
		if (strcmp(c, s[i]) == 0)
			return i;
	}
	return -1;
}
int main()
{
	int n, *a, key, res, choice;

	float *f, k;
	double *d, K;
	char **s;
	char *keys;
	cout << "Enter the number of elements in the array:";
	cin >> n;

	cout << "Enter 1 for integers  2 for float  3 for double 4 for strings";
	cin >> choice;
	switch (choice)
	{


	case 1:

		a = new int[n];
		cout << "Enter the integers";
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << "Enter the integer to be searched";
		cin >> key;
		res = linear_search<int>(a, key,n);
		if (res == -1)
			cout << "The element is not present in the array";
		else
			cout << "The element is present at"<<res<<"position ";
			break;
	case 2:
		f = new float[n];
		cout << "Enter the floating point numbers in the array";
		for (int i = 0; i < n; i++)
			cin >> f[i];
		cout << "Enter the number to be searched";
		cin >> k;
		res = linear_search<float>(f, k,n);
		if (res == -1)
			cout << "The element is not present in the array";
		else
			cout << "The element is present at"<<res<<"position";
			break;
	case 3:
		d = new double[n];
		cout << "Enter the elements in the array";
		for (int i = 0; i < n; i++)
			cin >> d[i];
		cout << "Enter the number to be searched:";
		cin >> K;
		res = linear_search<double>(d, K,n);
		if (res == -1)
			cout << "The element is not present in the array";
		else
			cout << "The element is present at"<<res<<"position ";
			break;

	case 4:
		s = new char*[n];
		for (int i = 0; i < n; i++)
			s[i] = new char[10];
		cout << "Enter the strings i the array:";
		for (int i = 0; i < n; i++)
			cin >> s[i];
		cout << "Enter the string to be searched:";
		keys = new char[10];
		cin >> keys;
		res = linear_search(s, keys, n);
		if (res == -1)
			cout << "The element is not present in the array";
		else
			cout << "The element is present at"<<res<<"position ";
			break;
	}
	return 0;
}