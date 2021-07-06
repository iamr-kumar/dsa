class Solution {
public:
    string say(string s){
        int count = 1;
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i] == s[i+1]){
                count++;
            }
            else{
                res = res + to_string(count) + s[i];
                count = 1;
            }
        }
        return res;
    }
    string countAndSay(int n) {
        string s="1";
        for(int i=2;i<=n;i++){
            s = say(s);
        }
        return s;
    }
    
};