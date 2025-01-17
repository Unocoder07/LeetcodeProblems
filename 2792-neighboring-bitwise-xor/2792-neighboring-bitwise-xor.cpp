class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();
    for (int start = 0; start <= 1; start++) {
        vector<int> original(n);
        original[0] = start;
        for (int i = 0; i < n - 1; i++) {
            original[i + 1] = original[i] ^ derived[i];
            if (original[i + 1] < 0 || original[i + 1] > 1) break;
        }
        if ((original[n - 1] ^ original[0]) == derived[n - 1]) {
            return true;
        }
    }
    return false;
    }
};