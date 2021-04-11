class Solution {
public:
    vector<int> arr;
    bool solve(int p1, int p2, int i, int j, int turn) {
        bool ans;
        if(turn) {
            if(i == j) {
                return p1 + arr[i] >= p2 ? true : false;
            }
            ans = !solve(p1 + arr[i], p2, i + 1, j, 0) || !solve(p1 + arr[j], p2, i, j - 1, 0);
        }else {
            if(i == j) {
                return p1 < p2 + arr[i] ? true : false;
            }
            ans = !solve(p1, p2 + arr[i], i + 1, j, 1) || !solve(p1, p2 + arr[j], i, j - 1, 1);
        }
        return ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        arr = nums;
        return solve(0, 0, 0, arr.size() - 1, 1);
    }
};
