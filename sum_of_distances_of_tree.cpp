class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0), subtree_count(n, 1);
        vector<vector<int>> g(n);
        for (auto x : edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        auto pre_calc = [&](int node, int parent, auto &pre_calc) -> void {
            for(auto nbr: g[node]){
                if(nbr != parent){
                    pre_calc(nbr, node, pre_calc);
                    subtree_count[node] += subtree_count[nbr];
                    ans[node] += ans[nbr] + subtree_count[nbr];
                }
            }
        };
        pre_calc(0, -1, pre_calc);
        auto final = [&](int node, int parent, auto &final) -> void {
            for(auto nbr: g[node]) {
                if(nbr != parent){
                    ans[nbr] = ans[node] - subtree_count[nbr] + n - subtree_count[nbr];
                    final(nbr, node, final);
                }
            }
        };
        final(0, -1, final);
        return ans;
    }
};