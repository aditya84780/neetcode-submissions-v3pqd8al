class Solution {
public:
    int n;
    vector<int> num_arr;
    bool check(int mid) {
        if(num_arr[mid] <= num_arr[n-1]) {
            return true;
        }
        return false;
    }
    int findMin(vector<int> &nums) {
        num_arr = nums;
        n = nums.size();
        int lo = 0, hi = n-1, ans = -1;
        int mid;
        while(lo<=hi) {
            mid = lo + (hi-lo)/2;
            if(check(mid)) {
                hi = mid-1;
                ans = mid;
            } else {
                lo = mid+1;
            }
        }
        return nums[ans];
    }
};
