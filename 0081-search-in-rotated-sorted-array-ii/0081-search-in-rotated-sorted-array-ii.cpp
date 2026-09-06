class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n= nums.size();
       int low= 0;
       int high= n-1;

       while(low<= high){
        int mid= (low+high)/2;
        if(nums[mid]== target) return true;
        //error comes if low mid high are all same
        if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
            //then we reduce the search space ashte
            low++; high--;
            continue;//we'll continue untill we get different values for each indexes.
        }

        
        //if its in the left
        if(nums[low]<=nums[mid]){
            if(target>= nums[low]&& target< nums[mid]){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        //its on right side
        else{
            if(target> nums[mid]&& target<= nums[high]){
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
       }
       return false;
    }
};