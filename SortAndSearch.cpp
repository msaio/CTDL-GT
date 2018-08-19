#include<iostream>
using namespace std;

int find_min(int x, int y)
{
	return (x > y) ? y : x;
}

int Linear_Search(int *a, int n, int item)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == item) return i;
	}
	return -1;
}
//Only For Sorted Array
int Binary_Search(int *a, int begin, int end, int item)
{
	// n: numberOfElements; begin=n-1; end = 0;
	if (end >= begin)
	{
		int mid = begin + (end - begin) / 2;
		if (a[mid] == item)
		{
			return mid;
		}
		//recursive the right
		if (a[mid] < item)
		{
			return Binary_Search(a, mid + 1, end, item);
		}
		//recursive the left
		return Binary_Search(a, begin, mid - 1, item);
	}
	return -1;
}
int Binary_Search2(int *a, int n, int x)
{
	if (n > 0)
	{
		int begin = 0;
		int end = n - 1;
		int mid = begin + (end - begin) / 2;
		int output = Binary_Search(a, begin, end, x);
		return output;
	}
	return NULL;
}
//Only For Sorted Array
int Jump_Search(int *a, int n, int item)
{
	//find block size to jump
	int step = sqrt(n);
	//find the block that contains the element's value;
	int prev = 0;
	while (a[find_min(step, n) - 1] < item)
	{
		prev = step;
		step += sqrt(item);
		if (prev >= n) return -1;
	}
	//Do a linear search for item in block which start with prev from above
	while (a[prev] < item)
	{
		prev++;
		//Reached the end of block without finding the element's value
		if (prev == find_min(step, n)) return -1;
	}
	//Found in the block
	if (a[prev] == item) return prev;

	return -1;
}

int min(int x, int y)
{
	return (x > y) ? y : x;
}
void interchange_sort(int *a, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] > a[j])swap(a[i], a[j]);
		}
	}
}
//Selection Sort - Get_Min_Value
void Selection_Sort(int *a, int n)
{
	int minimum, i, j;
	for (i = 0; i < n - 1; i++)
	{
		minimum = a[i];
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < minimum)
			{
				minimum = a[j];
				swap(a[i], a[j]);
			}
		}
	}
}
//Another Type Of Selection Sort - Get_Min_Id
void SlSort(int *a, int n)
{
	int min_id;
	for (int i = 0; i < n - 1; i++)
	{
		min_id = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_id])min_id = j;
		swap(a[i], a[min_id]);
	}
}
//Another Type Of Selection Sort - Get_Max_Value
void SlSort1(int *a, int n)
{
	int max, i, j;
	for (i = n - 1; i > 0; i--)
	{
		max = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] > max)
			{
				max = a[j];
				swap(a[j], a[i]);
			}
		}
	}
}
//Another Type Of Selection Sort - Get_Max_Id
void SlSort2(int *a, int n)
{
	int max_id;
	for (int i = n - 1; i > 0; i--)
	{
		max_id = i;
		for (int j = i - 1; j >= 0l; j--)
		{
			if (a[j] > a[max_id])max_id = j;
		}
		swap(a[i], a[max_id]);
	}
}
//Bubble Sort - bigger elements keep move to right
void Bubble_Sort(int *a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		// the biggest element will be moved to position i
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}
//Another type of Bubble Sort - smaller elements keep move to left
void BbSort(int *a, int n)
{
	int i, j;
	for (i = n - 1; i >= 0; i--)
	{
		for (j = n - 1; j > n - 1 - i; j--)
		{
			if (a[j] < a[j - 1])swap(a[j], a[j - 1]);
		}
	}
}
//Another type of Bubble Sort - the biggest moves to end
void BbSort1(int *a, int n)
{
	int i, j;
	for (i = n - 1; i >= 0; i--)
	{
		//Move the biggest element to the end of array
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])swap(a[j], a[j + 1]);
		}
	}
}
//Another type of Bubble Sort - the smallest moves to begining
void BbSort2(int *a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		//Move the smallest element to the begin of array
		for (j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])swap(a[j], a[j - 1]);
		}
	}
}
//Another type of Bubble Sort - Recursive Bubble Sort
void Recursive_BbSort(int *a, int n)
{
	//Stopping case
	if (n == 1)return;
	//Move the biggest to the end of array
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])swap(a[i], a[i + 1]);
	}
	Recursive_BbSort(a, n - 1);
}
//Another type of Bubble Sort - Another Recursive Bubble Sort
void Recursive_BbSort1(int *a, int begin, int n)
{
	//Stopping case
	if (begin == n)return;
	//Move the smallest to the begin of array
	for (int i = n - 1; i > begin; i--)
	{
		if (a[i] < a[i - 1])swap(a[i], a[i - 1]);
	}
	Recursive_BbSort1(a, begin + 1, n - 1);
}
//Insertion Sort
void Insertion_Sort(int *a, int n)
{
	int t, j;
	for (int i = 1; i < n; i++)
	{
		//Find place to insert element a[i]
		j = i - 1;
		t = a[i];
		while (a[j] > t && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
}
//Insertion Sort With 2 for-loops
void InsSort(int *a, int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		//find place to insert element a[i]
		temp = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] < temp)break;
			else  a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}
