#include<bits/stdc++.h>

using namespace std;

bool dictionaryContains(string sub, vector<string>& dict) {
    int n = dict.size();
    for(int i = 0; i < n; ++i) {
        if(dict[i].compare(sub) == 0) 
            return true;
    }
    return false;
}

bool wordBreak(string s, vector<string>& dict) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    vector<int> doneIndex;
    doneIndex.push_back(-1);
    for(int i = 0; i < n; ++i) {
        int k = doneIndex.size();
        bool flag = false;
        for(int j = k - 1; j >= 0; --j) {
            string sub = s.substr(doneIndex[j] + 1, i - doneIndex[j]);
            if(dictionaryContains(sub, dict)) {
                flag = true;
                break;
            }
        }
        
        if(flag) {
            dp[i] = true;
            doneIndex.push_back(i);
        }
    }
    
    return dp[n - 1];
}

void solve(){
    int n;
    cin >> n;
    vector<string> dict;
    for(int i = 0; i < n; ++i) {
        string l;
        cin >> l;
        dict.push_back(l);
    }
    string s;
    cin >> s;
    if(wordBreak(s, dict)) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long t;
	cin>>t;
	while(t--){
        solve();
    
    }
	
	return 0;
}