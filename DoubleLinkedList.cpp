#include<iostream>
using namespace std;
struct node {
	struct node *previous;
	struct node *next;
	int data;
};
struct list {
	node *head;
	node *tail;
};
void create_list(list &l) {
	l.head = l.tail = NULL;
}
node *create_node(int value) {
	node *new_node = new node;
	if (new_node == NULL)exit(1);
	else {
		new_node->data = value;
		new_node->next = new_node->previous = NULL;
		return new_node;
	}
}
void add_head(list &l, node *add) {
	if (l.head == NULL) {
		l.head = add;
		l.tail = l.head;
	}
	else {
		add->next = l.head;
		l.head->previous = add;
		l.head = add;
	}
}
void add_tail(list &l, node *add) {
	if (l.head == NULL) {
		l.head = l.tail = add;
	}
	else {
		add->previous = l.tail;
		l.tail->next = add;
		l.tail = add;
	}
}
// first, we need to get node_after_target
// then, if memory is available or list is not empty:
// - add_next -> node_after_target
// - add_previous -> target
// - target_next -> add
// - if node_after_target is not NULL or target is not tail:
//  + node_after_target_'s_previous -> add
// - if node_after_target is NULL or target is tail
// 	+ tail -> add
// else:
// - list is empty: add_head
void add_after(list &l, node *target, node *add) {
	node *after_target = target->next;
	if (target != NULL) {
		add->next = after_target;
		add->previous = target;
		target->next = add;
		if (after_target != NULL) after_target->previous = add;
		if (target == l.tail) l.tail = add;
	}
	else add_head(l, add);
}
// similar with add_after
void add_before(list &l, node *target, node *add) {
	node *before_target = target->previous;
	if (target != NULL) {
		add->next = target;
		add->previous = before_target;
		target->previous = add;
		if (before_target != NULL) before_target->next = add;
		if (target == l.head) l.head = add;
	}
	else {
		add_tail(l, add);
	}
}

void remove_head(list &l) {
	node *temp;
	if (l.head != NULL) {
		temp = l.head;
		l.head = l.head->next;
		l.head->previous = NULL;
		delete temp;
		if (l.head == NULL) l.tail = l.head = NULL;
	}
}

void remove_tail(list &l) {
	node *temp;
	if (l.head != NULL) {
		temp = l.tail;
		l.tail = l.tail->previous;
		l.tail->next = NULL;
		delete temp;
		if (l.tail == NULL) l.tail = l.head = NULL;
	}
}
//first, create a temporatory
//then, check if target exists:
//- temp -> target_next
//- check if memory is available:
//	+ temp_next -> target_next
//	+ check if temp is tail: tail -> target
//	+ else: temp_next_previous -> target (target_next_next)
//	+ delete temp
//else: (target does not exist or only one node)
//- remove_head (inside function remove_head() we also check if list is empty or not)
void remove_after(list &l, node *target) {
	node *temp;
	if (target != NULL) {
		temp = target->next;
		if (temp != NULL) {
			target->next = temp->next;
			if (temp == l.tail) l.tail = target;
			else temp->next->previous = target;
			delete temp;
		}
	}
}

void remove_before(list &l, node *target) {
	node *temp;
	if (target != NULL) {
		temp = target->previous;
		if (temp != NULL) {
			target->previous = temp->previous;
			if (temp == l.head) l.head = target;
			else temp->previous->next = target;
			delete temp;
		}
	}
}
//This must break the loop or gonna be "exeption thrown"!
void remove_node(list &l, node *target) {
	node *temp;
	if (target != NULL) {
		temp = target;
		if (temp->previous == NULL) {
			remove_head(l);
		}
		else if (temp->next == NULL) {
			remove_tail(l);
		}
		else {
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			/*cout <<" <"<< temp->next->data<<"> ";
			cout <<" <"<< temp->previous->data<<"> ";*/
			temp->next = temp->previous = NULL;
			delete temp;
		}
	}
}
int main()
{
	list l;
	create_list(l);
	for (int i = 0; i<10; i++) {
		node *p = create_node(i);
		add_tail(l, p);
	}
	for (node *p = l.head; p != NULL; p = p->next) {
		cout << p->data << " ";
	}
	for (node *p = l.head; p != NULL; p = p->next) {
		if (p->data == 8) remove_after(l, p);
		if (p->data == 1) remove_before(l, p);
		/*if (p->data == 0) { 
			remove_node(l, p);
			break;
		}*/
	}
	//remove_node(l, l.tail);
	//remove_node2(l, l.head); 
	cout << endl;
	for (node *p = l.head; p != NULL; p = p->next) {
		cout << p->data << " ";
	}
	/*remove_head(l);
	remove_tail(l);
	node *x = create_node(100);
	node *y = create_node(500);
	add_head(l,x);
	add_tail(l,y);
	for(node *p = l.head;p!=NULL;p=p->next){
	if(p->data == 5) {
	node *x = create_node(999);
	add_after(l,p,x);
	}
	}
	cout<<endl;
	for(node *p = l.head;p!=NULL;p=p->next){
	cout<< p->data <<" ";
	}
	cout<<endl;*/
	system("pause");
	return 0;
}
