// [拓撲排序.cpp]

/*
Topological Sort
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)

const INT mxn=1e5;
vector<INT> tree[mxn];
INT in[mxn];
INT n=0,m=0;

void Topological(){
	queue<INT> que;
	for(INT i=0;i<=n;i++){
		if(!in[i])que.push(i);
	}
	while(!que.empty()){
		INT nw=que.front();
		que.pop();
		/*do something here*/
		cout<<nw<<" ";
		for(auto i:tree[nw]){
			INT nx=i;
			in[nx]--;
			if(!in[nx]){
				que.push(nx);
			}
			/*do something here*/
		}
	}
}

int main(){
	cin>>n>>m;
	for(INT i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		in[b]++;
		tree[a].push_back(b);
	}
	Topological();
}