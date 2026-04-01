class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it,nums.end());
        int i=0,j=1,n=nums.size();
        int maxsize = 1;
        while(j<n) {
            if (nums[j]-nums[j-1] == 1) {
                maxsize = max(maxsize, j-i+1);
                j++;
            } else {
                j++;
                i = j-1;
            }
        }
        if (nums.size() != 0)
        return maxsize;
        return 0;
    }
};
