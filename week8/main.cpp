#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int>> convertMatrixToList(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cout << "khong the mo duoc file de doc" << endl;
		return {};
	}
	int n;
	file >> n;
	file.ignore();
	vector<vector<int>> vv(n);
	int row = 0;
	string line;
	while (getline(file, line)) {
		stringstream s(line);
		int col = 0, val;
		while (s >> val) {
			if (val == 1) {
				vv[row].push_back(col);
			}
			col++;
		}
		row++;
	}
	file.close();
	return vv;
}

vector<vector<int>> convertListToMatrix(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cout << "khong the mo file de doc" << endl;
		return {};
	}
	int n;
	file >> n;
	file.ignore();
	vector<vector<int>> vv(n, vector<int>(n, 0));
	string line;
	int row = 0;
	while (getline(file, line)) {
		stringstream s(line);
		int val;
		s >> val;
		while (s >> val) {
			vv[row][val] = 1;
		}
		row++;
	}
	file.close();
	return vv;
}

bool isDirected(const vector<vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (adjMatrix[i][j] != adjMatrix[j][i]) return true;
		}
	}
	return false;
}

int countVertices(const vector<vector<int>>& adjMatrix) {
	return adjMatrix.size();
}

int countEdges(const vector<vector<int>>& adjMatrix) {
	int count = 0;
	int n = adjMatrix.size();
	if (isDirected(adjMatrix)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adjMatrix[i][j] == 1) {
					count++;
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (adjMatrix[i][j] == 1) count++;
			}
		}
	}
	return count;
}

vector<int> getIsolatedVertices(const vector<vector<int>>& adjMatrix) {
	vector<int> v;
	int n = adjMatrix.size();
	for (int i = 0; i < n; i++) {
		int ktra = 0;
		for (int j = 0; j < n; j++) {
			if (adjMatrix[i][j] == 1 || adjMatrix[j][i] == 1) {
				ktra = 1;
				break;
			}
		}
		if (ktra == 0) v.push_back(i);
	}
	return v;
}

bool isCompleteGraph(const vector<vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	for (int i = 0; i < n; i++) {
		if (adjMatrix[i][i] != 0) return false;
		for (int j = i + 1; j < n; j++) {
			if (adjMatrix[i][j] != 1 || adjMatrix[j][i] != 1) return false;
		}
	}
	return true;
}

bool isBipartite(const std::vector<std::vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	vector<int> color(n, -1);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			queue<int> q;
			q.push(i);
			color[i] = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v = 0; v < n; v++) {
					if (adjMatrix[u][v]) {
						if (color[v] == -1) {
							color[v] = 1 - color[u];
							q.push(v);
						}
						else if (color[v] == color[u]) return false;
					}
				}
			}
		}
	}
	return true;
}

bool isCompleteBipartite(const vector<vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	vector<int> color(n, -1);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			queue<int> q;
			q.push(i);
			color[i] = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v = 0; v < n; v++) {
					if (adjMatrix[u][v]) {
						if (color[v] == -1) {
							color[v] = 1 - color[u];
							q.push(v);
						}
						else if (color[v] == color[u]) return false;
					}
				}
			}
		}
	}
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			if (u != v) {
				if (color[u] != color[v]) {
					if (adjMatrix[u][v] != 1) return false;
				}
				else {
					if (adjMatrix[u][v] != 0) return false;
				}
			}
		}
	}
	return true;
}

vector<vector<int>> convertToUndirectedGraph(const vector<vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	vector<vector<int>> vv(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adjMatrix[i][j] == 1) {
				vv[i][j] = 1;
				vv[j][i] = 1;
			}
		}
	}
	return vv;
}

vector<vector<int>> getComplementGraph(const vector<vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	vector<vector<int>> vv(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (adjMatrix[i][j] == 0) {
				vv[i][j] = 1;
				vv[j][i] = 1;
			}
		}
	}
	return vv;
}

