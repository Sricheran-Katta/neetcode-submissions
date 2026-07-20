// class UnionFind{
// private:
//     vector<int> parent;
// public:
//     UnionFind(int n){
//         parent.resize(n+1);
//         for(int i = 0; i < n + 1; i++){
//             parent[i] = i;
//         }
//     }
//     int find(int x){
//         if (parent[x] == x) return x;
//         return parent[x] = find(parent[x]);
//     }   
//     bool unite(int x, int y){
//         int rootX = find(x);
//         int rootY = find(y);
//         if (rootX == rootY)return false;
//         parent[rootY] = rootX;
//         return true; 
//     }
// };

class Solution {
private: 
    int find(int x, vector<int>& parent){
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // UnionFind dsu(n);
        // for(auto& edge : edges){
        //     int u = edge[0];
        //     int v = edge[1];
        //     if(!dsu.unite(u, v)){
        //         return {u, v};
        //     }
        // }
        // return {};
        vector<int> parent(n + 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int rootu = find(u, parent);
            int rootv = find(v, parent);
            if(rootu == rootv){
                return {u, v};
            }
            parent[rootv] = rootu; 
        }
        return {};
    }
};
