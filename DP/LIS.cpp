/*
[LIS]
[最長遞增子序列]
O(nlogn)
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int

vector<INT> LIS(vector<INT> a){//
	INT n=a.size();
	INT dp[n+1];
	dp[0]=1;
	vector<INT> v;
	v.push_back(a[0]);
	INT L=1; 
	for (INT i=1;i<n;i++){ //尋找LIS
		if(a[i]>v.back()){ //如果a[i]比最後一個元素大，直接加入
			v.push_back(a[i]);
			L++;
			dp[i]=L;
		}else{//否則找到第一個比a[i]大的元素，取代它
			auto it=lower_bound(v.begin(),v.end(),a[i]);
			*it=a[i];
			dp[i]=it-v.begin()+1;
		}
	}

	//印出LIS
	vector<INT> ans;
	ans.reserve(L);
	for (INT i=n-1;i>=0;i--){
		if (dp[i]==L){//從後面開始找，找到第一個dp[i]==L的元素，加入ans
			ans.push_back(a[i]);
			L--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
