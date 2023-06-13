bool isSafe(int newx, int newy, vector<vector<bool> >&vis, vector<vector<int>> &arr, int n){
         if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) 
            && vis[newx][newy] != 1 && arr[newx][newy] == 1){
                return true;
            }
            else
            return false;
}

void solve(int x, int y, int n, vector<string > &ans, 
            vector<vector<int>> &arr, vector<vector<bool> >&vis, string path){
                //Base case
                //destination reached
                if(x == n-1 && y == n-1){
                    ans.push_back(path);
                    return;
                }
                
                // from here we have four path
                //D, L, R, U
                //down moment
                
                vis[x][y] = 1;
                
                if(isSafe(x+1, y, vis, arr, n)){
                    solve(x+1, y, n, ans, arr, vis, path + 'D');
                }
                
                //left moment
                
                if(isSafe(x, y-1, vis, arr, n)){
                    solve(x, y-1, n, ans, arr, vis, path + 'L');
                }
                
                //right moment
                
                if(isSafe(x, y+1, vis, arr, n)){
                    solve(x, y+1, n, ans, arr, vis, path + 'R');
                }
                
                //Upword moment
                
                if(isSafe(x-1, y, vis, arr, n)){
                    solve(x-1, y, n, ans, arr, vis, path + 'U');
                }
                //returning time make it as 0
                vis[x][y] = 0;
            }
    
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        vector<string > ans;
        vector<vector<bool> >visited (n, vector<bool>(n, 0));
        string path = "";
        if(arr[0][0] == 0){
            return ans;
        }
        solve(0, 0, n, ans, arr, visited, path);
        return ans;
    }
