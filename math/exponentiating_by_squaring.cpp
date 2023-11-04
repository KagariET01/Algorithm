/*
快速冪
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int

template<typename T>T pow_mod(T a,INT b,T mod){
	if(b==0)return a;
	T re=a;
	T tmp=a;
	b--;
	while(b){
		if(b&1){
			re=re*tmp;
			re=re%mod;
		}
		tmp=tmp*tmp;
		tmp=tmp%mod;
		b>>=1;
	}
	return re;
}