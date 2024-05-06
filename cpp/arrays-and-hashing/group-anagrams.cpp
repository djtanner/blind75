#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        // create a hashmap to store the anagrams with the key being the alphabetical word
        std::unordered_map<string, vector<string>> hashMap;

        for (int i = 0; i < strs.size(); i++)
        {
            string myString = strs[i];
            string copyStr(myString);
            std::sort(copyStr.begin(), copyStr.end());

            // does not exist in map, so add it
            if (hashMap.find(copyStr) != hashMap.end())
            {
                hashMap.insert({copyStr, vector<std::string>()});
            }

            hashMap[copyStr].push_back(myString);
        }

        // iterate values of hashMap and add to result
        for (auto x : hashMap)
        {

            result.push_back(x.second);
        }

        return result;
    }
};