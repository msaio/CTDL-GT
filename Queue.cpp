#include<iostream>
using namespace std;

struct node {
	int data;
	node *next;
};
struct queue {
	node *top;
	node *tail;
};
node * create_node(int v) {
	node *t = new node;
	t->data = v;
	t->next = NULL;
	return t;
}
void create_queue(queue &q) {
	q.top = q.tail = NULL;
}
int check(queue &q) {
	if (q.top == NULL) return 0;
	return 1;
}
void enqueue(queue &q, node *x) {
	int c = check(q);
	if (c == 0) q.top = q.tail = x;
	else {
		q.tail->next = x;
		q.tail = x;
	}
}
int dequeue(queue &q) {
	int c = check(q);
	if (c != 0) {
		node *t = q.top;
		int x = t->data;
		q.top = q.top->next;
		if (q.top == NULL) q.tail = NULL;
		delete t;
		return x;
	}
	return -1;
}

int main() {
	queue q;
	create_queue(q);
	node *x = create_node(10);
	node *y = create_node(100);
	node *z = create_node(1000);
	enqueue(q, x);
	enqueue(q, y);
	enqueue(q, z);
	int k = dequeue(q);
	cout << k << endl;
	k = dequeue(q);
	cout << k << endl;
	k = dequeue(q);
	cout << k << endl;
	k = dequeue(q);
	cout << k << endl;
	system("pause");
	return 0;
}