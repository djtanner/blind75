#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> hashSet;
        int L= 0; //leftmost char
        int maxLength = 0;


        for (int R = 0; R < s.length(); R++) { 
             while (hashSet.find(s[R]) != hashSet.end()) {
            // Remove characters from the set until we can add s[R] - sliding window
            hashSet.erase(s[L]);
            L++;
            }
            
            hashSet.insert(s[R]);
            maxLength = std::max(maxLength, R - L + 1);
        }

        return maxLength;

    }
};