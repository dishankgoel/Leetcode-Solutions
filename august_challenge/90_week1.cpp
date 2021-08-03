class Solution {
public:
	vector<vector<int>> ans;
	int check_present(vector<int> arr) {
		vector<int> a = arr;
		sort(a.begin(), a.end());
		for(int i = 0; i < ans.size(); i++) {
			vector<int> b = ans[i];
			sort(b.begin(), b.end());
			if(a == b) {return 1;}
		}
		return 0;
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	    int n = nums.size();
	    for(int i = 0; i < (1<<n); i++) {
		    int j = 0;
		    vector<int> curr;
		    while((1<<j) <= i) {
			if(((1<<j)&i) > 0) {
				curr.push_back(nums[j]);
			}
			j++;
		    }
		    if(check_present(curr) == 0) {
			ans.push_back(curr);
		    }
	    }
	    return ans;

    }
};
