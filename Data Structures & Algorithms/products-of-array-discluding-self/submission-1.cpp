class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> output;
        int num_zeros = 0;
        bool more_than_one_zeros = false;
        int product_no_zeros = 1;
        for (int num : nums) {
            product *= num;
            if (num == 0) {
                num_zeros++;
            } else {
                product_no_zeros *= num;
            }
        }
        if (num_zeros > 1) more_than_one_zeros = true;
        for(int num : nums) {
            if(product == 0 && more_than_one_zeros) output.push_back(0);
            else if(product == 0 && num == 0) {
                // if (num < 0) {
                //     output.push_back(abs(product)/abs(num));
                // }
                // else if (num > 0) {
                //     output.push_back(-1*(abs(product)/num));
                // } else {
                    output.push_back(product_no_zeros);
                // }
            }
            else output.push_back(product/num);
        }
        return output;
    }
};
