#include <iostream>
#include <fstream>
using namespace std;

struct NODE {
	int key;
	NODE* p_next;
};
struct Queue {
	NODE* p_head;
	NODE* p_tail;
};
Queue* initializeQueue() {
	Queue* q = new Queue;
	q->p_head = nullptr;
	q->p_tail = nullptr;
	return q;
}
void enqueue(Queue* q, int key) {
	NODE* p = new NODE;
	p->key = key;
	p->p_next = nullptr;
	if (q->p_head == nullptr) {
		q->p_head = p;
		q->p_tail = p;
	}
	else {
		q->p_tail->p_next = p;
		q->p_tail = p;
	}
}
int dequeue(Queue* q) {
	if (q->p_head != nullptr) {
		NODE* temp = q->p_head;
		if (q->p_head == q->p_tail) {
			q->p_head = nullptr;
			q->p_tail = nullptr;
		}
		else {
			q->p_head = q->p_head->p_next;
		}
		return temp->key;
	}
	return -1;
}
int size(Queue* q) {
	int dem = 0;
	for (NODE* p = q->p_head; p != nullptr; p = p->p_next) {
		dem++;
	}
	return dem;
}
bool isEmpty(Queue* q) {
	return q->p_head == nullptr;
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
	Queue* q = nullptr;
	while (file1 >> n) {
		if (n == "init") {
			q = initializeQueue();
			file2 << "EMPTY" << endl;
		}
		else if (n == "enqueue") {
			int data;
			file1 >> data;
			if (q != nullptr) {
				enqueue(q, data);
				for (NODE* p = q->p_head; p != nullptr; p = p->p_next) {
					file2 << p->key << " ";
				}
				file2 << endl;
			}
		}
		else if (n == "dequeue") {
			int temp = dequeue(q);
			if (isEmpty(q)) {
				file2 << "EMPTY" << endl;
			}
			else {
				for (NODE* p = q->p_head; p != nullptr; p = p->p_next) {
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