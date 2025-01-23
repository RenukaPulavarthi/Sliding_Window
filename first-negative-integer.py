#https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1?page=1&category=sliding-window&status=solved&sortBy=submissions

#User function Template for python3
from collections import deque
class Solution:
    def FirstNegativeInteger(self, arr, k): 
        de=deque()
        ans=[]
        for i in range(len(arr)):
            if arr[i]<0:
                de.append(arr[i])
            if i>=k:
                if len(de)!=0 and de[0]==arr[i-k]:
                    de.popleft()
            if i>=k-1:
                if len(de)!=0:
                    ans.append(de[0])
                else:
                    ans.append(0)
        return ans
                
            
                
                
                

