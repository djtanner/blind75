#include <vector>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // create a hashSet of nums
        std::unordered_set<int> hashSet;

        for (int i = 0; i < nums.size(); i++)
        {
            hashSet.insert(nums[i]);
        }

        int max = 0;

        // traverse nums, only count sequence if the set doesn't contain the number immediately preceding it

        for (int i = 0; i < nums.size(); i++)
        {

            if (hashSet.find(nums[i] - 1) == hashSet.end())
            {
                int val = nums[i];
                int count = 1;
                while (hashSet.find(val + 1) != hashSet.end())
                {
                    count++;
                    val += 1;
                }

                if (count > max)
                {
                    max = count;
                }
            }
        }

        return max;
    }
};