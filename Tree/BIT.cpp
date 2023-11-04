#include<bits/stdc++.h>
using namespace std;
#define INT long long int

INT n;
vector<INT> vec;
vector<INT> BIT;

INT low_bit(INT x){
	return x&(-x);
}

INT getsum(INT x){//求1~x的值
	INT re=0;
	while(x>0){
		re+=BIT[x];
		x-=low_bit(x);
	}
	return re;
}

INT getloop(INT l,INT r){//求l~r的值
	return getsum(r)-getsum(l-1);
}

void update(INT x,INT v){//單點加v
	while(x<=n){
		BIT[x]+=v;
		x+=low_bit(x);
	}
}