#include <iostream>
using namespace std;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3daccd4 (week2)

void generateBinaryStrings(int n, string str) {
    if (n == 0) {
        cout << str << endl;        //do dai chuoi n=0 thi in ra chuoi
        return;
    }
    generateBinaryStrings(n - 1, str + '0');    // do dai chuoi khac 0 thi them '0' vao chuoi va de quy phan con lai cua chuoi
    generateBinaryStrings(n - 1, str + '1');    // do dai chuoi khac 0 thi them '1' vao chuoi va de quy phan con lai cua chuoi
}

<<<<<<< HEAD
=======
=======
int TimGTNN(int arr[], int n) {
	int low = 0, high = n - 1;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] >arr[high]) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	cout << arr[low] << endl;
	return low;
}
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = TimGTNN(a, n);
	cout << "Explanation: The original array was [";
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			cout << a[i] << ",";
		}
		else {
			cout << a[i];
		}
	}
	cout << "] rotated " << k << " times." << endl;
	delete a;
	return 0;
}
>>>>>>> 610f03f (week2)
>>>>>>> 3daccd4 (week2)
