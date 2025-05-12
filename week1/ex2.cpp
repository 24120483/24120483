#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 0) {
		return 1;		//khi n=0 thi 0!=1
	}
	else {
		return n * factorial(n - 1);	//khi n>0 thi n!=n*(n-1)!
	}
}
