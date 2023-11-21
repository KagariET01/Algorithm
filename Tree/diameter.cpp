// [樹直徑.cpp]
// 樹上最長距離

#include<bits/stdc++.h>
using namespace std;
#define INT long long int

const INT mxn=2e5;
vector<INT> tree[mxn+5];
INT mx=0;
INT p=0;
/*fn定義*/
INT dfs(INT now,INT from,INT ans=0){
	if(mx<ans){
		mx=ans;
		p=now;
	}
	for(INT i:tree[now]){
		if(i==from)continue;
		dfs(i,now,ans+1);
	}
	return p;
}

INT diameter(){
	mx=0;
	p=0;
	dfs(dfs(0,-1),-1);
	return mx;
}