class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int maxfreq = 0;
        int rep = 0;
        int tail = 0, head = -1;
        int ans = 0;
        for (int r = 0; r<n; r++) {
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);
            if(r-tail+1 - maxfreq > k) {
                mp[s[tail]]--;
                tail++;
            }
            ans = max(ans, r-tail+1);
        }
        return ans;
    }
};
