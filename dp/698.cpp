class Solution {
public:
    vector<int> A;
    int n, K;
    int total_sum;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        A = nums; n = nums.size(); K = k;
        total_sum = 0;
        for(auto a : nums) {total_sum += a;}
        if(total_sum%k != 0) {return false;}
        return recurse(total_sum/k, 0, 0, k);
    }

    bool recurse(int target, int start, int taken, int subleft) {
        if(subleft == 1) {
            return true;
        }
        if(target == 0) {
            return recurse(total_sum/K, 0, taken, subleft - 1);
        }
        bool ans = false;
        for(int i = start; i < n; i++) {
            if((taken&(1<<i)) == 0) {
                if(target - A[i] >= 0) {
                    ans = ans | recurse(target - A[i], i + 1, taken|(1<<i), subleft);
                }
            }
        }
        return ans;
    }
};