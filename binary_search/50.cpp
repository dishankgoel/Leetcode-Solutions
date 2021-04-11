class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        double xabs = abs(x);
        int nabs = abs(n);
        for(int i = 31; i >= 0; i--) {
            ans = ans*ans;
            if((1 << i)&nabs) {
                ans *= xabs;
            }
        }
        if(n < 0) {
            ans = 1/ans;
        }
        if(x < 0) {
            ans = n%2 == 0 ? ans : -ans;
        }
        return ans;
    }
};