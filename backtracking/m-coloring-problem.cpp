#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>>& graph, int colors[], int v, int c) {
    for(int i = 1; i < graph.size(); ++i) {
        if(graph[v][i] == 1 and c == colors[i]) {
            return false;
        }
    }
    return true;
}

bool canBeColored(vector<vector<int>> graph, int colors[], int v, int m) {
    if(v == graph.size()) {
       return true;
    }
    for(int c = 1; c <= m; ++c) {
        if(isSafe(graph, colors, v, c)) {
            colors[v] = c;
            if(canBeColored(graph, colors, v + 1, m)) {
                return true;
            }
            colors[v] = 0;
        }
    }
    return false;
   
}

void solve() {
    int n, e, m;
    cin >> n >> m >> e;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    int colors[n + 1] = {0};
    for(int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    if(canBeColored(graph, colors, 1, m)) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
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
      