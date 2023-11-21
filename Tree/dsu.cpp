// [dsu.cpp]
// 並查集

#include<bits/stdc++.h>
using namespace std;
#define INT long long int
struct dsu{
	vector<INT> vec;//vec[i]紀錄i連到哪裡
	vector<set<INT>> se;//se[i]記錄所有連到i的點編號
	void init(INT n){//初始化
		se.clear();
		se.resize(n+1);
		vec.clear();
		vec.resize(n+1);
		for(INT i=0;i<=n;i++){
			vec[i]=i;
			se[i].clear();
		}
	}
	INT find(INT n){//查詢編號
		if(vec[n]==n){
			return n;
		}else{
			INT re=find(vec[n]);//找出最終老大
			se[vec[n]].erase(n);//將n連到re，所以要把vec[n]的被動連線解除掉
			vec[n]=re;//將n連到re
			se[re].insert(n);//re被n連
			return re;
		}
	}
	void merge(INT a,INT b){//合併兩者
		INT aboss=find(a);
		INT bboss=find(b);
		vec[aboss]=bboss;//將a樹連到b樹
		se[bboss].insert(aboss);//b樹被a連
	}
	void erase(INT n){//將n孤立
		vec[n]=n;//將自己連到自己
		INT othboss=*(se[n].begin());//其他的老大就用第一個連到n的人來當
		for(INT i:se[n]){
			vec[i]=othboss;
			se[othboss].insert(i);
		}
		se[n].clear();
	}
};