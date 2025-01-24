//https://codeforces.com/contest/645/problem/C

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,c;
	cin>>n>>c;
	string s;
	cin>>s;
	vector<long long>arr;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') arr.push_back(i);
	}
	long long l=0,r=c,f=0;
	long long ans=INT_MAX;
	while(r<arr.size()){
		long long z=max(arr[f]-arr[l],arr[r]-arr[f]);
		long long y=max(arr[f+1]-arr[l],arr[r]-arr[f+1]);
		if(z>=y){
			f++;
		}
		else{
			ans=min(ans,z);
			l++;
			r++;
		}
	}
	cout<<ans;
}
