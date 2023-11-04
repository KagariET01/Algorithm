/*
線段樹
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define FN function<INT(INT,INT)>

//初始變數
vector<INT> seg;//線段數
vector<INT> seg_mark_add;//懶人標記，紀錄區間加值
vector<INT> arr;//原始數列
INT m;//操作編號
INT n;//數列長度
INT q;//詢問次數

void build(INT l,INT r,INT index,FN merge){//建樹
	if(l==0 and r==n-1){
		seg.clear();
		seg.resize(4*n);
		seg_mark_add.clear();
		seg_mark_add.resize(4*n);
	}
	if(l==r){
		seg[index]=arr[l];
		return;
	}
	INT mid=(r-l)/2+l;
	build(l,mid,index*2,merge);
	build(mid+1,r,index*2+1,merge);
	seg[index]=merge(seg[index*2],seg[index*2+1]);
	return;
};

void modify(INT x,INT v,INT l,INT r,INT index,FN merge){/*單點改值（a=b）*/
	if(l==x && r==x){
		seg[index]=v;
		return;
	}else{
		INT mid=(r-l)/2+l;
		if(x<=mid){
			modify(x,v,l,mid,index*2,merge);
		}else{
			modify(x,v,mid+1,r,index*2+1,merge);
		}
		seg[index]=merge(seg[index*2],seg[index*2+1]);
	}
	return;
};

void modify_add(INT x,INT v,INT l,INT r,INT index,FN merge){/*單點改值（a+=b）*/
	if(l==x && r==x){
		seg[index]+=v;
		return;
	}else{
		INT mid=(r-l)/2+l;
		if(x<=mid){
			modify_add(x,v,l,mid,index*2,merge);
		}else{
			modify_add(x,v,mid+1,r,index*2+1,merge);
		}
		seg[index]=merge(seg[index*2],seg[index*2+1]);
	}
	return;
};

void loop_modify_add(INT ml,INT mr,INT v,INT l,INT r,INT index,FN merge){/*區間加值（a+=b）*/
	if(ml<=l && r<=mr){
		seg_mark_add[index]+=v;
		return;
	}else{
		INT mid=(r-l)/2+l;
		if(ml<=mid){
			loop_modify_add(ml,mr,v,l,mid,index*2,merge);
		}
		if(mid+1<=mr){
			loop_modify_add(ml,mr,v,mid+1,r,index*2+1,merge);
		}
	}
}

INT query(INT ql,INT qr,INT l,INT r,INT index,FN merge){//區間查詢
	if(seg_mark_add[index]){
		if(l==r){
			seg[index]+=seg_mark_add[index];
			seg_mark_add[index]=0;
		}else{
			INT nw=r-l;
			INT ad=seg_mark_add[index];
			INT res=seg_mark_add[index];
			while(nw){
				if(nw&1){
					res=merge(res,ad);
				}
				ad=merge(ad,ad);
				nw>>=1;
			}
			seg[index]+=res;

			seg_mark_add[index*2]+=seg_mark_add[index];
			seg_mark_add[index*2+1]+=seg_mark_add[index];
			seg_mark_add[index]=0;
		}
	}
	if(ql<=l && r<=qr){
		return seg[index];
	}else{
		INT mid=(r-l)/2+l;
		INT ans=0;
		if(ql<=mid && mid+1<=qr){
			ans=merge(query(ql,qr,l,mid,index*2,merge),query(ql,qr,mid+1,r,index*2+1,merge));
		}else if(ql<=mid){
			ans=query(ql,qr,l,mid,index*2,merge);
		}else if(mid+1<=qr){
			ans=query(ql,qr,mid+1,r,index*2+1,merge);
		}
		return ans;
	}
};



FN sum=[](INT a,INT b){return a+b;};
FN maxn=[](INT a,INT b){return max(a,b);};
FN minn=[](INT a,INT b){return min(a,b);};
FN xorr=[](INT a,INT b){return a^b;};
FN andd=[](INT a,INT b){return a&b;};
FN orr=[](INT a,INT b){return a|b;};

int main(){
	n=arr.size();
	build(0,n-1,1,sum);
	return 0;
}