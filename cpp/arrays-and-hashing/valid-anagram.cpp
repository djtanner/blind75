#include <unordered_map>
#include <string>

using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // first check they are the same size
        if (s.length() != t.length())
        {
            return false;
        }

        // make a hashmap of the chars in s
        std::unordered_map<char, int> myMap;

        for (int i = 0; i < s.length(); i++)
        {
            if (myMap.find(s[i]) == myMap.end())
            {
                myMap[s[i]] = 1;
            }
            else
            {
                myMap[s[i]] = myMap[s[i]] + 1;
            }
        }

        // iterate through t and decrement the hashmap for each char
        for (int i = 0; i < t.length(); i++)
        {
            if (myMap.find(t[i]) == myMap.end())
            {
                return false;
            }
            if (myMap[t[i]] == 0)
            {
                return false;
            }

            myMap[t[i]] -= 1;
        }

        // return false if char isn't there

        return true;
    }
};