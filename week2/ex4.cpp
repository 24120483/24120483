#include <iostream>
using namespace std;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3daccd4 (week2)

void TowersofHanoi(int n, char from, char to, char temp) {
	if (n == 1) {
		cout << "chuyen dia 1 tu " << from << " den " << to << endl;	//khi co 1 dia duy nhat thi chuyen dia do den cot dich
		return;
	}
	TowersofHanoi(n - 1, from, temp, to);	//khi so dia lon hon 1 thi ta dung de quy den chuyen n-1 dia phia tren sang cot trung gian
	cout << "chuyen dia " << n << " tu " << from << " den " << to << endl;	//sau khi chuyen n-1 dai sang cot trung gian thi chuyen dia cuoi cung sang cot dich
	TowersofHanoi(n - 1, temp, to, from);	//goi de quy de chuyen n-1 dia con lai de n-1 dia chuyen tu cot trung gian sang cot dich
}
int main() {
	int n;
	cin >> n;
	TowersofHanoi(n, 'A', 'C', 'B');
<<<<<<< HEAD
=======
=======
int canShipInDays(int a[], int n, int days, int mid) {	//ham kiem tra xem trong luong cua tau la mid thi co van chuyen duoc so hang do trong days khong
	int dayCount = 1;	//bat dau tu ngay dau tien
	int currenWeight = 0;	
	for (int i = 0; i < n; i++) {
		if (currenWeight + a[i] > mid) {	
			dayCount++;					//chuyen sang ngay tiep theo
			currenWeight = a[i];		//dat khoi luong kien hang nay la khoi luong dau tien trong ngay
			if (dayCount > days) {
				return 0;		//so ngay vuot qua days thi la sai
			}
		}
		else {
			currenWeight += a[i];
		}
	}
	return 1;
}
int shipWithinDays(int a[], int n, int days) {		//ham tim trong luong toi thieu cua tau de co the chuyen so kien hang nay trong days ngay
	int left = a[n - 1];			//kien hang co khoi luong lon nhat
	int right = 0;
	for (int i = 0; i < n; i++) {
		right += a[i];				//tinh tong khoi luong cac kien hang
	}
	while (left < right) {		//dung ki thuat binary search 
		int mid = left + (right - left) / 2;
		if (canShipInDays(a, n, days, mid)) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}
int main() {
	int n, days;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "days =";
	cin >> days;
	cout << shipWithinDays(a, n, days);
>>>>>>> 610f03f (week2)
>>>>>>> 3daccd4 (week2)
	return 0;
}