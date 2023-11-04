/*
[擴展歐幾里得]https://zh.wikipedia.org/wiki/扩展欧几里得算法
[求反模逆元 a^(-1) mod n]https://zh.wikipedia.org/wiki/模反元素#求模反元素
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
pair<INT,pair<INT,INT>> Extended_Euclidean(INT a,INT b){//擴展歐幾里得
	//回傳{gcd(a,b),{x,y}}，使得ax+by=gcd(a,b)
	INT lst[3][3]={
		{a,1,0},
		{b,0,1},
		{0,0,0}
	};
	INT i=2;
	for(i=2;lst[(i+2)%3][0];i=(i+1)%3){
		INT q=lst[(i+1)%3][0]/lst[(i+2)%3][0];
		lst[i][0]=lst[(i+1)%3][0]-lst[(i+2)%3][0]*q;
		lst[i][1]=lst[(i+1)%3][1]-lst[(i+2)%3][1]*q;
		lst[i][2]=lst[(i+1)%3][2]-lst[(i+2)%3][2]*q;
	}
	i=(i+1)%3;
	pair<INT,pair<INT,INT>> re={lst[i][0],{lst[i][1],lst[i][2]}};
	return re;
}

INT Modular_multiplicative_inverse(INT a,INT n){//用擴展歐幾里得求模逆元
	pair<INT,pair<INT,INT>> ans=Extended_Euclidean(a,n);
	INT re=ans.second.first;
	re=(re%n+n)%n;
	if(ans.first==1)return re;
	else return -1;
}


int main(){
	int a,b;
	cin>>a>>b;
	int ans=Modular_multiplicative_inverse(a,b);
	cout<<ans<<endl;
}

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a289
*/