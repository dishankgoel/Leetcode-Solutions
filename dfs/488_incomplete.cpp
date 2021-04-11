class Solution {
public:
    int ans;
    string insert_ball(string curr, int i, char new_ball) {
        int n = curr.size();
        string new_string;
        if(i == 0) {
            if(n >= 2) {
                if(curr[0] == new_ball && curr[1] == new_ball) {
                    new_string = curr.substr(2, n - 2);
                } else {
                    new_string = curr;
                    new_string.insert(0, 1, new_ball);    
                }
            } else {
                new_string = curr;
                new_string.insert(0, 1, new_ball);
            }
        } else if(i == n + 1) {
            if(n >= 2) {
                if(curr[n - 1] == new_ball && curr[n-2] == new_ball) {
                    new_string = curr.substr(0, n - 2);
                } else {
                    new_string = curr;
                    new_string.insert(0, 1, new_ball);
                }
            } else {
                new_string = curr;
                new_string.insert(0, 1, new_ball);
            }
        } else {
            if(curr[i-1] == new_ball && curr[i] == new_ball) {
                new_string = curr.substr(0, i - 1) + curr.substr(i + 1, n - (i + 1));
            } else {
                new_string = curr.substr(0, i);
                new_string.push_back(new_ball);
                new_string += curr.substr(i, n - i);
            }
        }
        return new_string;
    }
    void dfs(string board, string hand, int curr_step) {

        for(int i = 0; i < hand.size(); i++) {
            for(int j = 0; j < board.size() + 1; j++) {
                string new_string = insert_ball(board, j, hand[i]);
                if(new_string == "") {
                    ans = max(ans, curr_step + 1);
                } else {
                    string new_hand;
                    new_hand = hand.substr(0, i) + hand.substr(i + 1, hand.size() - (i + 1));
                    dfs(new_string, new_hand, curr_step + 1);
                }
            }
        }
    }

    int findMinStep(string board, string hand) {
        int m = board.size();
        int n = hand.size();
        ans = INT_MAX;
        dfs(board, hand, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};