#https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1?page=1&category=sliding-window&status=solved&sortBy=submissions
class Solution:
    def countDistinct(self, arr, k):
        # Code here
        d={}
        for i in range(k):
            if arr[i] not in d:
                d[arr[i]]=0
            d[arr[i]]+=1
        i=0
        j=k
        ans=[len(d)]
        while j<len(arr):
            d[arr[i]]-=1
            if d[arr[i]]<=0:
                del d[arr[i]]
            i+=1
            if arr[j] not in d:
                d[arr[j]]=0
            d[arr[j]]+=1
            ans.append(len(d))
            j+=1
            #print(d)
        return ans
            
