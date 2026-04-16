class DisjointSet{
    vector<int> rank;
    vector<int> size;
    vector<int> parent;
    public:
        DisjointSet(int n){
            rank.resize(n + 1 , 0);
            parent.resize(n + 1 , 0);
            size.resize(n + 1 , 0);

            for(int i = 0 ; i <= n ; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }

            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u , int v){
            int ulp = findUPar(u);
            int vlp = findUPar(v);

            if(ulp == vlp) return;

            if(rank[ulp] < rank[vlp]){
                parent[ulp] = vlp;
            }else if(rank[vlp] < rank[ulp]){
                parent[vlp] = ulp;
            }else{
                parent[ulp] = vlp;
                rank[ulp]++;
            }
        }

        void unionBySize(int u , int v){
            auto ulp = findUPar(u);
            auto vlp = findUPar(v);

            if(ulp == vlp) return;

            if(size[ulp] < size[vlp]){
                parent[ulp] = vlp;
                size[vlp]+= size[ulp];
            }else{
                parent[vlp] = ulp;
                size[ulp]+= size[vlp];
            }
        }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string , int> mapMailNode;

        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }else{
                    ds.unionBySize(i , mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

        for(auto& it : mapMailNode){
            auto mail = it.first;
            auto ind = it.second;

            auto node = ds.findUPar(ind);

            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> res;

        for(int i = 0 ; i < n; i++){
            if(mergedMail[i].size() == 0){
                continue;
            }
            sort(mergedMail[i].begin() , mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(int j = 0 ; j < mergedMail[i].size() ; j++){
                temp.push_back(mergedMail[i][j]);
            }
            res.push_back(temp);
        }

        return res;
    }
};