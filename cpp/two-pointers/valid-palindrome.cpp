#include <string>

using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        // clean the string
        string cleanedStr = cleanStr(s);

        // using 2 pointers, check if first and last chars match
        int i = 0;
        int j = cleanedStr.length() - 1;

        while (i < j)
        {

            if (cleanedStr.at(i) != cleanedStr.at(j))
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    string cleanStr(string s)
    {
        string newStr;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s.at(i);
            if (std::isalnum(c))
            {
                newStr += std::tolower(c);
            }
        }

        return newStr;
    }
};