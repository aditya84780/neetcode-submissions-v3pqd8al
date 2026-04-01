class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> count(26, 0); // Use a vector for speed over map
        int maxfreq = 0;
        int tail = 0;
        int ans = 0;

        for (int head = 0; head < n; head++) {
            // 1. Expand the window: add current character
            count[s[head] - 'A']++;
            maxfreq = max(maxfreq, count[s[head] - 'A']);

            // 2. Check if window is valid: (length - maxfreq) = number of replacements needed
            // If replacements needed > k, shrink from the left
            if ((head - tail + 1) - maxfreq > k) {
                count[s[tail] - 'A']--;
                tail++;
                // Note: We don't need to update maxfreq here! 
                // The answer only improves if we find a NEW higher maxfreq.
            }

            // 3. Update the global maximum length
            ans = max(ans, head - tail + 1);
        }
        return ans;
    }
};