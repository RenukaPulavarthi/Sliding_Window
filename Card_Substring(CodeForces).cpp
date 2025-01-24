//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	string s,c;
	cin>>s>>c;
	map<char,long long>m1;
	map<char,long long>m2;
	for(int i=0;i<m;i++) m1[c[i]]++;
	long long l=0,r=0,ans=0;
	while(r<n){
		if(m2[s[r]]+1>m1[s[r]]){
			m2[s[l]]--;
			l++;
		}
		else{
			ans+=(r-l)+1;
			m2[s[r]]++;
			r++;
		}	
	}
	cout<<ans<<endl;
}
