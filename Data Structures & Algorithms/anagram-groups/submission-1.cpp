class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(string s: strs) {
            vector<int> arr(26,0);
            for(char c : s) {
                arr[c-'a']++;
            }
            string key = "";
            for(int num: arr) {
                key += to_string(num)+",";
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto x: mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
