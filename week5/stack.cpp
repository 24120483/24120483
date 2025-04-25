#include <iostream>
#include <fstream>
using namespace std;

struct NODE {
	int key;
	NODE* p_next;
};

struct Stack {
	NODE* top;
};
Stack* initializeStack() {
	Stack* s = new Stack;
	s->top = nullptr;
	return s;
}
void push(Stack* s, int key) {
	NODE* p = new NODE;
	p->key = key;
	p->p_next = nullptr;
	p->p_next = s->top;
	s->top = p;
}
int pop(Stack* s) {
	if (s->top != nullptr) {
		NODE* temp = s->top;
		s->top = s->top->p_next;
		return temp->key;
	}
	return -1;
}
int size(Stack* s) {
	if (s->top != nullptr) {
		int dem = 0;
		for (NODE* p = s->top; p != nullptr; p = p->p_next) {
			dem++;
		}
		return dem;
	}
	return 0;
}
bool isEmpty(Stack* s) {
	if (s->top == nullptr) return true;
	return false;
}
int main() {
	ifstream file1("input.txt");
	if (!file1) {
		cout << "khong the mo file de doc" << endl;
		return 1;
	}
	ofstream file2("output.txt");
	if (!file2) {
		cout << "khong the mo file de ghi" << endl;
		return 1;
	}
	string n;
	Stack* s = nullptr;
	while (file1 >> n) {
		if (n == "init") {
			s = initializeStack();
			file2 << "EMPTY" << endl;
		}
		else if (n == "push") {
			int data;
			file1 >> data;
			if (s != nullptr) {
				push(s, data);
				for (NODE* p = s->top; p != nullptr; p = p->p_next) {
					file2 << p->key << " ";
				}
				file2 << endl;
			}
		}
		else if (n == "pop") {
			int temp = pop(s);
			if (isEmpty(s)) {
				file2 << "EMPTY" << endl;
			}
			else {
				for (NODE* p = s->top; p != nullptr; p = p->p_next) {
					file2 << p->key << " ";
				}
				file2 << endl;
			}
		}
	}
	file1.close();
	file2.close();
	return 0;
}