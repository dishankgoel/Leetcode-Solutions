class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> all, curr;
        for(int i = 0; i < arr.size(); i++) {
            set<int> temp;
            for(auto itr = curr.begin(); itr != curr.end() ;++itr) {
                int val = *itr;
                temp.insert(val | arr[i]);
                all.insert(val | arr[i]);
            }
            temp.insert(arr[i]);
            all.insert(arr[i]);
            curr = temp;
        }
        return all.size();
    }
};