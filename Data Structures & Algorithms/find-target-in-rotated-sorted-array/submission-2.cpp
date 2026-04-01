class Solution {
public:
    int n;
    vector<int> num_arr;
    bool check(int x) {
        if(num_arr[x]<=num_arr[n-1]) {
            return true;
        }
        return false;
    }

    bool check_asc(int x, int target) {
        if(num_arr[x] >= target){
            return true;
        }
        return false;
    }
    int search(vector<int>& nums, int target) {
        num_arr = nums;
        n = nums.size();
        int lo = 0, hi = n-1, lowest_index = -1;
        int mid;
        while(lo<=hi) {
            mid = lo + (hi-lo)/2;
            if(check(mid)) {
                lowest_index = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        cout<<"lowest_index: "<<lowest_index<<'\n';
        if(lowest_index!=-1) {
            lo = lowest_index;
            hi = n-1;
            int ans = -1;
            while(lo<=hi) {
                mid = lo + (hi-lo)/2;
                if(check_asc(mid, target)) {
                    ans = mid;
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            }
            cout<<"ans: "<<ans<<'\n';
            if(ans != -1 && nums[ans] == target) {
                return ans;
            } else if(lowest_index != 0) {
                lo = 0;
                hi = lowest_index-1;
                while(lo<=hi) {
                    mid = lo + (hi-lo)/2;
                    if(check_asc(mid, target)) {
                        ans = mid;
                        hi = mid-1;
                    } else {
                        lo = mid+1;
                    }
                }
                cout<<"ans: "<<ans<<'\n';
                if(ans!=-1 && nums[ans] == target) {
                    return ans;
                }
            }
        }
        return -1;
    }
};
