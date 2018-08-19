#include<iostream>
#include<stack>
using namespace std;

void showstack(stack <int> gq) {
	stack <int> g = gq;	
	while (!g.empty()) {
		cout << '\t' << g.top();
		g.pop();
	}
	cout << endl;
}

int main() {
	stack <int> gquiz;
	gquiz.push(10);
	gquiz.push(30);
	gquiz.push(20);
	gquiz.push(5);
	gquiz.push(1);
	
	cout << "The Stack: ";
	showstack(gquiz);

	cout << endl;
	cout << "Stack's size: " << gquiz.size();
	cout << endl;
	cout << "Stack's top element: " << gquiz.top();

	cout << endl;
	cout << "pop an element in stack: ";
	gquiz.pop();
	showstack(gquiz);
	system("pause");
	return 0;
}