vector<int> findEulerCycle(const vector<vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	for (int i = 0; i < n; ++i) {
		int degree = 0;
		for (int j = 0; j < n; ++j) {
			degree += adjMatrix[i][j];
		}
		if (degree % 2 != 0) return {};
	}
	vector<vector<int>> graph = adjMatrix;
	vector<int> circuit;
	stack<int> currPath;
	int currV = 0;  
	currPath.push(currV);
	while (!currPath.empty()) {
		bool hasEdge = false;
		for (int nextV = 0; nextV < n; ++nextV) {
			if (graph[currV][nextV] > 0) {
				hasEdge = true;
				graph[currV][nextV]--;
				graph[nextV][currV]--; 
				currPath.push(currV);
				currV = nextV;
				break;
			}
		}
		if (!hasEdge) {
			circuit.push_back(currV);
			currV = currPath.top();
			currPath.pop();
		}
	}
	return circuit;
}

void dfs(vector<vector<int>>& spanningTree, const vector<vector<int>>& adjMatrix, vector<bool>& visited, int start) {
	int n = adjMatrix.size();
	visited[start] = true;
	for (int v = 0; v < n; ++v) {
		if (adjMatrix[start][v] && !visited[v]) {
			spanningTree[start][v] = 1;
			spanningTree[v][start] = 1;
			dfs(spanningTree,adjMatrix,visited,v);
		}
	}
}
vector<vector<int>> dfsSpanningTree(const vector<vector<int>>& adjMatrix, int start) {
	int n = adjMatrix.size();
	vector<vector<int>> spanningTree(n, vector<int>(n, 0)); 
	vector<bool> visited(n, false);
	dfs(spanningTree,adjMatrix,visited,start);
	return spanningTree;
}

vector<vector<int>> bfsSpanningTree(const vector<vector<int>>& adjMatrix, int start) {
	int n = adjMatrix.size();
	vector<vector<int>> spanningTree(n, vector<int>(n, 0));
	vector<bool> visited(n, false);
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < n; ++v) {
			if (adjMatrix[u][v] && !visited[v]) {
				visited[v] = true;
				spanningTree[u][v] = 1;
				spanningTree[v][u] = 1;
				q.push(v);
			}
		}
	}
	return spanningTree;
}

bool isConnected(int u, int v, const vector<vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	vector<bool> visited(n, false);
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (curr == v) return true; 
		for (int next = 0; next < n; ++next) {
			if (adjMatrix[curr][next] && !visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return false; 
}

vector<int> dijkstra(int start, int end, const vector<vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	vector<int> dist(n, INT_MAX);
	vector<int> parent(n, -1);
	vector<bool> visited(n, false);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		if (u == end) break;
		for (int v = 0; v < n; ++v) {
			int weight = adjMatrix[u][v];
			if (weight > 0 && !visited[v]) { 
				int newDist = dist[u] + weight;
				if (newDist < dist[v]) {
					dist[v] = newDist;
					parent[v] = u;
					pq.push({ newDist, v });
				}
			}
		}
	}
	if (dist[end] == INT_MAX) return {};
	vector<int> path;
	for (int cur = end; cur != -1; cur = parent[cur])
		path.push_back(cur);
	reverse(path.begin(), path.end());
	return path;
}

vector<int> bellmanFord(int start, int end, const vector<vector<int>>& adjMatrix) {
	int n = adjMatrix.size();
	vector<int> dist(n, INT_MAX);
	vector<int> predecessor(n, -1);
	dist[start] = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				if (adjMatrix[u][v] != INT_MAX && dist[u] != INT_MAX &&
					dist[u] + adjMatrix[u][v] < dist[v]) {
					dist[v] = dist[u] + adjMatrix[u][v];
					predecessor[v] = u;
				}
			}
		}
	}
	for (int u = 0; u < n; ++u) {
		for (int v = 0; v < n; ++v) {
			if (adjMatrix[u][v] != INT_MAX && dist[u] != INT_MAX &&
				dist[u] + adjMatrix[u][v] < dist[v]) {
				cout << "Graph contains a negative-weight cycle.\n";
				return {};
			}
		}
	}
	vector<int> path;
	for (int at = end; at != -1; at = predecessor[at])
		path.insert(path.begin(), at);
	if (path.empty() || path[0] != start) return {};
	return path;
}
