//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

//Solution

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = 0;
        int i = 0;
        int j = 0;
        vector<int> result;
        while(i<m && j <n)
        {
            if(nums1[i]<=nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else
            {
                result.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m)
        {
                result.push_back(nums1[i]);
                i++;  
        }
        while(j<n)
        {
            result.push_back(nums2[j]);
            j++;
        }
        for(int i=0;i<result.size();i++)
        {
            nums1[i] = result[i];
        }
        
    }
};
