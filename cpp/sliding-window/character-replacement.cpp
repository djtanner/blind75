#include <unordered_map>
#include <string>

using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
                unordered_map<char, int> hashMap;
        int L = 0;
        int R = 0;
        int maxChar = 0;
        int result = 0;

        while (R < s.length()) {
            char currentChar = s[R];

            // Increment the frequency of the current character
            hashMap[currentChar]++;

            // Update the most frequent character count
            maxChar = max(maxChar, hashMap[currentChar]);

            // Check if the current window is valid
            if ((R - L + 1) - maxChar <= k) {
                result = max(result, R - L + 1);
            } else {
                // Move L pointer to make the window valid
                hashMap[s[L]]--;
                if (hashMap[s[L]] == 0) {
                    hashMap.erase(s[L]);
                }
                L++;
            }

            // Move R pointer
            R++;
        }

        return result;
    }
};
