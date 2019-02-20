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
	void insert_First(int ele)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = start;
		start = temp;
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
	void insert_After(int sele, int ele)
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
			x = temp ->data;
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

	}
	void travel_forward()
	{
		if (start == NULL)
			cout << "List is empty";
		else
		{
			struct node* cur;
			cur = new node;
			cur= start;
			while (cur)
			{
				cout << cur->data << " ";
				cur = cur->next;
			}
		}
	}
	void travel_backward()
	{
		if(start==NULL)
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
		struct node*pprev=NULL, *prev=NULL, *cur = start;
		while (cur)
		{
			pprev = prev;
			prev = cur;
			cur = cur->next;
			prev->next = pprev;
		}
		start = prev;

	}
	
};
void print(struct node* temp)
{
	if (temp)
	{
		print(temp->next);
		cout << temp->data << "  ";
	}
}
int main()
{
	sll l;
	int ch, n;
	while (1)
	{
		cout << "\nEnter 1 to insert_first 2 to insert_last 3 for insert_after \n 4 for printing the list in forward direction 5 to exit \n6 for deletinf first 7 for deleting last 8 for deleting specific \n 9 for printing the list in reverse order 10 for reversing the lsit";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter the number to be put in the queue";
			cin >> n;
			l.insert_First(n);
			break;
		case 2:cout << "Enter the number to be put in the queue";
			cin >> n;
			l.insert_Last(n);
			break;
		case 3:
			int n1;
			cout << "Enter the number to be put in the queue";
			cin >> n;
			cout << "Enter the element after which the insertion has to done";
				cin >> n1;
			l.insert_After(n1,n);
			break;
		case 4:
			cout << "The list is:";
			l.travel_forward();
			break;
		case 5:exit(0);
			break;
		case 6:
			cout<<"The number deleted:"<<l.delete_Front();
			break;
		case 7:
			cout << "The number deleted:" << l.delete_Last();
			break;
		case 8:
			int n;
			cout << "enter The number to be deleted ";
			cin >> n;
			l.delete_Spec(n);
			break;
		case 9:
			cout << "The list in backward direction:";
			l.travel_backward();
			break;
		case 10:
			l.reverse();
			cout << "\nThe list is reversed";
			break;
		default:cout << "Wrong choice";
		}
	}
	return 0;

}


