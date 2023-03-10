#include <queue>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int ans = 0;
        if(n == 1) return ans;
        long long totalSum = 0;
        long long topKSum = 0;
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i - 1];
            if(diff <= 0) {
                ans = i;
                continue;
            } 
            if(q.size() < ladders) {
                topKSum += diff;
                q.push(diff);
            } else if(q.size() > 0) {
                if(diff > q.top()) {
                    int lowest = q.top();
                    q.pop();
                    q.push(diff);
                    topKSum = topKSum - lowest + diff;
                }
            }
            totalSum += diff;
            if(totalSum - topKSum <= bricks) {
                ans = i;
            } else {
                break;
            }
        }
        return ans;
    }
};
