class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        for (string s : strs) {
            encoded_str += s;
            encoded_str += "`";
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> decoded_str;
        string temp = "";
        for(char c : s) {
            if(c == '`') {
                decoded_str.push_back(temp);
                temp = "";
            }
            else temp += c;
        }
        return decoded_str;
    }
};
