//Given an array of integers where each value 1 <= x <= len(array), write a function that finds all the duplicates in the array.

//Solution -->

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            int index = abs(nums[i]) - 1;
            
            if(nums[index]<0)
            {
                result.push_back(abs(nums[i]));
            }
            else
            {
                nums[index] = -1*nums[index];
            }
        }
        return result;
    }
};