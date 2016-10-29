#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#define INF 10000001
using namespace std;
typedef pair <int,int> ii;
int pred[100001];
int plen[100001];
int status[100001];
vector <ii> G[100001];
priority_queue <ii, vector <ii>, greater<ii> > pq;
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));
	}
	for (int i = 1; i <= n; i++) {
		pred[i] = -1;
		plen[i] = 1000001;
	}
	int start;
	cin >> start;
	plen[start] = 0;
	pq.push(ii(0,start));
	while (!pq.empty()) {
		ii top = pq.top();
		pq.pop();
		int clen = top.first, ind = top.second;
		if (status[ind]) {
			continue;
		}
		status[ind] = 1;
		vector <ii> :: iterator it;
		for (it = G[ind].begin(); it != G[ind].end(); it++) {
			int ver = it->first;
			int dt = it->second;
			if (status[ver]) {
				continue;
			}
			if (plen[ver] > plen[ind]+dt) {
				plen[ver] = plen[ind]+dt;
				pq.push(ii(plen[ver],ver));
				pred[ver] = ind;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << i << ' ' << plen[i] << endl;
	}
	int val = 6;
	while (val != 1) {
		cout << pred[val] << endl;
		val = pred[val];
	}
	return 0;
}
