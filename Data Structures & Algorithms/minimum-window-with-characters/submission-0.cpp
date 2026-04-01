class Solution {
public:
    string minWindow(string s, string t) {
        int head = -1, tail = 0;
        unordered_map<char,int> needmap, havemap;
        int needcount = 0;
        int havecount = 0;
        for(char c: t) {
            needmap[c]++;
        }
        for(auto v: needmap) {
            needcount++;
            cout<<v.first<<": "<<v.second<<'\n';
        }
        int n = s.size(), len = 1e9;
        pair<int,int> ansI = make_pair(-1,-1);
        while(tail<n) {
            while(head+1<n && needcount > havecount) {
                head++;
                if(needmap.contains(s[head])) {
                    havemap[s[head]]++;
                    if(havemap[s[head]] == needmap[s[head]]) {
                        havecount++;
                    }
                }
            }

            if(len > head-tail+1 && needcount == havecount) {
                for(auto v: needmap) {
                    if(havemap[v.first] < v.second) continue;
                }
                cout<<"head: "<<head<<" tail: "<<tail<<'\n';
                len = head-tail+1;
                ansI = make_pair(tail, head);
            }
            
            if(head<tail) {
                if(needmap.contains(s[tail])) {
                    if(havemap[s[tail]] == needmap[s[tail]]) {
                        havecount--;
                    }
                    havemap[s[tail]]--;
                }
                tail++;
                head = tail-1;
            } else {
               if(needmap.contains(s[tail])) {
                    if(havemap[s[tail]] == needmap[s[tail]]) {
                        havecount--;
                    }
                    havemap[s[tail]]--;
                } 
                tail++;
            }
        }
        if(ansI.first == -1) return "";
        return s.substr(ansI.first, len);
    }
};
