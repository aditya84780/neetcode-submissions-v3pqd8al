class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 1;
        if(n == 0) return 0;
        int taken = 0;
        int tail = 0, head = -1;
        unordered_map<char, int> freq;
        int max_freq = 0;
        while(tail<n) {
            while(head+1<n && (freq[s[head+1]] == max_freq || head+1-tail+1 - max_freq <=k)) {
                head++;
                freq[s[head]]++;
                max_freq = max(max_freq, freq[s[head]]);
            }
            ans = max(ans, head-tail+1);
            if(head<tail) {
                freq[s[tail]]--;
                tail++;
                head = tail-1;
            } else {
                freq[s[tail]]--;
                tail++;
            }
        }
        return ans;
        
    }
};
