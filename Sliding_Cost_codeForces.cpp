// https://codeforces.com/gym/102961/problem/ZG
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	vector<long long>v(n);
	vector<long long>ans;
	for(int i=0;i<n;i++) cin>>v[i];
	multiset<long long>lo,hi;
	long long low=0,high=0;
	auto balance=[&](){
	    if(lo.size()>hi.size()+1){
			hi.insert(*lo.rbegin());
			high+=*lo.rbegin();
			low-=*lo.rbegin();
			lo.erase(prev(lo.end()));
		}
		if(lo.size()<hi.size()){
			lo.insert(*hi.begin());
			low+=*hi.begin();
			high-=*hi.begin();
			hi.erase(hi.begin());
		}
		
	};
	for(int i=0;i<n;i++){
		if(lo.empty() || v[i]<=*lo.rbegin())
		{
			lo.insert(v[i]);
			low+=v[i];
		}
		else{
			hi.insert(v[i]);
			high+=v[i];
		}
		balance();
		
		if(i>=k){
			long long z=v[i-k];
			auto it=lo.find(z);
			if(it!=lo.end()){
				lo.erase(it);
				low-=z;
			}
			else{
				it=hi.find(z);
				if(it!=hi.end()){
					hi.erase(it);
					high-=z;
				}
			}
			balance();
		}
		if(i>=k-1){
		    
			long long m=*lo.rbegin();
			ans.push_back((m*(int)lo.size())-low+high-((int)hi.size()*m));
		}
	}
	for(int i=0;i<(int)ans.size();i++){
		cout<<ans[i]<<" ";
	}
}
