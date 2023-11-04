/*
[LCS]
[最長共用子序列]
*/

#include<bits/stdc++.h>
using namespace std;
#define INT long long int

string s,t;//輸入字串
INT dp[3001][3001];
void lcs(INT n,INT m){//n=s.size(),m=t.size() 求兩字串的最長共用子序列
	for(INT i=1;i<=n;i++){
		for(INT j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
}
/*void printdp(INT n,INT m){//DBG 印出dp表格
	if(debug){
		for(INT i=0;i<=n;i++){
			for(INT j=0;j<=m;j++){
				cout<<dp[i][j]<<",";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}*/
string backlcs(INT n,INT m){//回推最長共用子序列
	string re="";
	INT i=n,j=m;
	while(i && j){
		if(s[i-1]==t[j-1]){//如果兩字元相同，加入re，並往左上角移動
			re.push_back(s[i-1]);
			i--;
			j--;
		}else{
			if(dp[i-1][j]>=dp[i][j-1]){//如果上面的數字比左邊大，往上移動
				i--;
			}else j--;
		}
	}
	reverse(re.begin(),re.end());
	return re;
}
