#include <iostream>
#include <malloc.h>
using namespace std;

struct link
{
	int data;
	link *link;
};

class List
{
private:
	link *first;

public:
	List();
	void reversetolast();
	void addlast(int d);
	void addstart(int d);
	void del(int v);
	void delt();
	void addaft(int d, int p);
	void show();
	void swap();
	void minmax();
	void selection();
	void bubble();
	void rep(int d, int p);
	void meanmedian();
};
List::List()
{
	first = NULL;
}

void List::meanmedian()
{
	struct link *temp;
	int mean, med, i = 0;

	if (first == NULL)
	{
		cout << "\nEmpty list\n"
			 << endl;
		return;
	}
	temp = first;
	while (temp != NULL)
	{
		mean += temp->data;
		++i;
		cout << temp->data << " ";
		temp = temp->link;
	}
	med = i / 2; // Didn't Knew the Formulas of Mean and Median (Internet Not Working)
	mean /= i;	 // Didn't Knew the Formulas of Mean and Median (Internet Not Working)
	cout << "\nMean=" << mean << endl;
	cout << "\nMedian=" << med << endl;
}

void List::rep(int d, int p)
{
	link *temp, *next;
	if (first == NULL)
	{
		cout << "\nEmpty list\n"
			 << endl;
		return;
	}
	next = first;
	for (int i = 1; i < p; i++)
	{
		next = next->link;
		if (next == NULL)
		{
			cout << "\nLess Elements\n\n";
			return;
		}
	}
	next->data = d;
}

void List::bubble()
{
	int count = 0, i;
	link *start = first;
	link *curr = NULL;
	link *next = NULL;
	link *temp = NULL;

	while (start != NULL)
	{
		count++;
		start = start->link;
	}
	for (i = 0; i < count; ++i)
	{
		curr = next = first;
		while (curr->link != NULL)
		{
			if (curr->data > curr->link->data)
			{
				temp = curr->link;
				curr->link = curr->link->link;
				temp->link = curr;

				if (curr == first)
					first = next = temp;
				else
					next->link = temp;
				curr = temp;
			}
			next = curr;
			curr = curr->link;
		}
	}
}

void List::selection()
{
	int val1, val2;
	for (link *p = first, *p1, *pos; p->link != NULL; p = p->link)
	{
		val1 = p->data;
		pos = p;
		for (link *q = p; q->link != NULL; q = q->link)
		{
			val2 = (*(q->link)).data;
			if (val2 < val1)
			{
				val1 = val2;
				pos = q;
			}
		}
		if (val1 != p->data)
		{
			link *temp = pos->link;
			if (temp != NULL)
				pos->link = temp->link;
			else
				pos->link = NULL;
			if (pos != p)
			{
				temp->link = p->link;
				p->link = pos->link;
				pos->link = p;
			}
			else
				temp->link = p;
			if (p == first)
				first = temp;
			else
				p1->link = temp;
			p = temp;
		}
		p1 = p;
	}
}

void List::minmax()
{
	struct link *ptr, *temp;
	int min, max;

	if (first == NULL)
	{
		cout << "\nEmpty list\n"
			 << endl;
		return;
	}
	ptr = first;
	min = first->data;
	max = first->data;

	while (ptr != NULL)
	{
		if (ptr->data <= min)
		{
			min = ptr->data;
		}
		if (ptr->data >= max)
		{
			max = ptr->data;
		}
		ptr = ptr->link;
	}
	cout << "\nMinimum Number is " << min << endl;
	cout << "\nMax Number is " << max << endl;
}

void List::swap()
{
	struct link *ptr, *temp;

	if (first == NULL)
	{
		cout << "\nEmpty list\n"
			 << endl;
		return;
	}

	ptr = first;

	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	temp = new link;
	temp->data = first->data;
	first->data = ptr->data;
	ptr->data = temp->data;
	delete temp;
}

void List::addstart(int d)
{
	struct link *temp;
	temp = (struct link *)malloc(sizeof(struct link *));
	temp->data = d;
	temp->link = first;
	first = temp;
	return;
}

