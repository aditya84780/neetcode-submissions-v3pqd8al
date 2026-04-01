class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total_xor = 0;
        for(auto v: nums) {
            total_xor ^= v;
        }
        int entire_xor = 0;
        int n = nums.size();
        for(int i = 0; i<=n; i++) {
            entire_xor ^= (i);
        }
        return total_xor^entire_xor;
    }
};
