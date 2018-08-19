#include <iostream>
using namespace std;
void swap(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}
void heap(int *a, int n, int i, int &m){
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[left] > a[max]){
		max = left;
	}
	if (right < n && a[right] > a[max]){
		max = right;
	}
	if (max != i){
		swap(a[i], a[max]);
		heap(a, n, max, m);
	}
	m = a[n-1];
}
void delete_max(int *a, int &n, int m){
	int i = 0;
	while(i<n){
		if (a[i] == m){
			for (int j = i; j < n - 1; j++){
				a[j] = a[j + 1];
			}
			n--;
			i = 0;
		}
		i++;
	}
}
void sort(int *a, int n, int &m){
	for (int i = n / 2 - 1; i >= 0; i--)
		heap(a, n, i, m);
	for (int i = n - 1; i >= 0; i--){
		swap(a[0], a[i]);
		heap(a, i, 0, m);
	}
}
int main(){
	int input;
	int n = 0;
	int i;
	int m;
	int *a = new int[n];
	do{
		cin >> input;
		if (input == -1){
			delete_max(a, n, a[n-1]);
		}
		if (input == -2){
			sort(a, n, m);
			cout << n << endl;
			for (int i = n - 1; i >= 0; i--){
				cout << a[i] << endl;
			}
			break;
		}
		if (input >= 0 && n < 100000){
			int *temp7 = a;
			temp7 = new int[n + 1];
			for (i = 0; i < n; i++){
				temp7[i] = a[i];
			}
			temp7[n] = input;
			delete[] a;
			a = temp7;
			a = new int[++n];
			for (i = 0; i < n; i++){
				a[i] = temp7[i];
			}
			delete[] temp7;
			heap(a, n, 0, m);
		}
	} while (input);
	system("pause");
	return 0;
}