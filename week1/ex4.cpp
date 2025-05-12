#include <iostream>
using namespace std;

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
	return 0;
}