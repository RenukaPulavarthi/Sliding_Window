//https://codeforces.com/problemset/problem/580/B

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,d,k,l;
	cin>>n>>d;
	vector<pair<long long,long long>>arr;
	for(int i=0;i<n;i++){
		cin>>k>>l;
		arr.push_back({k,l});
	}
	sort(arr.begin(),arr.end());
	long long r=0,fri=0,ans=0;
	l=0;
	while(r<n){
	    fri+=arr[r].second;
	    //cout<<l<<' '<<r<<endl;
	    if(arr[r].first-arr[l].first<d){
	        ans=max(ans,fri);
	        r++;
	    }
	    while(arr[r].first-arr[l].first>=d){
	        fri-=arr[l].second;
	        l++;
	    }
	}
	cout<<ans;
}
