class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.empty() || height.size() == 1) return 0;
        int start_pos = 0, end_pos = height.size() - 1;
        int max_area = (end_pos - start_pos)
                * std::min(height[start_pos], height[end_pos]);

        while (start_pos < end_pos) {
            int current_max_area = (end_pos - start_pos)
                        * std::min(height[start_pos], height[end_pos]);
                max_area = std::max(max_area, current_max_area);
            if (height[start_pos] < height[end_pos]) {
                start_pos++;
            } else {
                end_pos--;
            }
        }

        return max_area;
    }
};
