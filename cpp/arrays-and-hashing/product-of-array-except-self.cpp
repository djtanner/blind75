#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();

        int L[len];
        int R[len];
        vector<int> answer;

        L[0] = 1;
        for (int i = 1; i < len; i++)
        {
            L[i] = nums[i - 1] * L[i - 1];
        }

        R[len - 1] = 1;
        for (int i = len - 2; i >= 0; i--)
        {
            R[i] = nums[i + 1] * R[i + 1];
        }

        for (int i = 0; i < len; i++)
        {
            answer.push_back(L[i] * R[i]);
        }

        return answer;
    }
};