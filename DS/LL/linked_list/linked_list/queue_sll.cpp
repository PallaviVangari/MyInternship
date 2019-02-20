#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
class queue_sll
{
	struct node* start;
public:
	queue_sll()
	{
		start = NULL;
	}
	~queue_sll()
	{
		struct node*temp;
		while (start)
		{
			temp = start;
			start = start->next;
			delete(temp);
		}
	}
	void enqueue(int ele)
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
	int deque()
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
	queue_sll q;
	int ch, n;
	while (1)
	{
		cout << "Enter 1 for enqueue 2 for deque 3 for printing the queue 4 for exit";
		cin >> ch;

		switch (ch)
		{
		case 1:cout << "enter element to push";
			cin >> n;
			q.enqueue(n);
			break;
		case 2:
			cout << "Element poped=" << q.deque();
			break;
		case 3:
			cout << "Stack from top:";
			q.travel_forward();
			break;
		case 4:exit(0);
			break;
		default:cout << "Invalid choice";
		}
	}
	return 0;

}