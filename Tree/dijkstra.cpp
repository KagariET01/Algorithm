#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define hmax(a,b) ((a>b)?a:b)
#define hmin(a,b) ((a<b)?a:b)
const INT mxINT=1e18;

const INT mxn=1e5;
vector<PII> tree[mxn+5];//{node,weight}
INT n,m;
//n=number of nodes
//m=number of edges
INT dist[mxn+5];//distance from start
bool vis[mxn+5];//visited

void init(){
	for(INT i=0;i<=n+1;i++){
		tree[i].clear();
		dist[i]=mxINT;
		vis[i]=0;
	}
}

void dijkstra(INT st){
	priority_queue<PII,vector<PII>,greater<PII>> pq;
	pq.push({0,st});
	for(INT i=0;i<=n;i++)dist[i]=mxINT,vis[i]=0;
	dist[st]=0;
	while(!pq.empty()){
		INT nw=pq.top().second;
		pq.pop();
		if(vis[nw])continue;
		for(PII i:tree[nw]){
			INT nxt=i.first,v=i.second;
			if(dist[nw]+v<dist[nxt]){
				dist[nxt]=dist[nw]+v;
				pq.push({dist[nxt],nxt});
			}
		}
		vis[nw]=1;
	}
}

