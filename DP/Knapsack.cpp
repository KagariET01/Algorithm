#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)

#define DBG if(debug)
bool debug=1;

const INT mxn=1000;
INT n;
vector<PII> wp;//{weight,price}
INT x;//max weight
INT Knapsack(){
	INT dp[x+1]={};
	for(INT i=0;i<wp.size();i++){
		for(INT j=x;j>=wp[i].first;j--){
			maxs(dp[j],dp[j-wp[i].first]+wp[i].second);
		}
	}
	return dp[x];
}
