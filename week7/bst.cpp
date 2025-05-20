#include <iostream>
using namespace std;

struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
};

NODE* Search(NODE* pRoot, int x) {
	while (pRoot) {
		if (pRoot->key == x) {
			return pRoot;
		}
		else if (pRoot->key > x) {
			pRoot = pRoot->p_left;
		}
		else {
			pRoot = pRoot->p_right;
		}
	}
	return NULL;
}

NODE* createNode(int data) {
	NODE* p = new NODE;
	p->key = data;
	p->p_left = NULL;
	p->p_right = NULL;
}

void Insert(NODE*& pRoot, int x) {
	if (!pRoot) {
		pRoot = createNode(x);
		return;
	}
	if (pRoot->key == x) {
		return;
	}
	if (x < pRoot->key) {
		Insert(pRoot->p_left,x);
	}
	if (x > pRoot->key) {
		Insert(pRoot->p_right, x);
	}
}
NODE* maxLeft(NODE* pRoot) {
	NODE* temp = pRoot->p_left;
	while (temp->p_right) {
		temp = temp->p_right;
	}
	return temp;
}

void Remove(NODE*& pRoot, int x) {
	if (!pRoot) return;
	if (x < pRoot->key) {
		Remove(pRoot->p_left, x);
	}
	else if (x > pRoot->key) {
		Remove(pRoot->p_right, x);
	}
	else {
		if (!pRoot->p_left && !pRoot->p_right) {
			delete pRoot;
			pRoot = NULL;
		}
		else if (!pRoot->p_left) {
			NODE* temp = pRoot;
			pRoot = pRoot->p_right;
			delete temp;
		}
		else if (!pRoot->p_right) {
			NODE* temp = pRoot;
			pRoot = pRoot->p_left;
			delete temp;
		}
		else {
			NODE* q = maxLeft(pRoot);
			pRoot->key = q->key;  
			Remove(pRoot->p_left, q->key);  
		}
	}
}

NODE* createTree(int a[], int n) {
	NODE* pRoot = NULL;
	for (int i = 0; i < n; i++) {
		Insert(pRoot, a[i]);
	}
	return pRoot;
}

void removeTree(NODE*& pRoot) {
	if (pRoot) {
		removeTree(pRoot->p_left);   
		removeTree(pRoot->p_right);  
		delete pRoot;                
		pRoot = NULL;                
	}
}

int Height(NODE* pRoot) {
	if (!pRoot) return -1;
	int left = Height(pRoot->p_left);
	int right = Height(pRoot->p_right);
	if (left > right) return 1 + left;
	return 1 + right;
}
int countNode(NODE* pRoot) {
	if (!pRoot) return 0;
	int dem = 0;
	dem++;
	int left = countNode(pRoot->p_left);
	dem += left;
	int right = countNode(pRoot->p_right);
	dem += right;
	return dem;
}
int countLess(NODE* pRoot, int x) {
	if (!pRoot) return 0;
	if (pRoot->key < x) {
		return 1 + countNode(pRoot->p_left) + countLess(pRoot->p_right, x);
	}
	else {
		return countLess(pRoot->p_left, x);
	}
}
int countGreater(NODE* pRoot, int x) {
	if (!pRoot) return 0;
	if (pRoot->key > x) {
		return 1 + countNode(pRoot->p_right) + countGreater(pRoot->p_left, x);
	}
	else {
		return countGreater(pRoot->p_right, x);
	}
}

bool ktra(NODE* pRoot, int min, int max) {
	if (!pRoot) return true;
	if (pRoot->key <= min || pRoot->key >= max) return false;
	return ktra(pRoot->p_left, min, pRoot->key) && ktra(pRoot->p_right, pRoot->key, max);
}
bool isBST(NODE* pRoot) {
	return ktra(pRoot, INT_MIN, INT_MAX);
}

bool isFullBST(NODE* pRoot) {
	if (!pRoot) return true;
	if (!pRoot->p_left && !pRoot->p_right) return true; 
	if (pRoot->p_left && pRoot->p_right) {
		return isFullBST(pRoot->p_left) && isFullBST(pRoot->p_right);
	}
	return false;
}

