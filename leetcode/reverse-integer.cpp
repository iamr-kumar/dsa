class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x){
            int p = x % 10;

            // Handling overflow situations!!!
            if(ans > INT_MAX/10 or (ans == INT_MAX/10 and p > 7)) 
                return 0;
            if(ans < INT_MIN/10 or (ans == INT_MIN/10 and p < -8)) 
                return 0;
            // Handling overflow situations!!!
            ans = ans * 10 + p;
            
            x /= 10;
        }
        return ans;
    }
};