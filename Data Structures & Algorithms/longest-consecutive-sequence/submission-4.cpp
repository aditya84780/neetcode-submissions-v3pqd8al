class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> lenmap;
        int maxsize = 0;
        for(int num: nums) {
            if(lenmap[num]) continue;
            int len = lenmap[num-1] + lenmap[num+1] + 1;
            lenmap[num] = len;
            lenmap[num-lenmap[num-1]] = len;
            lenmap[num+lenmap[num+1]] = len;
            maxsize = max(maxsize, len);
        }
        return maxsize;
    }
};
