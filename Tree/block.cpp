#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define FN function<INT(INT,INT)>

vector<INT> block;//分塊
vector<INT> block_mark_add;//懶人標記，紀錄區間加值
vector<INT> arr;//原始數列
INT n;
INT block_sz;

INT sqrt(INT n){
	INT l=0,r=n;
	while(l<r){
		INT mnt=(r-l)/r+l;
		if(mnt*mnt<n){
			l=mnt+1;
		}else{
			r=mnt;
		}
	}
	return l-1;
}

void build(FN merge){
	block.clear();
	block_mark_add.clear();
	block_sz=sqrt(n);
	block.reserve(n/block_sz+1);
	block_mark_add.reserve(n/block_sz+1);
	INT nw=0;
	for(INT i=0;i<n;i++){
		if(!(i%block_sz)){
			nw=arr[i];
		}else{
			nw=merge(nw,arr[i]);
		}
		if((i%block_sz)==block_sz-1){
			block.push_back(nw);
		}
	}
}

void modify(INT x,INT v,FN merge){
	INT l=(x/block_sz)*block_sz;
	INT r=l+block_sz;
	arr[x]=v;
	nw=0;
	for(INT i=l;i<r;i++){
		if(!(i%block_sz)){
			nw=arr[i];
		}else{
			nw=merge(nw,arr[i]);
		}
		if((i%block_sz)==block_sz-1){
			block[l/block_sz]=nw;
		}
	}
}

void modify_add(INT x,INT v,FN merge){
	INT l=(x/block_sz)*block_sz;
	INT r=l+block_sz;
	arr[x]+=v;
	nw=0;
	for(INT i=l;i<r;i++){
		if(!(i%block_sz)){
			nw=arr[i];
		}else{
			nw=merge(nw,arr[i]);
		}
		if((i%block_sz)==block_sz-1){
			block[l/block_sz]=nw;
		}
	}
}

INT query(INT l,INT r,FN merge){
	INT re=0;
	bool flag=1;
	for(;l<=r && l%block_sz;l++){
		if(flag){
			re=arr[l];
			flag=0;
		}
		else{
			re=merge(re,arr[l]);
		}
	}
	for(;l+block_sz<=r;l+=block_sz){
		re=merge(re,block[l/block_sz]);
	}
	for(;l<=r;l++){
		re=merge(re,arr[l]);
	}
	return re;
}

FN merge=[](INT a,INT b){return max(a,b);};



int main(){
	cin>>n;
	arr.reserve(n);
	for(INT i=0;i<n;i++){
		arr.push_back(read(INT));
	}
	build(merge);
	INT q=read(INT);
	while(q--){
		INT l,r;
		cin>>l>>r;
		if(l>r)swap(l,r);
		l--,r--;
		cout<<query(l,r,merge)<<endl;
	}
}