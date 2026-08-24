class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // can be directly used shortcuts for coding for fidning lower bound
    //     target= lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    //   return target; 

    int n= nums.size();
    int low=0;
    int high= n-1;
    int ans=n;// = n because if theres nothing it'll assume as last index and return that ok
    while(low<=high){
        int mid= (low+high)/2;
        if(nums[mid]>= target){
            ans= mid;
            high= mid -1;
        }
        else{
            low= mid+1;
        }
    }
    return ans;
    }
    
};