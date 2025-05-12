#include <iostream>
using namespace std;

void generateBinaryStrings(int n, string str) {
    if (n == 0) {
        cout << str << endl;        //do dai chuoi n=0 thi in ra chuoi
        return;
    }
    generateBinaryStrings(n - 1, str + '0');    // do dai chuoi khac 0 thi them '0' vao chuoi va de quy phan con lai cua chuoi
    generateBinaryStrings(n - 1, str + '1');    // do dai chuoi khac 0 thi them '1' vao chuoi va de quy phan con lai cua chuoi
}

