#include <iostream>
using namespace std;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3daccd4 (week2)

int sorted(int* arr, int n) {
	if (n == 0 || n == 1) {		//khi mang co 0 hoac 1 phan tu thi luon dung
		return 1;
	}
	if (arr[n - 1] < arr[n - 2]) {		//neu phan tu cuoi cung cua mang nho hon phan tu truoc do thi sai
		return 0;
	}
	return sorted(arr, n - 1);		//goi de quy ham voi n-1 phan tu con lai
}
int main() {
	int n;
<<<<<<< HEAD
=======
=======
int minSubArrayLen(int a[], int target, int n) {
	int left = 0;
	int sum = 0;
	int minlength = n + 1;
	for (int right = 0; right < n; right++) {
		sum += a[right];
		while (sum >= target) {
			if ((right - left + 1) < minlength) {
				minlength = right - left + 1;
			}
			sum -= a[left];
			left++;
		}
	}
	if (minlength == n + 1) {
		return 0;
	}
	return minlength;
}
int main() {
	int n, target;
>>>>>>> 610f03f (week2)
>>>>>>> 3daccd4 (week2)
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3daccd4 (week2)
	if (sorted(a, n)) {
		cout << "mang da duoc sap xep tang dan";
	}
	else {
		cout << "mang khong duoc sap xep tang dan";
	}
	return 0;
<<<<<<< HEAD
}
=======
}
=======
	cout << "target =";
	cin >> target;
	cout << minSubArrayLen(a, target, n);
	return 0;
}
>>>>>>> 610f03f (week2)
>>>>>>> 3daccd4 (week2)
