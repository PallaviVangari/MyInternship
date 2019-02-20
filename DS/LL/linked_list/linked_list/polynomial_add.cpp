
#include<iostream>
using namespace std;

struct node
{
	int coef;
	int pow;
	struct node*next;
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
	void insert_First(int c,int p)
	{
		struct node *temp;
		temp = new node;
		temp->coef = c;
		temp->pow = p;
		temp->next = start;
		start = temp;
	}
	void insert_Last(int c,int p)
	{
		struct node *temp;
		temp = new node;
		temp->coef= c;
		temp->pow = p;
		temp->next = NULL;
		if (start == NULL)
			start = temp;
		else
		{
			struct node*cur;
			//cur = new node;
			cur = start;
			while (cur->next)
				cur = cur->next;
			cur->next = temp;
		}
	}
/*	void insert_After(int sele, int ele)
	{
		if (start == NULL)
			cout << "List is empty";
		else
		{
			struct node* cur;
			cur = new node;
			cur = start;
			while (cur != NULL && cur->data != sele)
				cur = cur->next;
			if (cur == NULL)
				cout << "Element not found";
			else
			{
				struct node* temp;
				temp = new node;
				temp->data = ele;
				temp->next = cur->next;
				cur->next = temp;
			}
		}
	}
	int delete_Front()
	{
		int x = -999;
		if (start == NULL)
			cout << "List is empty";
		else
		{
			struct node* temp;
			temp = new node;
			temp = start;
			start = start->next;
			x = temp->data;
			delete(temp);
			return x;
		}
	}
	int delete_Last()
	{
		int x = -999;
		if (start == NULL)
			cout << "List is empty";
		else
		{
			struct node * cur;
			cur = new node;
			cur = start;
			if (start->next == NULL)
			{
				start = NULL;
				x = cur->data;
				delete(cur);
				return x;
			}
			else
			{
				while (cur->next->next)
					cur = cur->next;
				struct node*temp;
				temp = new node;
				temp = cur->next;
				cur->next = NULL;
				x = temp->data;
				delete(temp);
				return x;
			}
		}
	}
	void delete_Spec(int x)
	{
		if (start == NULL)
			cout << "List is empty";
		else
		{
			struct node* cur;
			cur = new node;
			cur = start;
			if (start->data == x)
			{
				start = start->next;
				delete(cur);
				return;
			}

			while (cur->next != NULL && cur->next->data != x)
				cur = cur->next;
			if (cur->next == NULL)
				cout << "Element not found";
			else
			{
				struct node* temp;
				temp = cur->next;
				cur->next = temp->next;
				delete(temp);
			}
		}

	}/*/
	void travel_forward()
	{
		if (start == NULL)
			cout << "List is empty";
		else
		{
			struct node* cur;
			//cur = new node;
			cur = start;
			while (cur)
			{
				cout << cur->coef << "x"<<cur->pow<<"  +  ";
				cur = cur->next;
			}
		}
	}
/*	void travel_backward()
	{
		if (start == NULL)
			cout << "List is empty";
		else
		{
			print(start);
			//cout << cur->data << " ";
		}
	}
	friend void print(struct node*);
	void reverse()
	{
		struct node*pprev = NULL, *prev = NULL, *cur = start;
		while (cur)
		{
			pprev = prev;
			prev = cur;
			cur = cur->next;
			prev->next = pprev;
		}
		start = prev;

	}*/
	friend void add(sll, sll,sll&);

};
/*
void print(struct node* temp)
{
	if (temp)
	{
		print(temp->next);
		cout << temp->data << "  ";
	}
}*/

void add(sll l1, sll l2,sll &l3)
{
	//struct node* t3 = l3.start;
	struct node* t1;
	t1=l1.start;
	struct node* t2;
	t2=l2.start;
	while (t1 && t2)
	{
		if (t1->pow == t2->pow)
		{
			l3.insert_Last(t1->coef + t2->coef, t1->pow);
			//l3.travel_forward();
			t1 = t1->next;
			t2 = t2->next;
		}
		else if (t1->pow > t2->pow)
		{
			l3.insert_Last(t1->coef, t1->pow);
			t1 = t1->next;
		}
		else
		{
			l3.insert_Last(t2->coef, t2->pow);
			t2 = t2->next;
		}
	}
	while (t1)
	{
		l3.insert_Last(t1->coef, t1->pow);
		t1 = t1->next;
	}
	while (t2)
	{
		l3.insert_Last(t2->coef, t2->pow);
		t2 = t2->next;
	}
}
int main()
{
	sll a, b, c;
	int ch, x, y;
	cout << "Enter the coef and power of poly 1:";
	while(1)
	{
		cout << "Enter -1 to stop the insertion";
			cin >> ch;
		if (ch == -1)
			break;
		cin >> x>> y;
		a.insert_Last(x, y);
	}
	cout << "List 1:";
	a.travel_forward();
	cout << "\nEnter the coef and power of poly 2:";
	ch = 0;
	while(1)
	{
		cout << "Enter -1 to stop the insertion";
		cin >> ch;
		if (ch == -1)
			break;
		cin >> x >> y;
		b.insert_Last(x, y);
	}
	cout << "\nList2:";
	b.travel_forward();
	add(a, b, c);
	
	
	cout << "\nThe list after addition=";
	c.travel_forward();
	return 0;
}