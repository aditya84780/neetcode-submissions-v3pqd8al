class Solution {
public:
    int n;
    vector<int> num_arr;
    int t;
    bool check_lowest(int x) {
        if(num_arr[x]<=num_arr[n-1]) {
            return true;
        }
        return false;
    }

    bool check_asc(int x) {
        if(num_arr[x] >= t){
            return true;
        }
        return false;
    }

    int bin_ser(int lo, int hi, int ans, function<bool(int)> check) {
        int mid;
        while(lo<=hi) {
            mid = lo + (hi-lo)/2;
            if(check(mid)) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        num_arr = nums;
        n = nums.size();
        t = target;
        int lo = 0, hi = n-1, lowest_index = -1;
        lowest_index = bin_ser(lo, hi, lowest_index, [this](int x) {return check_lowest(x);});
        cout<<"lowest_index: "<<lowest_index<<'\n';
        if(lowest_index!=-1) {
            lo = lowest_index;
            hi = n-1;
            int ans = -1;
            ans = bin_ser(lo, hi, ans, [this](int x) {return check_asc(x);});
            cout<<"ans: "<<ans<<'\n';
            if(ans != -1 && nums[ans] == target) {
                return ans;
            } else if(lowest_index != 0) {
                lo = 0;
                hi = lowest_index-1;
                ans = bin_ser(lo, hi, ans, [this](int x) {return check_asc(x);});
                cout<<"ans: "<<ans<<'\n';
                if(ans!=-1 && nums[ans] == target) {
                    return ans;
                }
            }
        }
        return -1;
    }
};
