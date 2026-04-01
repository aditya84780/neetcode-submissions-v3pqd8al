class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> arr(nums.size() + 1, 0);
        for(auto v: nums) {
            arr[v] = 1;
        }
        for(int i = 0; i<arr.size(); i++) {
            if(arr[i] == 0) return i;
        }
    }
};
