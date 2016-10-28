#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100001];
int tree[1000001];
int lazy[1000001];
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
	if (lazy[node] != 0) {
		tree[node] = tree[node] + ((y-x)+1)*lazy[node];
		if (x != y) {
			lazy[node*2] += lazy[node];
		    lazy[(node*2)+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (y < x || x > r || l > y) {
		return ;
	}
	if(x >= l && y <= r) { 
    	tree[node] = tree[node] + (((y-x)+1)*upd);
		if(x != y) { 
			lazy[node*2] = lazy[node*2] + upd;
			lazy[node*2+1] = lazy[(node*2)+1] + upd;
		}
     	return;
	}
	update_tree(node*2,x,(y+x)/2,l,r,upd);
	update_tree((node*2)+1,((y+x)/2)+1,y,l,r,upd);
	tree[node] = tree[node*2] + tree[(node*2)+1];
}
void query_tree(int node,int x,int y,int l,int r) {
	
	if (x > y || y < l || x > r) {
		return ;
	}
	if (lazy[node] != 0) {
		tree[node] = tree[node] + ((y-x)+1)*lazy[node];
		if (x != y) {
			lazy[node*2] += lazy[node];
		    lazy[(node*2)+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (x >= l && y <= r) {
		sum = sum + tree[node];
		return ;
	}
	query_tree(node*2,x,(y+x)/2,l,r);
	query_tree((node*2)+1,((y+x)/2)+1,y,l,r);
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	build_tree(1,0,n-1);
	for (int i = 1; i <= 7; i++) {
		cout << tree[i] << ' ';
	}
	cout << endl;
	update_tree(1,0,n-1,0,2,10);
	for (int i = 1; i <= 7; i++) {
		cout << tree[i] << ' ';
	}
	cout << endl;
	sum = 0;
	query_tree(1,0,n-1,0,3);
	cout << sum << endl;
}
