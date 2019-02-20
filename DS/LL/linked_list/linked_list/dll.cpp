#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* prev;
	struct node* next;

};
class dll
{
	struct node* start;
public:
	dll()
	{
		start = NULL;
	}
	~dll()
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
		temp->prev = NULL;
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
			temp->prev = cur;
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
				temp->prev = cur;
				temp->next = cur->next;
				if(cur->next)
					cur->next->prev = temp;
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
			start->prev = NULL;
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
			//cur = new node;
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
				//if(cur->next)
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
			//cur = new node;
			cur = start;
			if (start->data == x)
			{
				start = start->next;
				delete(cur);
				return;
			}

			while (cur != NULL && cur->data != x)
				cur = cur->next;
			if (cur == NULL)
				cout << "Element not found";
			else
			{
				struct node* temp;
				temp = cur;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
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
			//cur = new node;
			cur = start;
			while (cur)
			{
				cout << cur->data << " ";
				cur = cur->next;
			}
		}
	}
	void travel_backward()
	{
		if (start == NULL)
			cout << "List is empty";
		else
		{
			struct node* temp;
			temp = start;
			while (temp->next)
			{
				temp = temp->next;
			}
			while (temp)
			{
				cout << temp->data << " ";
				temp = temp->prev;
			}
		}
	}


};

int main()
{
	dll l;
	int ch, n;
	while (1)
	{
		cout << "\nEnter 1 to insert_first 2 to insert_last 3 for insert_after \n 4 for printing the list in forward direction 5 to exit \n6 for deletinf first 7 for deleting last 8 for deleting specific \n 9 for printing the list in reverse order";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter the number to be put in the list";
			cin >> n;
			l.insert_First(n);
			break;
		case 2:cout << "Enter the number to be put in the list";
			cin >> n;
			l.insert_Last(n);
			break;
		case 3:
			int n1;
			cout << "Enter the number to be put in the list";
			cin >> n;
			cout << "Enter the element after which the insertion has to done";
			cin >> n1;
			l.insert_After(n1, n);
			break;
		case 4:
			cout << "The list is:";
			l.travel_forward();
			break;
		case 5:exit(0);
			break;
		case 6:
			cout << "The number deleted:" << l.delete_Front();
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
		default:cout << "Wrong choice";
		}
	}
	return 0;

}


