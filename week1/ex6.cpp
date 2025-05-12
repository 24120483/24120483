#include <iostream>
using namespace std;

int kientravitri(int* arr, int hang, int cot) {	//ham kiem tra Hau co the dat o vi tri (hang,cot) nay khong
	for (int i = 0; i < hang; i++) {
		if (arr[i] == cot || abs(arr[i] - cot) == abs(i - hang)) {	// kiem tra vi tri nay co nam tren hang hoac duong cheo nao cua cac con hau hang phia tren khong
			return 0;
		}
	}
	return 1;
}
void sapxephau(int* arr, int n, int hang) {
	if (n == hang) {						//khi tim duoc vi tri tat ca con hau thi in ra vi tri cua no
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i] == j) {
					cout << "Q ";
				}
				else {
					cout << ". ";
				}
			}
			cout << endl;
		}
		cout << "---------------------------------" << endl;
		return;
	}
	
	for (int cot = 0; cot < n; cot++) {		
		if (kientravitri(arr, hang, cot)) {	//tim vi tri con hau co the dung trong hang nay
			arr[hang] = cot;
			sapxephau(arr, n, hang +1);		//goi ham de quy de tim vi tri con hau cho hang tiep theo
			arr[hang] = -1;					//sau khi thuc hien ham de quy phia tren ,ta cho xoa vi tri con hau nay de tim xem co vi tri nao con hay co the dung nua khong
		}
	}
}
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = -1;
	}
	sapxephau(a, n, 0);
	delete a;
	return 0;

}