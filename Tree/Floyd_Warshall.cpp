// [Floyd_Warshall.cpp]

#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
const INT mxint=1e18;


const INT mxn=100+5;
vector<INT> tree[mxn];//tree
INT road[mxn][mxn];//ans
INT n;

void build(){
	for(INT i=0;i<=n;i++){
		for(INT j=0;j<=n;j++){
			road[i][j]=mxint;
		}
	}
	for(INT k=0;k<=n;k++){//中繼站
		for(INT i=0;i<=n;i++){//起點
			for(INT j=0;j<=n;j++){//終點
				mins(road[i][j],road[i][k]+road[k][j]);
			}
		}
	}
}