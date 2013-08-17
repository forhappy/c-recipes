class Solution {
public:
    int longestValidParentheses(string s) {
        int s_size = s.size();
        if (2 > s_size)
            return 0;
        int start = s_size + 1;
        int end;
        int max_length = 0;
        int curr_length = 0;
        stack<int> st;
        for (end = 0; end < s_size; ++end) {
            // Meet a (
            if ('(' == s[end]) {
                st.push(end);
                continue;
            }
            // Meet a )
            if (st.empty()) {
                start = s_size + 1;
            } else {
                start = min(st.top(), start);
                st.pop();
                if (st.empty()) {
                    curr_length = end - start + 1;
                } else {
                    curr_length = end - st.top();
                }
                max_length = max(max_length, curr_length);
            }
        }
        return max_length;
    }
};