void List::addlast(int d)
{
	link *ptr, *temp;
	if (first == NULL)
	{
		first = new link;
		first->data = d;
		first->link = NULL;
	}
	else
	{
		ptr = first;
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		temp = new link;
		temp->data = d;
		temp->link = NULL;
		ptr->link = temp;
	}
}

void List::reversetolast()
{
	link *ptr, *temp;
	if (first == NULL)
	{
		cout << "List EMpty";
	}
	else
	{
		ptr = first;
		while (ptr->link->link != NULL)
		{
			ptr = ptr->link;
		}
		temp = new link;
		temp->data = ptr->link->data;
		temp->link = first;
		ptr->link = NULL;
		first = temp;
	}
}

void List::del(int v)
{
	link *temp, *pre;
	temp = first;
	if (temp->data == v)
	{
		first = temp->link;
		delete temp;
		cout << endl
			 << v << " has been deleted" << endl;
		return;
	}
	pre = temp;
	while (temp != NULL)
	{
		if (temp->data == v)
		{
			pre->link = temp->link;
			delete temp;
			cout << endl
				 << v << " is deleted" << endl;
			return;
		}
		pre = temp;
		temp = temp->link;
	}
	cout << endl
		 << v << " not found" << endl;
}

void List::delt()
{
	link *temp, *pre;
	temp = first;
	if (temp->data % 3 == 0)
	{
		first = temp->link;
		delete temp;
		return;
	}
	pre = temp;
	while (temp != NULL)
	{
		if (temp->data % 3 == 0)
		{
			pre->link = temp->link;
			delete temp;
			if (temp->link == NULL && temp->data % 3 == 0)
			{
				pre->link = temp->link;
				delete temp;
				return;
			}
		}
		pre = temp;
		temp = temp->link;
	}
}

void List::addaft(int d, int p)
{
	link *temp, *next;
	next = first;
	for (int i = 1; i < p - 1; i++)
	{
		next = next->link;
		if (next == NULL)
		{
			cout << "\nLess Elements\n\n";
			return;
		}
	}
	temp = (struct link *)malloc(sizeof(struct link *));
	temp->link = next->link;
	temp->data = d;
	next->link = temp;
}

void List::show()
{
	link *temp;
	int i = 0;
	temp = first;
	cout << "\nList is as follow\n";
	while (temp != NULL)
	{
		++i;
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << "\nTotal Number of Nodes=" << i << endl;
}

int main()
{
	List l;
	int ch = 1, ans, pos;
	l.addlast(15);
	l.addlast(18);
	l.addlast(31);
	l.addlast(43);
	l.addlast(27);
	l.show();
	while (ch != 0)
	{
		cout << "\nChoose the Option:\n1:For Adding at Last\n2:For Subtract\n3:To Show Data";
		cout << "\n4:To add at nth Position\n5:To Add Element at Start\n6:To Swap first and Last Element\n7:To Find Min and Max";
		cout << "\n8:To Replace a Value at nth Position\n9:To Find Mean and Median\n10:Selection Sort\n11:Bubble Sort\n\n\n";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "\nEnter Value to Add at Last Position:\n";
			cin >> ans;
			l.addlast(ans);
			l.show();
			break;
		case 2:
			cout << "\nEnter Value to Subtract:\n";
			cin >> ans;
			l.del(ans);
			l.show();
			break;
		case 3:

			l.delt();
			l.show();
			break;
		case 4:
			cout << "\nEnter Value to Add:\n";
			cin >> ans;
			cout << "\nEnter Position:\n";
			cin >> pos;
			l.addaft(ans, pos);
			l.show();
			break;

		case 5:
			cout << "\nEnter Value at First Position:\n";
			cin >> ans;
			l.addstart(ans);
			l.show();
			break;

		case 6:
			l.swap();
			l.show();
			break;

		case 7:
			l.show();
			l.reversetolast();
			l.minmax();
			break;

		case 8:
			cout << "\nEnter Value:\n";
			cin >> ans;
			cout << "\nEnter Position of Existing Value:\n";
			cin >> pos;
			l.rep(ans, pos);
			l.show();
			break;

		case 9:
			l.meanmedian();
			break;

		case 10:
			l.selection();
			break;

		case 11:
			l.bubble();
			l.show();
			break;

		default:
			cout << "\nWrong Input\n";
		}
	}

	return 0;
}
