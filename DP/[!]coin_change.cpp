/*
找零問題
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)

const INT mxn=1000;
vector<INT> coin;//金錢列表(請先以嚴格遞減排序)
INT dp[mxn+1][mxn+1];//dp[al][mx]表示湊出al元，最大面額為mx的方法數
INT solve(INT al,INT mx){//al為最終要湊出的$，mx為面額id
	if(!dp[al][mx]){
		if(al==0){//如果al為0:有一種方法:不使用任何面額
			dp[al][mx]=1;
		}else if(mx==0){//如果面額為0:無解
			dp[al][mx]=0;
		}else{
			dp[al][mx]=solve(al,mx-1);//不使用此面額
			if(coin[mx]<=al)dp[al][mx]+=solve(al-coin[mx],mx);//使用此面額
		}
	}
	return dp[al][mx];
}

int main(){
	coin.push_back(50);
	coin.push_back(25);
	coin.push_back(10);
	coin.push_back(5);
	coin.push_back(1);
	INT inin=0;
	while(cin>>inin){
		cout<<solve(inin,4)<<endl;
	}
}