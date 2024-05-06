#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // add to set
        // if didn't add, then return true

        std::set<int> theSet;

        for (int i = 0; i < nums.size(); i++)
        {
            if (theSet.insert(nums[i]).second == false)
            {
                return true;
            }
        }

        return false;
    }
};