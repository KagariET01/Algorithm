#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)

template<typename TPE> void merge_sort(TPE *l,TPE *r){
	if(l==r)return;
	TPE mid=(r-l)/2+l;
	merge_sort(l,mid);
	merge_sort(mid+1,r);

	vector<TPE> vec;
	vec.reserve(r-l);
	TPE *i=l,*j=mid+1;
	while(i<mid && j<r){
		if(*i<*j){
			/*do something*/
			vec.push_back(*i);
			i++;
		}else{
			/*do something*/
			vec.push_back(*j);
			j++;
		}
	}
	while(i<mid){
		/*do something*/
		vec.push_back(*i);
		i++;
	}
	while(j<r){
		/*do something*/
		vec.push_back(*j);
		j++;
	}
	for(TPE i:vec){
		*l=i;
		l++;
	}
}
