class Solution {
private:
    void solve(int ind , int n , int k ,  vector<vector<int>>& res , vector<int>& output){

        if(k == 0){
            res.push_back(output);
            return ;
        }
        
        if(ind > n){
            return;
        }

        
        for(int i = ind ; i <= n ; i++){
            output.push_back(i);
            solve(i + 1 , n , k - 1, res , output);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> output;

        solve(1 , n , k , res , output);

        return res;
    }
};