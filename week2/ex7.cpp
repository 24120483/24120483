#include  <iostream>
using namespace std;

void SapXepArr(int nums[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
		}
	}
}
void TimBoBa(int nums[], int n) {
	SapXepArr(nums, n);
	int kiemtra = 0;
	cout << "[";
	for (int i = 0; i < n - 2; i++) {
		if (i>0&&nums[i] == nums[i - 1]) continue;
		int left = i + 1;
		int right = n - 1;
		while (left < right) {
			int sum = nums[i] + nums[left] + nums[right];
			if (sum == 0) {
				if (kiemtra) cout << ",";
				kiemtra = 1;
				cout << "[" << nums[i] << "," << nums[left] << "," << nums[right] << "]";
				while (left < right && nums[left] == nums[left + 1]) left++;
				while (left < right && nums[right] == nums[right - 1]) right--;
				left++;
				right--;
			}
			else if (sum < 0) {
				left++;
			}
			else {
				right--;
			}
		}
	}
	if (!kiemtra) cout << "khong tim thay bo ba nao";
	cout << "]" << endl;
}
int main() {
	int n;
	cin >> n;
	int* nums = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	TimBoBa(nums, n);
	return 0;
}