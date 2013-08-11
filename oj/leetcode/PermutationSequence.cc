class Solution {
public:
    string getPermutation(int n, int k) {
        int permutation_generated = 0;
        std::string str, result;
        for (int i = 1; i <= n; i++) {
            char c = i + 48; // Generate 'i'.
            str.push_back(c);
        }
        do {
            result = str;
            permutation_generated++;
        } while (std::next_permutation(str.begin(), str.end()) && permutation_generated != k);
        return result;
    }
};
