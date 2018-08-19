#include <iostream>
using namespace std;
void delete_max(int *a, int &n) {
	int m = a[n - 1], i = 0;
	while (i<n) {
		if (a[i] == m) {
			for (int j = i; j < n - 1; j++) a[j] = a[j + 1];
			n--; i = 0;
		}
		i++;
	}
}
void add(int *a, int &n, int input) {
	int k, i;
	for (i = n - 1; i >= 0; i--) if (input > a[i]) break;
	k= i + 1;
	for (i = n; i >= k; i--) a[i] = a[i - 1];
	a[k] = input;
	n++;
}
int main(){
	int input;
	int n = 0;
	int a[100000];
	do {
		cin >> input;
		if (input == -1) delete_max(a, n);
		if (input == -2) {
			cout << n << endl;
			for (int i = n - 1; i >= 0; i--) cout << a[i] << endl;
			break;
		}
		if (input >=0 && n < 100000) add(a, n, input);
	} while (input);
	system("pause");
	return 0;
}

