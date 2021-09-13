class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0) {
                nums[i] = n+1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(abs(nums[i]) <= n) {
                if(nums[abs(nums[i]) - 1] > 0) {
                    nums[abs(nums[i]) - 1] *= -1;
                }

            }
        }
        int ans = n+1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans = i+1;
                break;
            }
        }
        return ans;

    }
};
