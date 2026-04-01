class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> mapping;
        for(auto num: nums) {
            auto it = mapping.find(num);
            if(it == mapping.end()) {
                mapping[num] = 1;
            } else return true;
        }
        return false;
    }
};