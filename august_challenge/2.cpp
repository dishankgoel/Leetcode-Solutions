class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> d;
	int n = nums.size();
	for(int i = 0; i < n; i++) {
		d[nums[i]] = i;
	}
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		int left = target - nums[i];
		if(d.find(left) != d.end()) {
			if(d[left] != i) {
				ans = {i, d[left]};
			}
		}
	}
	return ans;
    }
};
