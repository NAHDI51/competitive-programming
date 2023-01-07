class Solution {
public:
void dfs(int i, unordered_multimap<int, int> &m, vector<vector<int>>& res) {
    auto it = m.find(i);
    while(it != end(m)) {
        int j = it->second;
        m.erase(it);
        dfs(j, m, res);
        res.push_back({i, j});
        it = m.find(i);
    }
}
vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    unordered_multimap<int, int> m;
    unordered_map<int, int> cnt;
    vector<vector<int>> res;
    for (auto &p : pairs) {
        m.insert({p[0], p[1]});
        ++cnt[p[0]];
        --cnt[p[1]];
    }
    auto head = find_if(begin(cnt), end(cnt), [&](const auto &p){ return p.second > 0; });
    dfs(head != end(cnt) ? head->first : pairs[0][0], m, res);
    reverse(begin(res), end(res));
    return res;
}
};