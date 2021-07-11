// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int x[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	    int y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	    
	    int len = word.length();
	    
	    vector<vector<int>> ans;
	    for(int row = 0; row < grid.size(); ++row) {
	        for(int col = 0; col < grid[row].size(); ++col) {
	            bool flag = false;
	            if(word[0] != grid[row][col]) {
	                continue;
	            }
	            for(int dir = 0; dir < 8; ++dir) {
	                int r = row + x[dir], c = col + y[dir];
	                int k;
	                for(k = 1; k < len; ++k) {
	                    if(r < 0 or r >= grid.size() or c < 0 or c >= grid[row].size())
	                        break;
	                    if(word[k] == grid[r][c]) {
	                        r += x[dir];
	                        c += y[dir];
	                        continue;
	                    } else {
	                        break;
	                    }
	                }
	                
	                if(k == len) {
	                    flag = true;
	                    break;
	                }
	                
	            }
	            if(flag) {
	                ans.push_back({row, col});
	            } 
	        }
	        
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}