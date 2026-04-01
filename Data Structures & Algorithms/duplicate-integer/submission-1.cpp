class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freq;
        bool hasDupe = false;
        for(auto num: nums) {
            if(freq[num]) {
                hasDupe = true;
                break;
            }
            freq[num]++;
        }
        return hasDupe;
    }
};