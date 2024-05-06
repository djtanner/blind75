#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hashMap;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            int val = target - nums[i];

            auto iter = hashMap.find(nums[i]);
            if (iter != hashMap.end())
            {
                result.push_back(iter->second);
                result.push_back(i);
            }
            else
            {
                hashMap[val] = i;
            }
        }

        return result;
    }
};