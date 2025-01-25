//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D

#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a;
	vector<int>cap(a);
	for(int i=0;i<a;i++) cin>>cap[i];
	cin>>b;
	vector<int>pant(b);
	for(int i=0;i<b;i++) cin>>pant[i];
	cin>>c;
	vector<int>shirt(c);
	for(int i=0;i<c;i++) cin>>shirt[i];
	cin>>d;
	vector<int>sh(d);
	for(int i=0;i<d;i++) cin>>sh[i];
	sort(cap.begin(),cap.end());
	sort(pant.begin(),pant.end());
	sort(shirt.begin(),shirt.end());
	sort(sh.begin(),sh.end());
 	long long ans=INT_MAX;
	vector<int>ans_v(4);
	long long u1=0,u2=0,u3=0,u4=0;
	long long mini,maxi;
	while(u1<a && u2<b && u3<c && u4<d){
		mini=min(min(cap[u1],pant[u2]),min(shirt[u3],sh[u4]));
		maxi=max(max(cap[u1],pant[u2]),max(shirt[u3],sh[u4]));
		if(maxi-mini<ans){
			ans=maxi-mini;
			ans_v[0]=cap[u1];
			ans_v[1]=pant[u2];
			ans_v[2]=shirt[u3];
			ans_v[3]=sh[u4];
		}
		if(mini==cap[u1]) u1++;
		else if(mini==pant[u2]) u2++;
		else if(mini==shirt[u3]) u3++;
		else u4++;
	}
	for(int i=0;i<4;i++){
		cout<<ans_v[i]<<" ";
	}
	
}
