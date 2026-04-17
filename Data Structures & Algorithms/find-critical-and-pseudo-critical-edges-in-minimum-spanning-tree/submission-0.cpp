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
private:
    int findMstWt(int n , vector<vector<int>>& edges , int skip , int force){

        DisjointSet ds(n);
        int mstWt = 0 ;
        int edgesUsed = 0 ;

        if(force != -1){
            auto& e = edges[force];
            ds.unionBySize(e[0] , e[1]);
            mstWt+= e[2];
            edgesUsed++;
        }

        for(int i = 0 ; i < edges.size(); i++){

            if(i == skip) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u , v);
                mstWt+= wt;
                edgesUsed++;
            }
        }

        if(edgesUsed != n-1) return INT_MAX;

        return mstWt;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {


        for(int i = 0 ; i < edges.size(); i++){
            edges[i].push_back(i);
        }

        sort(edges.begin() , edges.end() , [](auto & a , auto & b){
            return a[2] < b[2];
        });

        int baseCost = findMstWt(n , edges , -1 , -1);

        vector<int> critical , psedoCritical;

        for(int i = 0 ; i < edges.size(); i++){
            if(findMstWt(n , edges , i , -1) > baseCost){
                critical.push_back(edges[i][3]);
            }else if(findMstWt(n , edges , -1 , i) == baseCost){
                psedoCritical.push_back(edges[i][3]);
            }
        }

        return {critical , psedoCritical};

    }
};