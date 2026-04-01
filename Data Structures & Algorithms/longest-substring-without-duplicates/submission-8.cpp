class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size();
        int longest = 0;
        unordered_map<char, int> mp;
        while(r<n) {
            if(mp.find(s[r]) != mp.end()) {
                l=max(mp[s[r]]+1, l);
            }
                longest = max(longest, r-l+1);
                mp[s[r]] = r;
                r++;
        }
        return longest;
    }
};
