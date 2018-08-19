#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}node;
typedef struct list
{
	node *head;
	node *tail;
}list;
void create_list(list &l)
{
	l.head = NULL;
	l.tail = NULL;
}
node* create_node(int value)
{
	node *new_node = new node;
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}
void print_linked_list(list l)
{
	cout << endl;
	node *x = l.head;
	while (x != NULL)
	{
		cout << x->data << " ";
		x = x->next;
	}
	cout << endl;
}
void add_head_with_node(list &l, node *new_node)
{
	if (l.head == NULL)
	{
		l.head = new_node;
		l.tail = l.head;
	}
	else 
	{
		new_node->next = l.head;
		l.head = new_node;
	}
}
void add_head_with_value(list &l, int value)
{
	node *adding = create_node(value);
	add_head_with_node(l, adding);
}
void add_tail_with_node(list &l, node *new_node)
{
	if (l.head == NULL)
	{
		l.head = new_node;
		l.tail = l.head;
	}
	else
	{
		l.tail->next = new_node;
		l.tail = new_node;
	}
}
void add_tail_with_value(list &l, int value)
{
	node *adding = create_node(value);
	add_tail_with_node(l, adding);
}
void insert_after_node_a_node(list &l, node *target, node *adding)
{
	if (adding != NULL)
	{
		adding->next = target->next;
		target->next = adding;
		if (l.tail == target) l.tail = adding;
	}
	else { add_head_with_node(l, adding); }
}
void insert_after_value_a_value(list &l, int target, int value) 
{
	node *count = l.head;
	while (count != NULL) {
		if (count->data == target)break;
		count = count->next;
	}
	node *adding = create_node(value);
	insert_after_node_a_node(l, count, adding);
}
void delete_head(list &l)
{
	if (l.head != NULL)
	{
		node *temp;
		temp = l.head;
		l.head = l.head->next;
		delete temp;
		if (l.head == NULL)l.tail = NULL;
	}
}
void delete_tail(list &l)
{
	if (l.head != NULL)
	{
		if (l.head == l.tail) delete_head(l);
		else
		{
			node *x = l.head;
			while (x != l.tail)
			{
				if (x->next == l.tail)
				{
					node *temp = l.tail;
					x->next = NULL;
					l.tail = x;
					delete temp;
					break;
				}
				x = x->next;
			}
		}
	}
}
void delete_after_node(list &l, node *target)
{
	if (l.head != NULL) {
		if (l.tail == target->next) delete_tail(l);
		else {
			node *t = target->next;
			target->next = t->next;
			t->next = NULL;
			if (target->next == NULL)l.tail = target;
			delete t;
		}
	}
}
void delete_after_value(list &l,int target) {
	node *count = l.head;
	while (count != NULL) {
		if (count->data == target)break;
		count = count->next;
	}
	delete_after_node(l, count);
}
void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}
void sort(list &l) {
	node *i = l.head;
	node *j;
	while (i->next != NULL) {
		j = i->next;
		while (j != NULL) {
			if (i->data > j->data)swap(i->data, j->data);
			j = j->next;
		}
		i = i->next;
	}
}
int search(list &l, int x) {
	node *i = l.head;
	int p = 0;
	while (i != NULL) {
		if(i->data == x){
			return p;
		}
		i = i->next;
	}
	return -1;
}
int main()
{
	list l;
	create_list(l);
	for (int i = 0; i < 10; i++)
	{
		add_head_with_value(l,i);
	}
	print_linked_list(l);
	//print_linked_list2(l.head);
	delete_head(l);
	delete_tail(l);
	insert_after_value_a_value(l, 5,100);
	print_linked_list(l);
	delete_after_value(l, 100);
	print_linked_list(l);
	sort(l);
	print_linked_list(l);
	int f = search(l, 1000);
	if (f != -1)cout << endl << "co" << endl; else cout << endl << "eo co!" << endl;
	system("pause");
	return 0;
}