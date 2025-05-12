#include <iostream>
using namespace std;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3daccd4 (week2)
int fibonacci(int n) {
	if (n <= 1) {
		return n;		//khi n=1 hoac n=0 thi F(0)=0 va F(1)=1
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);	//khi n>1 thi F(n)=F(n-1)+F(n-2)
	}
}

<<<<<<< HEAD
=======
=======
int LinearSearch(int arr[], int n, int k) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == k) {
			return i;
		}
	}
	return -1;
}
int main() {
	int n, k;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;
	cout << LinearSearch(a, n, k);
	delete a;
	return 0;
}
>>>>>>> 610f03f (week2)
>>>>>>> 3daccd4 (week2)
