#include <iostream>
using namespace std;
struct xxx {
	int a;
	int b;
	char c;
};
struct node {
	int data;
	node *left;
	node *right;
};
typedef node *tree;

node *create_node(int value) {
	node *x = new node;
	x->data = value;
	x->left = NULL;
	x->right = NULL;
	return x;
}
void create_tree(tree &t){
	t = NULL;
}
void insert(tree &t, node *x) {
	if (t == NULL) t = x;
	else if (t->data > x->data) insert(t->left, x);
	else if (t->data < x->data) insert(t->right, x);
	else return;
}
void del(tree &t, int x) {
	if (t == NULL) return;
	if (x < t->data) del(t->left, x);
	else if (x > t->data) del(t->right, x);
	else {
		node *p = t;
		if (!t->left) {
			p = t;
			t = t->right;
			delete p;
		}
		else if (!t->right) {
			p = t;
			t = t->left;
			delete p;
		}
		else {
			node *q = t->right;
			while (q->left) q = q->left;
			t->data = q->data;
			del(t->right, q->data);
		}
	}
}
node *search(tree t, int x) {
	if (t != NULL) {
		if (t->data == x) return t;
		else {
			if (x > t->data)return search(t->right, x);
			else return search(t->left, x);
		}
	}
	return NULL;
}
void LNR(tree t) {
	if (t != NULL) {
		LNR(t->left);
		cout << t->data << " ";
		LNR(t->right);
	}
}
void RNL(tree t) {
	if (t != NULL) {
		RNL(t->right);
		cout << t->data << " ";
		RNL(t->left);
	}
}
void NLR(tree t) {
	if (t != NULL) {
		cout << t->data << " ";
		NLR(t->left);
		NLR(t->right);
	}
}
void del_leaves(tree &t) {
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL) t = NULL;
		else {
			del_leaves(t->left);
			del_leaves(t->right);
		}
	}
}
int height(tree t) {
	if (t == NULL)return 0;
	else {
		int l_h = height(t->left);
		int r_h = height(t->right);
		if (l_h > r_h)return l_h + 1;
		else return r_h + 1;
	}
}
void count_leaf(tree t, int &c) {
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL) c++;
		count_leaf(t->left, c);
		count_leaf(t->right, c);
	}
}
void count_node(tree t, int &c) {
	if (t != NULL) {
		c++;
		count_node(t->left, c);
		count_node(t->right, c);
	}
}
void count_nodes_haves_1_node(tree t, int &c) {
	if (t != NULL) {
		if ((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL)) {
			c++;
		}
		count_nodes_haves_1_node(t->left, c);
		count_nodes_haves_1_node(t->right, c);
	}
}
void count_nodes_haves_2_node(tree t, int &c) {
	if (t != NULL) {
		if (t->left != NULL && t->right != NULL) {
			c++;
		}
		count_nodes_haves_2_node(t->left, c);
		count_nodes_haves_2_node(t->right, c);
	}
}
void find_max(tree t, int &m) {
	if (t != NULL) {
		if (t->data > m)m = t->data;
		find_max(t->left, m);
		find_max(t->right, m);
	}
}
int optimal_find_max(tree t) {
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL) return t->data;
		optimal_find_max(t->right);
	}
}
void find_min(tree t, int &m) {
	if (t != NULL) {
		if (t->data < m)m = t->data;
		find_min(t->left, m);
		find_min(t->right, m);
	}
}
int optimal_find_min(tree t) {
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL) return t->data;
		optimal_find_min(t->left);
	}
}
int main() {
	tree t;
	create_tree(t);
	int input;
	do {
		cin >> input;
		if (input != -1) {
			node *a = create_node(input);
			insert(t, a);
		}
		else break;
	} while (true);
	LNR(t);
	int s;
	cout << endl;
	cin >> s;
	node *x = search(t, s);
	if (x == NULL) cout << endl << "deoco" << endl;
	else {
		cout << endl << "co!" << endl;
		del(t, s);
	}
	LNR(t);
	NLR(t);
	//del_leaves(t);
	//int h = height(t);
	//cout << endl << h << endl;
	//cout << endl;
	//int cl = 0;
	//count_leaf(t, cl);
	//cout << "count leaf = " << cl << endl;
	////LNR(t);
	//int m = -1;
	////find_max(t, m);
	//m = optimal_find_max(t);
	//cout << "max: " << m << endl;
	//m = t->data;
	////find_min(t, m);
	//m = optimal_find_min(t);
	//cout << "min: " << m << endl;
	//int c1n = 0;
	//count_nodes_haves_1_node(t, c1n);
	//cout << "number of nodes have 1 node: " << c1n << endl;
	//int c2n = 0;
	//count_nodes_haves_2_node(t, c2n);
	//cout << "number of nodes have 2 node: " << c2n << endl;
	system("pause");
	return 0;
}







