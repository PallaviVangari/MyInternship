#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
class stack_sll
{
	struct node* start;
public:
	stack_sll()
	{
		start = NULL;
	}
	~stack_sll()
	{
		struct node*temp;
		while (start)
		{
			temp = start;
			start = start->next;
			delete(temp);
		}
	}
	void push(int ele)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = start;
		start = temp;
	}
	int pop()
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
};
int main()
{
	stack_sll s;
	int ch, n;
	
	while (1)
	{
		cout << "Enter 1 for push 2 for pop 3 for printing the stack from top 4 for exit";
		cin >> ch;

		switch (ch)
		{
		case 1:cout << "enter element to push";
			cin >> n;
			s.push(n);
			break;
		case 2:
			cout << "Element poped=" << s.pop();
			break;
		case 3:
			cout << "Stack from top:";
			s.travel_forward();
			break;
		case 4:exit(0);
			break;
		default:cout << "Invalid choice";
		}
	}
	return 0;

}