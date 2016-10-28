#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#define gc getchar_unlocked
using namespace std;
vector <int> v1[100001];
inline int getn()
{
    int n = 0 , s = 1 ;
    char p = getchar( ) ;
    if( p == '-' )
        s = -1 ;
    while( ( p < '0' || p > '9' ) && p != EOF && p != '-' )
        p = getchar( ) ;
    if( p == '-' )
        s = -1 , p = getchar( ) ;
    while( p >= '0' && p <= '9' )
    {
        n = ( n << 3 ) + ( n << 1 ) + ( p - '0' ) ;
        p = getchar( ) ;
    }
    return n * s ;
}
int main() {
	int n,m,z;
	n = getn();
	m = getn();
	int indeg[n+1];
	memset(indeg,0,sizeof(indeg));
	z = m;
	while (z--) {
		int u,v;
		u = getn();
		v = getn();
		v1[u].push_back(v);
		indeg[v]++;
	}
//	priority_queue <int, greater<int> > pq;
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 1; i <= n; i++) {
		if (!indeg[i]) {
			pq.push(i);
		}
	}
	vector <int> v2;
	while (!pq.empty()) { 
		int val = pq.top();
		v2.push_back(val);
		//cout << val << endl;
		pq.pop();
		for (int i = 0; i < v1[val].size(); i++) {
			int z = v1[val][i];
			indeg[z]--;
			if (!indeg[z]) {
				pq.push(z);
			}
		}
	}
	if (v2.size() != n) {
		printf("Sandro fails.\n");
		return 0;
	}
	for (int i = 0; i < v2.size(); i++) {
		printf("%d ",v2[i]);
	}
	printf("\n");
	return 0;
}
