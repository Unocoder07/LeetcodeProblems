class Solution {
public:
   bool doesValidBinaryArrayExist(vector<int>& derived) {
    int n = derived.size();

    // Try both possible values for original[0]: 0 and 1
    for (int start = 0; start <= 1; start++) {
        vector<int> original(n);
        original[0] = start;

        // Reconstruct the original array using the derived array
        for (int i = 0; i < n - 1; i++) {
            original[i + 1] = original[i] ^ derived[i]; // Compute original[i+1]
            if (original[i + 1] < 0 || original[i + 1] > 1) {
                break; // If invalid value, stop further checks
            }
        }

        // Validate the circular condition for the last element
        if ((original[n - 1] ^ original[0]) == derived[n - 1]) {
            return true; // Found a valid binary array
        }
    }

    return false; // No valid binary array found
}

};