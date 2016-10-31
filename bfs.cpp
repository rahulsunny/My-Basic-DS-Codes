#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector <int> G[100000];
vector <int> vis(100000,0);
int dist[100001];
int path[100001];
int main() {
	int n,m;
	cin >> n >> m;
	int i;
	for (i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int start,end;
	cin >> start >> end;
	queue <int> q;
	q.push(start);
	vis[start] = 1;
	int f1 = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (i = 0; i < G[temp].size(); i++) {
			if (vis[G[temp][i]] == 0) {
				dist[G[temp][i]] = dist[temp] + 1;
				path[G[temp][i]] = temp;
				if (G[temp][i] == end) {
					f1 = 1;
					break;
				}
				q.push(G[temp][i]);
				vis[G[temp][i]] = 1;
			}
		}
		if (f1 == 1) {
			break;
		}
	}
	int l = end;
	cout << end << ' ';
	while (l != start) {
		cout << path[l] << ' ';
		l = path[l];
	}
	cout << endl;
	cout << dist[end] << endl;
	return 0;
}
