#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*Function to ... */
    bool search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target || nums[left] == target || nums[right] == target)
            {
                return true;
            }
            if (nums[left] == nums[right])
            {
                // we have to decide which part to search, because the left part may contain from of the rotoated elements
                left++;
                right--;
            }
            else if (nums[left] <= nums[mid])
            {
                // left half is sorted
                if (nums[left] <= target && target <= nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                // right half is sorted
                if (nums[mid] <= target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    int n = 5;
    vector<int> nums = {0, 1, 1, 2, 0, 0};
    int target = 2;

    Solution sol;
    bool ans = sol.search(nums, target);
    if (ans)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}