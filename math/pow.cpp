#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)

template<typename T,typename T2>T pow(T a,INT b,T2 mod){
	if(b==0)return a;
	T re=a;
	b--;
	T x=a;
	while(b){
		if(b&1){
			re=re*x;
			re=re%mod;
		}
		x=x*x;
		x=x%mod;
		b>>=1;
	}
	return re;
}

template<typename T>T pow(T a,INT b){
	if(b==0)return a;
	T re=a;
	b--;
	T x=a;
	while(b){
		if(b&1){
			re=re*x;
		}
		x=x*x;
		b>>=1;
	}
	return re;
}