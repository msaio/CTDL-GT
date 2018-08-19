#include<iostream>
using namespace std;

struct n_stack {
	int data;
	n_stack *next;
};

struct stack {
	n_stack *top = NULL;
	n_stack *tail = NULL;
};
n_stack  *create_node(int v) {
	n_stack *x = new n_stack;
	x->data = v;
	x->next = NULL;
	return x;
}
void create_stack(stack &s) {
	s.top = s.tail = NULL;
}
int check(stack &s) {
	return !s.top;
}
void push(stack &s, n_stack *n) {
	if (s.top == NULL) {
		s.top = n;
		s.tail = n;
	}
	else {
		n->next = s.top;
		s.top = n;
	}
}
int pop(stack &s) {
	if (check(s)) return -1;
	else {
		n_stack *t = s.top;
		int popped = t->data;
		s.top = s.top->next;
		if (s.top == NULL) s.tail = NULL;
		delete t;
		return popped;
	}
}
int peek(stack &s) {
	if (check(s)) return -1;
	return s.top->data;
}
int main() {
	stack s;
	create_stack(s);
	n_stack * x = create_node(10);
	n_stack * y = create_node(20);
	n_stack * z = create_node(30);
	push(s, x); push(s, y); push(s, z);
	int top = peek(s);
	int xx = pop(s);
	top = peek(s);
	cout << top << endl;
	cout << xx << endl;
	system("pause");
	return 0;
}



