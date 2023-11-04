/*
[q]https://neoj.sprout.tw/problem/391/
[AC]
[單點求最短路]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT N,M,S,E,F;//輸入點數量，起點，終點
		cin>>N>>M>>S>>E>>F;
		INT lst[N+1];//紀錄S到i點的最近距離
		vector<pair<INT,INT>> edge[N+1];
		fill(lst,lst+N+1,1e16);
		bool visit[N+1];
		memset(visit,0,sizeof(visit));

		for(INT i=0;i<M;i++){//輸入點資訊
			INT A,B,C,D,C2;
			cin>>A>>B>>C>>D>>C2;
			INT V=min(F,D)*C+max((INT)0,F-D)*C2;
			edge[A].push_back(make_pair(B,V));
		}

		//do Dijkstra
		
		priority_queue<PII,vector<PII>,greater<PII>> pq;//將點以距離(對點1)排序
		pq.push(make_pair(0,S));
		lst[S]=0;

		while(!pq.empty()){
			INT nw=pq.top().second;
			pq.pop();
			if(visit[nw])continue;//如果那個點作過了，就不要再做一次了
			//可以證明每個點作的第一次都是最好的一次，之後就沒有了

			for(PII i:edge[nw]){
				INT nxt=i.first,V=i.second;
				if(lst[nw]+V<lst[nxt]){//發現更短的距離
					lst[nxt]=lst[nw]+V;
					pq.push(make_pair(lst[nxt],nxt));
				}
			}
			visit[nw]=1;
		}
		cout<<lst[E]<<endl;
	}
	return 0;
}
//#endif
