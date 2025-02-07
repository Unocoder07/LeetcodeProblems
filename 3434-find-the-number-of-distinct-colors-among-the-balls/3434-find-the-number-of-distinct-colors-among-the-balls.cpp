class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mapping;
        unordered_map<int, int> count;
        vector<int> result;
        for (auto& query : queries) {
            int x = query[0];
            int y = query[1];
            count[y]++;
            if (mapping.contains(x) && --count[mapping[x]] == 0) {
                count.erase(mapping[x]);
            }

            mapping[x] = y;
            result.push_back(count.size());
        }
      
        return result;
    }
};