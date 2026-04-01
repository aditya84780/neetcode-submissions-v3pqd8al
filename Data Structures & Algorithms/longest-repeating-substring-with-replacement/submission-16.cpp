class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int maxfreq = 0;
        int rep = 0;
        int tail = 0, head = -1;
        int ans = 0;
        while(tail<n) {
            while (head+1 < n && (head+1-tail+1 - maxfreq <= k || mp[s[head+1]] == maxfreq)) {
                head++;
                mp[s[head]]++;
                maxfreq = max(maxfreq, mp[s[head]]);
            }
            ans = max(ans, head-tail+1);
            if(head<tail) {
                mp[s[tail]]--;
                tail++;
                head = tail-1;
            } else {
                mp[s[tail]]--;
                tail++;
            }
        }
        return ans;
    }
};
