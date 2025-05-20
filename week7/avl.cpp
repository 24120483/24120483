#include <iostream>
using namespace std;

struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};

NODE* createNode(int data) {
	NODE* p = new NODE;
	p->key = data;
	p->height = 0;
	p->p_left = NULL;
	p->p_right = NULL;
	return p;
}
int getHeight(NODE* node) {
	if (node == NULL) {
		return -1;
	}
	else {
		return node->height;
	}
}
int getBalance(NODE* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		int leftHeight = getHeight(node->p_left);
		int rightHeight = getHeight(node->p_right);
		return leftHeight - rightHeight;
	}
}
void updateHeight(NODE* node) {
	int leftHeight = getHeight(node->p_left);
	int rightHeight = getHeight(node->p_right);
	node->height = 1 + max(leftHeight, rightHeight);
}
NODE* rotateRight(NODE* y) {
	NODE* x = y->p_left;
	NODE* T2 = x->p_right;

	x->p_right = y;
	y->p_left = T2;

	updateHeight(y);
	updateHeight(x);

	return x;
}

NODE* rotateLeft(NODE* x) {
	NODE* y = x->p_right;
	NODE* T2 = y->p_left;

	y->p_left = x;
	x->p_right = T2;

	updateHeight(x);
	updateHeight(y);

	return y;
}

void Insert(NODE*& pRoot, int data) {
	if (pRoot == NULL) {
		pRoot = createNode(data);
		return;
	}
	if (data == pRoot->key) return;
	if (data < pRoot->key)
		Insert(pRoot->p_left, data);
	else
		Insert(pRoot->p_right, data);
	updateHeight(pRoot);
	int balance = getBalance(pRoot);
	if (balance > 1 && data < pRoot->p_left->key)
		pRoot = rotateRight(pRoot);
	else if (balance < -1 && data > pRoot->p_right->key)
		pRoot = rotateLeft(pRoot);
	else if (balance > 1 && data > pRoot->p_left->key) {
		pRoot->p_left = rotateLeft(pRoot->p_left);
		pRoot = rotateRight(pRoot);
	}
	else if (balance < -1 && data < pRoot->p_right->key) {
		pRoot->p_right = rotateRight(pRoot->p_right);
		pRoot = rotateLeft(pRoot);
	}
}

NODE* findMin(NODE* node) {
	NODE* current = node;
	while (current->p_left != NULL) {
		current = current->p_left;
	}
	return current;
}
void Remove(NODE*& pRoot, int x) {
	if (pRoot == NULL) {
		return;
	}
	if (x < pRoot->key) {
		Remove(pRoot->p_left, x);
	}
	else if (x > pRoot->key) {
		Remove(pRoot->p_right, x);
	}
	else {
		if (pRoot->p_left == NULL && pRoot->p_right == NULL) {
			delete pRoot;
			pRoot = NULL;
		}
		else if (pRoot->p_left == NULL) {
			NODE* temp = pRoot->p_right;
			delete pRoot;
			pRoot = temp;
		}
		else if (pRoot->p_right == NULL) {
			NODE* temp = pRoot->p_left;
			delete pRoot;
			pRoot = temp;
		}
		else {
			NODE* temp = findMin(pRoot->p_right);
			pRoot->key = temp->key;
			Remove(pRoot->p_right, temp->key);
		}
	}
	if (pRoot == NULL) {
		return;
	}
	updateHeight(pRoot);
	int balance = getBalance(pRoot);
	if (balance > 1 && getBalance(pRoot->p_left) >= 0) {
		pRoot = rotateRight(pRoot);
	}
	else if (balance > 1 && getBalance(pRoot->p_left) < 0) {
		pRoot->p_left = rotateLeft(pRoot->p_left);
		pRoot = rotateRight(pRoot);
	}
	else if (balance < -1 && getBalance(pRoot->p_right) <= 0) {
		pRoot = rotateLeft(pRoot);
	}
	else if (balance < -1 && getBalance(pRoot->p_right) > 0) {
		pRoot->p_right = rotateRight(pRoot->p_right);
		pRoot = rotateLeft(pRoot);
	}
}

bool isAVL(NODE* pRoot) {
	if (pRoot == NULL) {
		return true;
	}
	bool isLeftAVL = isAVL(pRoot->p_left);
	bool isRightAVL = isAVL(pRoot->p_right);
	if (!isLeftAVL || !isRightAVL) {
		return false;
	}
	int leftHeight = getHeight(pRoot->p_left);
	int rightHeight = getHeight(pRoot->p_right);
	int balance = leftHeight - rightHeight;
	if (balance > 1 || balance < -1) {
		return false;
	}
	return true;
}