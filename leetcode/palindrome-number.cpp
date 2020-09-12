class Solution {
public:
    bool isPalindrome(int x) {
        int halfRev = 0;
        // If number is negative or divisible by 10, return false
        if(x < 0 or (x % 10 == 0 and x > 0) ) 
            return false;
        else{
            // Reverse half of the number
            while(x > halfRev){
                int p = x % 10;
                halfRev = halfRev * 10 + p;
                x /= 10;
            }
            if(halfRev == x or halfRev/10 == x) return true;
            return false;
        }
    }
};