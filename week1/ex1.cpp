#include <iostream>
using namespace std;

int fibonacci(int n) {
	if (n <= 1) {
		return n;		//khi n=1 hoac n=0 thi F(0)=0 va F(1)=1
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);	//khi n>1 thi F(n)=F(n-1)+F(n-2)
	}
}

