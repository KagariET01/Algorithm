// [最近共同祖先.cpp]

#include<bits/stdc++.h>
using namespace std;
#define INT long long int

const INT mxn=1e5+5;

INT deep[mxn];//距離根節點的距離(根節點距離為0)
INT p[mxn][35];
vector<INT> v[mxn];
void dfs(INT n,INT lst){
	for(INT i:v[n]){
		if(i==lst)continue;
		p[i][0]=n;
		deep[i]=deep[n]+1;
		dfs(i,n);
	}
}

void build(INT n){
	for(INT i=1;i<20;i++){
		for(INT j=0;j<n;j++){
			p[j][i]=p[p[j][i-1]][i-1];
		}
	}
}

INT LCA(INT a,INT b){//最近共同祖先
	if(deep[a]<deep[b])swap(a,b);
	if(deep[a]>deep[b]){
		INT dif=deep[a]-deep[b];
		for(INT i=0;i<20;i++){
			if(dif&1)a=p[a][i];
			dif>>=1;
		}
	}
	if(a==b)return a;
	for(INT i=19;i>=0;i--){
		if(p[a][i]!=p[b][i]){
			a=p[a][i];
			b=p[b][i];
		}
	}
	return p[a][0];
}
INT len(INT a,INT b){//a,b的距離
	INT lca=LCA(a,b);
	return deep[a]+deep[b]-deep[lca]*2;
}