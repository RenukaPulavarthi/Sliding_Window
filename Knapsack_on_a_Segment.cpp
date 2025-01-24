// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/E

#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,s;
	cin>>n>>s;
	vector<long long>arr(n);
	for(long long i=0;i<n;i++) cin>>arr[i];
	vector<long long>cost(n);
	for(long long i=0;i<n;i++) cin>>cost[i];
	long long l=0,r=0;
	long long w=0,c=0;
	long long ans=0;
	while(r<n && l<=r){
		if(w+arr[r]<=s){
			w+=arr[r];
			c+=cost[r];
		}
		else{
			w+=arr[r];
			c+=cost[r];
			while(l<=r && w>s){
				w-=arr[l];
				c-=cost[l];
				l++;
			}
		}
		r++;
		ans=max(ans,c);
//		cout<<ans<<endl;

	}
	cout<<ans;
}
