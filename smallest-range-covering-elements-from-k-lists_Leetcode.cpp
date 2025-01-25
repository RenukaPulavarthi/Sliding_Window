//https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        vector<int>v(k,0);
        multiset<pair<int,int>>se;
        for(int i=0;i<k;i++){
            se.insert({nums[i][0],i});
        }
        int ans=INT_MAX;
        vector<int>a(2);
        // cout<<se.begin()->first;
        while(true){
            int maxi=se.rbegin()->first;
            int mini=se.begin()->first;
            if(maxi-mini<ans){
                a={mini,maxi};
                ans=maxi-mini;
            }
            int k=se.begin()->first;
            int l=se.begin()->second;
            if(v[l]+1>=nums[l].size()){
                break;
            }
            v[l]++;
            se.insert({nums[l][v[l]],l});
            se.erase(se.begin());
        }
        return a;
    }
};
