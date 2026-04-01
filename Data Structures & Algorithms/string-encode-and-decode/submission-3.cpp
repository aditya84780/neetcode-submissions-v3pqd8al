class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        vector<int> sizes;
        for(string str : strs) {
            encoded_str += to_string(str.size());
            encoded_str+=",";
        }
        encoded_str += "#";
        for (string s : strs) {
            encoded_str += s;
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> decoded_str;
        vector<int> sizes;
        string temp = "";
        int delimpos = 0;
        for(char c : s) {
            if(c == '#') break;
            if(c == ',') {
                sizes.push_back(stoi(temp));
                temp = "";
            }
            else temp += c;
            delimpos++;
        }
        string to_be_decoded = s.substr(delimpos+1, s.size() - delimpos - 1);
        int itr = 0;
        for (int sz : sizes) {
            string word = to_be_decoded.substr(itr, sz);
            decoded_str.push_back(word);
            itr += sz;
        }

        return decoded_str;
    }
};
