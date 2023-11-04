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
INT dist[mxn+5];
bool vis[mxn+5];
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






#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	DBG{
		cout<<"Temp by KagariET01"<<endl;
		cout<<"My Webpage: https://kagariet01.github.io/about"<<endl;
		cout<<"===DBG mod on==="<<endl;
		cout<<"Here's your CFG"<<endl;
		for(int i=0;i<argc;i++){
			string nwstr=argv[i];
			cout<<'['<<nwstr<<']'<<endl;
		}
		cout<<"===Code start==="<<endl;
	}
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	function<int(INT)> solve=[](INT casenum){
		INT s,e,f;
		cin>>n>>m>>s>>e>>f;
		for(INT i=0;i<m;i++){
			INT a,b,c,d,c2;
			cin>>a>>b>>c>>d>>c;
			INT v=min(f,d)*c+hmax(0,f-d)*c2;
			tree[a].push_back({b,v});
			tree[b].push_back({a,v});
		}
		dijkstra(s);
		cout<<dist[e]<<endl;
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	bool eof=0;
	string yes="YES";
	string no="NO";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		INT re=solve(i);
		if(!ynans){
			if(re==-1)return 0;
		}else{
			if(re==1){
				cout<<yes<<endl;
			}else if(re==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}