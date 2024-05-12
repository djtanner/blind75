#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> result;
        if (nums.size() < 3)
        {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size() - 3 && nums[i] <= 0; i++)
        {
            if (i == 0 || nums[i - 1] != nums[i])
            {
                searchPairs(i, nums, result);
            }
        }

        return result;
    }

    void searchPairs(int index, vector<int> &nums, vector<vector<int>> &result)
    {
        int target = -(nums[index]);
        // if(index >= 1 && nums[index] == nums[index-1]){ return; }

        int ptr1 = index + 1;
        int ptr2 = nums.size() - 1;

        while (ptr1 < ptr2)
        {
            vector<int> triplet;
            // found a match
            if (nums[ptr1] + nums[ptr2] == target)
            {
                triplet.push_back(nums[index]);
                triplet.push_back(nums[ptr1]);
                triplet.push_back(nums[ptr2]);
                result.push_back(triplet);
                ptr1++;
                while (ptr1 < ptr2 && nums[ptr1] == nums[ptr1 - 1])
                {
                    ptr1++;
                }
            }
            // too big,  move ptr2 back
            if (nums[ptr1] + nums[ptr2] > target)
            {
                ptr2--;
            }

            // too small, move ptr1 fwd
            if (nums[ptr1] + nums[ptr2] < target)
            {
                ptr1++;
            }
        }

        return;
    }
};