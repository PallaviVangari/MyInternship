#include<iostream>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
class sll
{
	struct node* start;
public:
	sll()
	{
		start = NULL;
	}
	~sll()
	{
		struct node*temp;
		while (start)
		{
			temp = start;
			start = start->next;
			delete(temp);
		}
	}
	void insert_Last(int ele)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = NULL;
		if (start == NULL)
			start = temp;
		else
		{
			struct node*cur;
			cur = new node;
			cur = start;
			while (cur->next)
				cur = cur->next;
			cur->next = temp;
		}
	}
	void travel_forward()
	{
		if (start == NULL)
			cout << "List is empty";
		else
		{
			struct node* cur;
			cur = new node;
			cur = start;
			while (cur)
			{
				cout << cur->data << " ";
				cur = cur->next;
			}
		}
	}
	void self_adjust(int d)
	{
		struct node* temp = start;
		if (start == NULL)
			cout << "The list is empty";
		else if (temp->next == NULL)
			cout << "list has only one element";
		else
		{

			while (temp->next && temp->next->data != d)
				temp = temp->next;
			if (temp->next == NULL)
				cout << "element not in list";
			else
			{
				struct node*t = temp ->next;
				temp->next = temp->next->next;
				t->next = start;
				start = t;

			}
		}
	}
};
int main()
{
	sll a;
	int n;
	cout << "Enter the elements in the list. enter -999 when done";
	while (1)
	{
		cin >> n;;
		if (n == -999)
			break;
		a.insert_Last(n);
	}
	cout << "The list is:";
	a.travel_forward();
	cout << "Enter the element where the list has to be self adjusted";
	cin >> n;
	a.self_adjust(n);
	cout << "New list:";
	a.travel_forward();
	return 0;
}