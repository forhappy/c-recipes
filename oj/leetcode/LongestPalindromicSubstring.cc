class Solution {
public:
    string longestPalindrome(string src) {
        assert(!src.empty());
        if (src.size() == 1) return src;

        std::string::size_type start = 0;
        std::string::size_type max_palindorme_len = 0;
        std::string::size_type src_len = src.length();
        std::vector<std::vector<bool> > aux(src_len, std::vector<bool>(src_len));
        for (int i = 0; i < src_len; i++) {
            aux[i][i] = true;
            if (i + 1 < src_len) {
                if (src[i] == src[i + 1]) {
                    aux[i][i + 1] = true;
                    start = i;
                    max_palindorme_len = 2;
                }
                else aux[i][i + 1] = 0;
            }
        }

        for (int gap = 2; gap < src_len; gap++) {
            for (int i = 0; i < src_len - gap; i++) {
                if (aux[i + 1][i + gap - 1] == true && src[i] == src[i + gap]) {
                    aux[i][i + gap] = true;
                    if (max_palindorme_len <= gap) {
                        start = i;
                        max_palindorme_len = gap + 1;
                    }
                }
            }
        }

        return src.substr(start, max_palindorme_len);
    }
};
