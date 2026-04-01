class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n), pref(n), suff(n);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i = 1; i< nums.size(); i++) {
            pref[i] = nums[i]*pref[i-1];
            suff[n-i-1] = nums[n-i-1] * suff[n-i];
        }
        output[0] = suff[1];
        output[n-1] = pref[n-2];
        for(int i = 1; i< n-1; i++) {
            output[i] = pref[i-1]*suff[i+1];
        }
        return output;
    }
};