//Another type of.... no this is just a combination of Insert Sort and Bubble Sort
void InsSort1(int *a, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		//From i 's position, move smallest element to the begin
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] < a[j - 1])swap(a[j], a[j - 1]);
			else break;
		}
	}
}
//Recursive Insertion Sort
void Recursive_InsSort(int *a, int n)
{
	//Stopping case (base case)
	if (n <= 1)return;

	Recursive_InsSort(a, n - 1);
	int last = a[n - 1];
	int j = n - 2;
	while (j >= 0 && a[j] > last)
	{
		a[j + 1] = a[j];
		j--;
	}
	a[j + 1] = last;
}
//Merge Sort (Using Recursive)
//Merge Sort is a Divide and Conquer Algorithms
//Merge two subarrays of a[]
//First Subarray is array[begin -> middle]
//Second Subarray is array[middle+1 -> end] 
void Merge(int *a, int begin, int middle, int end)
{
	int i, j, k;
	int n1 = middle - begin + 1;//n1: number of elements in subarray left 
	int n2 = end - middle;//n2: number of elements in subarray right
						  //Create 2 temporary arrays
	int *L = new int[n1];
	int *R = new int[n2];
	//Copy data to temporary arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = a[begin + i];
	for (j = 0; j < n2; j++)
		R[j] = a[middle + 1 + j];
	/*Merge the temporary arrays back into a[]*/
	i = 0; j = 0; k = begin;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	// Not all couples of subarrays are equal so some elements remains, then we gotta copy all remaining elements
	while (i < n1)
	{
		a[k] = L[i]; i++; k++;
	}
	while (j < n2)
	{
		a[k] = R[j]; j++; k++;
	}
}
void Merge_Sort(int *a, int begin, int end)
{
	if (end > begin)
	{
		//First Split
		int middle = (begin + end) / 2;
		//Then Sort And Merge
		Merge_Sort(a, begin, middle);
		Merge_Sort(a, middle + 1, end);
		Merge(a, begin, middle, end);
	}
}
//Iterative Merge Sort (No recursive, only loop)
void Merge_Sort_Iterative(int *a, int n)
{
	int current_size;
	int left_start;
	//The current size begins with 1 then multiply x2: 1 -> 2 -> 4 -> 8 -> ... -> k ,stop when k*2 >= n-1 
	for (current_size = 1; current_size <= n - 1; current_size = 2 * current_size)
	{
		for (left_start = 0; left_start < n - 1; left_start += 2 * current_size)
		{
			int middle = left_start + current_size - 1;
			int right_end = min(left_start + 2 * current_size - 1, n - 1);
			Merge(a, left_start, middle, right_end);
		}
	}
}
//Quick Sort
//Quick Sort is a Divide and Conquer Algorithms
int* two_and_1_element_to_one(int *arr1, int noOfarr1, int *arr2, int noOfarr2, int x)
{
	int *temp = new int[noOfarr1 + noOfarr2];
	int i, j, k = 0;
	for (i = 0; i < noOfarr1; i++)
	{
		temp[k] = arr1[i];
		k++;
	}
	temp[k] = x;
	k++;
	for (j = 0; j < noOfarr2; j++)
	{
		temp[k] = arr2[j];
		k++;
	}
	return temp;
}
int MovePivotToRightPlace(int *a, int begin, int end)
{
	int Pivot = a[end];
	int i = begin - 1;
	for (int j = begin; j <= end - 1; j++)
	{
		if (a[j] <= Pivot)
		{
			i++;
			swap(a[i], a[j]);	
		}
	}
	swap(a[i + 1], a[end]);
	int PositionOfPivot = i + 1;
	return PositionOfPivot;
}
//Using Recursive
void Quick_Sort(int *a, int begin, int end)
{
	if (begin < end)
	{
		int x = MovePivotToRightPlace(a, begin, end);
		Quick_Sort(a, begin, x - 1);
		Quick_Sort(a, x + 1, end);
	}
}
//Using Loop
void Quick_Sort_Iterative(int *a, int begin, int end)
{
	// Create an auxiliary stack

	int *stack = new int[end - begin + 1];
	/*int range_of_stack = end - begin + 1;
	int stack[range_of_stack]; */

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[++top] = begin;
	stack[++top] = end;

	// Keep popping from stack while is not empty
	while (top >= 0)
	{
		// Pop h and l
		end = stack[top--];
		begin = stack[top--];

		// Set pivot element at its correct position
		// in sorted array
		int p = MovePivotToRightPlace(a, begin, end);

		// If there are elements on left side of pivot,
		// then push left side to stack
		if (p - 1 > begin)
		{
			stack[++top] = begin;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot,
		// then push right side to stack
		if (p + 1 < end)
		{
			stack[++top] = p + 1;
			stack[++top] = end;
		}
	}
}
//Heap Sort
//Technique based on Binary Heap data structure
void Heapfy(int *a, int n, int i)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<n && a[left]>a[max])
	{
		max = left;
	}
	if (right<n && a[right]>a[max])
	{
		max = right;
	}
	if (max != i)
	{
		swap(a[i], a[max]);
		Heapfy(a, n, max);
	}
}
void Heap_Sort(int *a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapfy(a, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		Heapfy(a, i, 0);
	}
}
//Shell Sort
void Shell_Sort(int *a, int n)
{
	//Start with range n/2 then keep dividing 2
	for (int range = n / 2; range>0; range /= 2)
	{
		for (int i = range; i<n; i++)
		{
			//from position 'range'
			int temporary = a[i];
			int j = i;
			while (j >= range && a[j - range]>temporary)
			{
				a[j] = a[j - range];
				j -= range;
			}
			a[j] = temporary;
		}
	}
}
//Radix Sort
void Radix_Sort(int *a, int n)
{
	//get max
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)max = a[i];
	}
	int exp;
	for ( exp = 1; max / exp > 0; exp *= 10) {
		int *output = new int[n]; // output array
		int i, count[10] = { 0 };
		// Store count of occurrences in count[]
		for (i = 0; i < n; i++)
			count[(a[i] / exp) % 10]++;
		// Change count[i] so that count[i] now contains actual
		//  position of this digit in output[]
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		// Build the output array
		for (i = n - 1; i >= 0; i--)
		{
			output[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
		}

		/*i = n - 1;
		while (i != 0) {
			output[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
			i--;
		}*/

		// Copy the output array to arr[], so that arr[] now
		// contains sorted numbers according to current digit
		for (i = 0; i < n; i++)
			a[i] = output[i];
	}	
}
//
void radix_sort2(int *a, int n)
{
	int max = a[0];
	int i = 1;
	while (i - n != 0) {
		max = ((max + a[i]) + abs(max - a[i])) / 2;
		i++;
	}
	int exp = 1;
	while ((max / exp) != 0) {
		int *output = new int[n];
		int i;
		int count[10] = { 0 };
		i = 0;
		while (i - n != 0) {
			count[(a[i] / exp) % 10]++;
			i++;
		}
		i = 1;
		while (i - 10 != 0) {
			count[i] += count[i - 1];
			i++;
		}
		i = n - 1;
		while (i != -1) {
			output[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
			i--;
		}
		i = 0;
		while (i - n != 0) {
			a[i] = output[i];
			i++;
		}
		exp *= 10;
	}
}
//
void swap(long *a, long i, long j, long n) {
	if (j >= n)return;
	if (a[i] > a[j]) {
		long c = a[i];
		a[i] = a[j];
		a[j] = c;
	}
	swap(a, i + 1, j + 1, n);
}
void sort(long *a, long n) {
	if (n == 0)return;
	swap(a, 0, 1, n);
	sort(a, n - 1);
}
//
void sort2(int *a, int i, int j, int n){
	if (i<n){
		if (j<n - i - 1){
			if (a[j]>a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		else{
			j = 0;
			++i;
		}
		sort2(a, i, ++j, n);
	}
}
//
int * sortxxx(int *p, int i, int j, int n){
	if (i<n){
		if (j<n - i - 1){
			if (p[j]>p[j + 1]){
				int t = p[j];
				p[j] = p[j + 1];
				p[j + 1] = t;
			}
		}
		else{
			j = 0;
			++i;
		}
		p = sortxxx(p, i, ++j, n);
	}
	return p;
}
//
void InnerLoop(int *values, int& min, int j,int n)
{
	if (j != n)
	{
		if (values[min] > values[j])
		{
			min = j;
		}
		InnerLoop(values, min, j + 1,n);
	}
}
void OuterLoop(int *values, int i,int n)
{
	int min = i;
	int tempVal = 0;
	if (i != n)
	{
		int j = i;
		InnerLoop(values, min, j, n);
		tempVal = values[i];
		values[i] = values[min];
		values[min] = tempVal;
		OuterLoop(values, i + 1,n);
	}
}
//
void bubblesort(int *arrayf, int size)
{
	int temp;
	int i = 0;
	arrayf[size];
	bool swapped = false;
	if (arrayf[i]>arrayf[i + 1])
	{
		swapped = true;
		temp = arrayf[i];
		arrayf[i] = arrayf[i + 1];
		arrayf[i + 1] = temp;
		bubblesort(arrayf, 0);
		cout << arrayf[i];
	}
	else {
		if (arrayf[i]>arrayf[size - 1])
		{
			bubblesort(arrayf, size--);
		}
	}
}
int main(void)
{
	int a[10] = { 5,8,13,2,1,4,7,0,3,5 };
	//int a[10] = { 0,0,8,7,6,5,4,3,2,0 };
	
	/*cout << output << endl;
	int max = a[0];
	for (int i = 1; i < 10; i++)
	{
		if (a[i] > max)max = a[i];
	}
	int max2 = a[0];
	for (int i = 1; i < 10; i++)
	{
		max2 = (max2 < a[i]) ? a[i] : max2;
	}
	cout << max << endl;
	cout << max2 << endl;*/
	int n = 10, i, j = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	/*OuterLoop(a, j, n);*/
	//Radix_Sort(a, n);
	interchange_sort(a, 10);
	cout << endl;
	for (i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}
   