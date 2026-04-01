class Solution {
public:
vector<int> num, canDos;
int n;
bool rec(int pos) {
    if(pos >= n-1) return true;
    if(num[pos] == 0) return false;
    if(canDos[pos] != -1) return canDos[pos];
    int maxJump = num[pos];
    bool canDo = false;
    for(int i = pos+1; i<=pos+maxJump; i++) {
        canDo |= rec(i);
    }
    return canDos[pos] = canDo;
}
    bool canJump(vector<int>& nums) {
        int pos = 0;
        num = nums;
        n = num.size();
        canDos.resize(n, -1);
        return rec(0);
    }
};
