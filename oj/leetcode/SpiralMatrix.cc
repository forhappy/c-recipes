class Solution {
  public:

      std::vector<int> spiralOrder(std::vector<vecto <int> >&matrix) {
		if (matrix.size() < 1) {
			return std::vector <int>();
		}
        std::vector<int>ans;
		int left = 0;
		int right = matrix[0].size() - 1;
		int up = 0;
		int down = matrix.size() - 1;

		int count = matrix.size() * matrix[0].size();
		int flag = 0;

		while (ans.size() < count) {
			switch (flag) {
			case 0:			// left => right
				for (int i = left; i <= right; i++)
					ans.push_back(matrix[up][i]);
				up++;
				flag = 1;
				break;
			case 1:			// up => down
				for (int i = up; i <= down; i++)
					ans.push_back(matrix[i][right]);
				right--;
				flag = 2;
				break;
			case 2:			// right => left
				for (int i = right; i >= left; i--)
					ans.push_back(matrix[down][i]);
				down--;
				flag = 3;
				break;
			case 3:			// down => up
				for (int i = down; i >= up; i--)
					ans.push_back(matrix[i][left]);
				left++;
				flag = 0;
				break;
			};
		}
		return ans;
	}

};
