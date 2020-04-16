//Given an unsorted array, find the length of the longest sequence of consecutive numbers in the array.

//Solution -->

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<long long int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int maximum = 0;
        for(auto x: s)
        {
            if(s.count(x-1) == 1)
            {
                continue;
            }
            int length = 0;
            while(s.count(x++) == 1)
            {
                length++;
            }
            maximum = max(maximum,length);
        }
        return maximum;
    }
};