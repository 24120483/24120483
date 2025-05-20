#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
};

NODE* createNode(int data) {
	NODE* p = new NODE;
	p->key = data;
	p->p_left = NULL;
	p->p_right = NULL;
	return p;
}

vector<int> NLR(NODE* pRoot) {
	vector<int> v;
	if (pRoot) {
		v.push_back(pRoot->key);
		vector<int> left = NLR(pRoot->p_left);
		v.insert(v.end(), left.begin(), left.end());
		vector<int> right = NLR(pRoot->p_right);
		v.insert(v.end(), right.begin(), right.end());
	}
	return v;
}

vector<int> LNR(NODE* pRoot) {
	vector<int> v;
	if (pRoot) {
		vector<int> left = LNR(pRoot->p_left);
		v.insert(v.end(), left.begin(), left.end());
		v.push_back(pRoot->key);
		vector<int> right = LNR(pRoot->p_right);
		v.insert(v.end(), right.begin(), right.end());
	}
	return v;
}

vector<int> LRN(NODE* pRoot) {
	vector<int> v;
	if (pRoot) {
		vector<int> left = LRN(pRoot->p_left);
		v.insert(v.end(), left.begin(), left.end());
		vector<int> right = LRN(pRoot->p_right);
		v.insert(v.end(), right.begin(), right.end());
		v.push_back(pRoot->key);
	}
	return v;
}

vector<vector<int>> LevelOrder(NODE* pRoot) {
	vector<vector<int>> vv;
	if (pRoot) {
		queue<NODE*> q;
		q.push(pRoot);
		while (!q.empty()) {
			vector<int> v;
			int sl = q.size();
			for (int i = 0; i < sl; i++) {
				NODE* p = q.front();
				v.push_back(p->key);
				q.pop();
				if (p->p_left) q.push(p->p_left);
				if (p->p_right)q.push(p->p_right);
			}
			vv.push_back(v);
		}
	}
	return vv;
}

int countNode(NODE* pRoot) {
	int dem = 0;
	if (pRoot) {
		dem++;
		int left = countNode(pRoot->p_left);
		dem += left;
		int right = countNode(pRoot->p_right);
		dem += right;
	}
	return dem;
}

int sumNode(NODE* pRoot) {
	if (!pRoot) return 0;
	return pRoot->key + sumNode(pRoot->p_left) + sumNode(pRoot->p_right);
}

int height(NODE* pRoot) {
	if (!pRoot) return -1;
	int left = height(pRoot->p_left);
	int right = height(pRoot->p_right);
	if (left > right) return 1 + left;
	return 1 + right;
}
int heightNode(NODE* pRoot, int value) {
	if (!pRoot) return -1;
	if (pRoot->key == value) {
		return height(pRoot);
	}
	int leftResult = heightNode(pRoot->p_left, value);
	if (leftResult != -1) return leftResult;
	int rightResult = heightNode(pRoot->p_right, value);
	return rightResult;
}

int Level(NODE* pRoot, NODE* p) {
	if (!pRoot) return -1;
	if (pRoot == p) return 0;
	int leftLevel = Level(pRoot->p_left, p);
	int rightLevel = Level(pRoot->p_right, p);
	if (leftLevel != -1) return leftLevel + 1;
	if (rightLevel != -1) return rightLevel + 1;
	return -1;
}

int countLeaf(NODE* pRoot) {
	if (!pRoot) return 0;
	if (!pRoot->p_left && !pRoot->p_right) return 1;
	return countLeaf(pRoot->p_left) + countLeaf(pRoot->p_right);
}