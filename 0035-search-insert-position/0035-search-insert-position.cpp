class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        target= lower_bound(nums.begin(), nums.end(), target) - nums.begin();
      return target; 
    }
    
};