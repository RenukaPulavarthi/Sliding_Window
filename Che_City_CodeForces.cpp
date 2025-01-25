//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int>v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	long long l=0,r=0,ans=0;
	while(r<n){
		if(v[r]-v[l]>k){
			ans+=n-r;
			l++;
		}
		else{
			r++;
		}
	}
	cout<<ans;
	
}
