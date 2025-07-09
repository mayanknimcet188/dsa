#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*Function to ... */
    vector<int> solve(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return {-1, -1};
    }
};

int main()
{
    int n = 5;
    vector<int> nums = {2, 6, 5, 8, 11};
    int target = 14;

    Solution sol;
    vector<int> ans = sol.solve(nums, target);
    cout << "This is the answer: [" << ans[0] << ", " << ans[1] << "]" << endl;
    return 0;
}