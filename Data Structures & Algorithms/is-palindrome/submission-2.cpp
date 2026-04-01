class Solution {
public:
    bool isAlphaNum(char c) {
        return ((c>='A' && c<='Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
    }
    bool isPalindrome(string s) {
        int st = 0, en = s.size() - 1;
        while (st<en) {
            while (st < en && !isAlphaNum(s[st])) {
                st++;
            } 
            while(st < en && !isAlphaNum(s[en])) {
                en--;
            } 
            if(tolower(s[st]) != tolower(s[en])) {
                return false;
            }
            st++;
            en--;
        }
        return true;
    }
};
