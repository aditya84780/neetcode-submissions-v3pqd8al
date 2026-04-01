class Solution {
public:
int n;
int dp[1010];
vector<int> num_arr;
    int rec(int level) {
        if(level<0 || level>=n) return 0;
        if(level == 0) return 1;
        if(dp[level]!=-1) return dp[level];
        int ans = 1;
        for(int i = 0; i<level; i++) {
            if(num_arr[i] < num_arr[level]){
                ans = max(ans, rec(i) + 1);
            }
        }
        cout<<"level = "<<level<<", ans = "<<ans<<'\n';
        return dp[level] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        num_arr = nums;
        for(int i =0; i<n; i++) {
            dp[i] = -1;
        }
        int ans = 1;
        for(int i = 0; i<n; i++) {
            ans= max(ans, rec(i));
        }
        return ans;
    }
};
