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
	void merge(sll a, sll &b)
	{
		struct node *t1=start;

		struct node* t2=a.start;
		while (t1 && t2)
		{
			if (t1->data < t2->data)
			{
				b.insert_Last(t1->data);
				t1 = t1->next;
			}
			else if (t1->data > t2->data)
			{
				b.insert_Last(t2->data);
				t2 = t2->next;
			}
			else
			{
				b.insert_Last(t1->data);
				b.insert_Last(t1->data);
				t1 = t1->next;
				t2 = t2->next;
			}
		}
		while (t1)
		{
			b.insert_Last(t1->data);
			t1 = t1->next;
		}
		while (t2)
		{
			b.insert_Last(t2->data);
			t2 = t2->next;
		}
	}
};
int main()
{
	sll a, b, c;
	a.insert_Last(9);
	a.insert_Last(32);
	a.insert_Last(45);
	b.insert_Last(-2);
	b.insert_Last(7);
	b.insert_Last(10);
	cout << "List 1:";
	a.travel_forward();
	cout << endl << "List 2:";
	b.travel_forward();
	a.merge(b, c);
	cout << "\nMerged list:";
	c.travel_forward();
	return 0;
}