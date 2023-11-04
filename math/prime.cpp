// [Prime.cpp]

#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)

// Prime
const INT mxn=1e6;
INT n;
INT a[mxn+5];
vector<INT> prime;
void find_prime(INT n){
	prime.push_back(2);
	a[2]=1;
	for(INT i=3;i<=n;i++){
		if(!a[i])prime.push_back(i);
		for(INT j:prime){
			a[i*j]=j;
			if(j==a[i])break;
		}
	}
}


int main(){
	find_prime(mxn);
	for(INT i:prime)cout<<i<<' ';
	cout<<endl;
}