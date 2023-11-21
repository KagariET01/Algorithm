// [st表]
// 區間極值查詢
// 不支援修改
// 預處理：$O(n*log_2(n))$
// 查詢：$O(1)$

#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)

const INT mxn=1e5;
const INT lgn=32;
INT orig[mxn+5];
INT n;
INT logn[mxn+5];
INT f[mxn+5][lgn];
void glog(){
	logn[0]=0;
	logn[1]=0;
	logn[2]=1;
	for(INT i=3;i<=mxn;i++){
		logn[i]=logn[i/2]+1;//log_2(i)=log_2((i/2) * 2)=log_2(i/2)+log_2(2)=log_2(i/2)+1
	}
}
void build(){
	for(INT i=0;i<n;i++){
		f[i][0]=orig[i];
	}
	for(INT j=1;j<lgn;j++){
		for(INT i=0; (i+(1<<(j-1))) <n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
}
INT query(INT l,INT r){
	INT lp=(r-l)+1;
	INT lglp=logn[lp];
	INT ans=f[l][lglp];
	maxs(ans,f[r-(1<<lglp)+1][lglp]);
	return ans;
}
