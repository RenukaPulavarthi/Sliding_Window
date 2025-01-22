https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?page=1&category=sliding-window&status=solved&sortBy=submissions

from collections import deque
class Solution:
    #Function to find maximum of each subarray of size k.
    def maxOfSubarrays(self, arr, k):
        # code here
        de=deque()
        ans=[]
        for i in range(len(arr)):
            while len(de)!=0 and de[-1]<arr[i]:
                de.pop()
            de.append(arr[i])
            if i>=k:
                if de[0]==arr[i-k]:
                    de.popleft()
            if i>=k-1:
                ans.append(de[0])
        return ans
