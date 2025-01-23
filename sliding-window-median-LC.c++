//https://leetcode.com/problems/sliding-window-median/description/
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long>lo,hi;
        vector<double>ans;
        auto balance=[&](){
            if(lo.size()>hi.size()+1){
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }
            if(lo.size()<hi.size()){
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
        };
        for(int i=0;i<nums.size();i++){
            if(lo.size()==0 || nums[i]<= *lo.rbegin()){
                lo.insert(nums[i]);
                balance();
            }     
            else{
                hi.insert(nums[i]);
                balance();
            }
            if(i>=k){
                long long z=nums[i-k];
                auto it=lo.find(z);
                if(it!=lo.end()){
                    lo.erase(it);
                }
                else{
                    it=hi.find(z);
                    if(it!=hi.end())
                        hi.erase(hi.find(z));
                }
                balance();
            }
            if(i>=k-1){
                if(k%2==1) ans.push_back((double)*lo.rbegin());
                else{
                    ans.push_back(((double)*lo.rbegin()+(double)*hi.begin())/2.0);
                }
            }

        }
        return ans;
    }
};
