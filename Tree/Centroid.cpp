#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)

//Centroid
const INT mxn=1e5;
INT n;
vector<INT> tree[mxn+1];
INT sub[mxn+1];//子樹最大大小

INT dfs(INT nw,INT pre){
	INT re=0;
	for(INT i:tree[nw]){
		if(i==pre){
			continue;
		}
		INT a=dfs(i,nw);
		re+=a;
		maxs(sub[nw],a);
	}
	maxs(sub[nw],n-re-1);
	return re+1;
}

INT centroid(){
	memset(sub,0,sizeof(sub));
	dfs(1,-1);
	INT re=1;
	for(INT i=0;i<=n;i++){
		if(sub[i]<sub[re]){
			re=i;
		}
	}
	return re;
}