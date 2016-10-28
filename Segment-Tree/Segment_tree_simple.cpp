#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100001];
int tree[10000001];
int sum = 0;
void build_tree(int node,int x,int y) {
	if (x > y) {
		return ;
	}
	if (x == y) {
		tree[node] = a[x];
		return ;
	}
	build_tree(node*2,x,(x+y)/2);
	build_tree((node*2)+1,((x+y)/2)+1,y);
	tree[node] = tree[node*2] + tree[(node*2)+1];
}
void update_tree(int node,int x,int y,int l,int r,int upd) {
	if (y < x || x > r || l > y) {
		return ;
	}
	if (x == y) {
		if (tree[node] == 0) {
			tree[node] = 1;
		}
		else {
			tree[node] = 0;
		}
		return ;
	}
	update_tree(node*2,x,(y+x)/2,l,r,upd);
	update_tree((node*2)+1,((y+x)/2)+1,y,l,r,upd);
	tree[node] = tree[node*2] + tree[(node*2)+1];
}
void query_tree(int node,int x,int y,int l,int r) {
	if (x > y || y < l || x > r) {
		return ;
	}
	if (x >= l && y <= r) {
		sum = sum + tree[node];
		return ;
	}
	query_tree(node*2,x,(y+x)/2,l,r);
	query_tree((node*2)+1,((y+x)/2)+1,y,l,r);
}
int main() {
	int n,q;
	scanf("%d %d",&n,&q);
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	build_tree(1,0,n-1);
	while (q--) {
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if (x == 0) {
			update_tree(1,0,n-1,y,z,0);
		}
		else if (x == 1) {
			sum = 0;
			query_tree(1,0,n-1,y,z);
			printf("%d\n",sum);
		}
	}
	return 0;
} 
