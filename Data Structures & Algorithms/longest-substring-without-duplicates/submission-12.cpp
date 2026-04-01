class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        int n = s.size();
        int l = 0;
        if(n == 0) return 0;
        unordered_map<char, int> mp;
        for(int h = 0; h<n; h++) {
            mp[s[h]]++;
            while(mp[s[h]] > 1) {
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, h-l+1);          
        }
        return ans;
    }
};
