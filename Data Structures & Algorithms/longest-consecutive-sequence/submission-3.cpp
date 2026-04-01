class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> store(nums.begin(), nums.end());
        int maxsize = 0;
        for(int num : store) {
            if(store.find(num-1) == store.end()) {
                int i = 0;
                while(store.find(num+i) != store.end()) {
                    i++;
                }
                maxsize = max(maxsize,i);
            }
        }
        return maxsize;
    }
};
