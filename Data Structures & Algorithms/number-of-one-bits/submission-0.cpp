class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(uint32_t i = 0; i<32; i++) {
            cout<<"i = "<<i<<" 1<<i = "<<(1<<i)<<" n&(1<<i) = "<<(n&(1<<i))<<'\n';
            if((n&(1<<i))!=0) {
                count++;
            }
            // count += ((n&(1<<i)==0)?0:1);
        }
        return count;
    }
};
