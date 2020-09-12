#include<bits/stdc++.h>

using namespace std;

bool checkDictHas(string prefix, vector<string>& dict) {
    for(int i = 0; i < dict.size(); ++i) {
        if(!dict[i].compare(prefix))
            return true;
    }
    return false;
}

void wordBreak(string s, int n, string result, vector<string>& dict) {
    for(int i = 0; i <=n; ++i) {
        string prefix = s.substr(0, i);
        if(checkDictHas(prefix, dict)) {
            if(i == n) {
                result += prefix;
                cout << "(" << result << ")";
                return;
            }
            wordBreak(s.substr(i, n - i), n - i, result + prefix + " ", dict);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<string> dict;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        dict.push_back(s);
    }
    string l;
    cin >> l;
    wordBreak(l, l.size(), "", dict);
    cout << "\n";
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