class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n%2 != 0) return false;
        stack<char> st;
        for (int i = 0; i< n; i++) {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (!st.empty()) {
                char c = st.top();
                    switch (s[i]){
                        case ')':
                            if(c!='(') return false;break;
                        case '}':
                            if(c!='{') return false;break;
                        case ']':
                            if(c!='[') return false;break;
                    }
                    st.pop();
                } else return false;
            } else {
                st.push(s[i]);
            }
        }
        if(st.empty())
        return true;
        return false;
    }
};
