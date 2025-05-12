#include <iostream>
using namespace std;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3daccd4 (week2)

int factorial(int n) {
	if (n == 0) {
		return 1;		//khi n=0 thi 0!=1
	}
	else {
		return n * factorial(n - 1);	//khi n>0 thi n!=n*(n-1)!
	}
}
<<<<<<< HEAD
=======
=======
int sentinelLinearSearch(int arr[], int n, int k) {
	int temp = arr[n - 1];
	arr[n - 1] = k;
	int i = 0;
	while (arr[i] != k) {
		i++;
	}
	arr[n - 1] = temp;
	if (i < n - 1 || arr[n - 1] == k) {
		return i;
	}
	else return -1;
}
int main() {
	int n, k;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;
	cout << sentinelLinearSearch(a, n, k);
	delete a;
	return 0;
}
>>>>>>> 610f03f (week2)
>>>>>>> 3daccd4 (week2)
