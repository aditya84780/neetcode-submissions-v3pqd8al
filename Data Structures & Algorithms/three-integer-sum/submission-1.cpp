class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int i = 0, n = nums.size();
        int k = n-1;
        sort(nums.begin(), nums.end());
        for(int j = 1; j< n-1; j++) {
            while(i<j && j<k) {
                if(nums[i] + nums [j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.insert(temp);
                    i++;
                    k--;
                } else if (nums[i] + nums [j] + nums[k] < 0) {
                    i++;
                } else {
                    k--;
                }
            }
            i = 0; k = n-1;
        }
        vector<vector<int>> vectorisedAns;
        for(auto v: ans) {
            vectorisedAns.push_back(v);
        }
        return vectorisedAns;
    }
};
