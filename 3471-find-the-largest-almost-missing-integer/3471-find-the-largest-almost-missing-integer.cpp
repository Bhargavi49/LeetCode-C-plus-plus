class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> cnt;

        for(int i = 0; i <= n-k; i++){
            set<int> st;

            for(int j = i; j < i+k; j++){
                st.insert(nums[j]);
            }

            for(int x : st){
                cnt[x]++;
            }
        }

        int ans = -1;

        for(auto it : cnt){
            if(it.second == 1){
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};