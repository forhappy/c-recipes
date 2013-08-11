class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        std::vector<std::vector<int> > result;
        std::sort(num.begin(), num.end());
        do {
            result.push_back(num);
        } while (std::next_permutation(num.begin(), num.end()));
        return result;
    }
};
