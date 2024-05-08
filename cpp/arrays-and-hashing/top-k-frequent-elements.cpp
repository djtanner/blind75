#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // get frequencies by hashmap

        std::unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hashMap.find(nums[i]) == hashMap.end())
            {
                hashMap[nums[i]] = 1;
            }
            else
            {
                int value = hashMap[nums[i]];
                hashMap[nums[i]] = value + 1;
            }
        }

        // Create a vector of pairs from the unordered_map
        std::vector<std::pair<int, int>> vec(hashMap.begin(), hashMap.end());

        // Sort the vector based on the values (second element of the pair)
        std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
                  {
                      return a.second > b.second; // Sorts in descending order by values
                  });

        std::vector<int> result;
        // get top k elements
        for (int i = 0; i < k; i++)
        {
            result.push_back(vec[i].first);
        }

        return result;
    }
};