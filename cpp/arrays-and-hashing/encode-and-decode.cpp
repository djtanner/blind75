#include <vector>
#include <string>

using namespace std;
class Codec
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        // do length#-string-length#-string...
        // add the # delimiter in case length > 1 digit
        string result;
        for (int i = 0; i < strs.size(); i++)
        {
            result += std::to_string(strs[i].length()) + '#';
            result += strs[i];
        }

        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {

        vector<string> result;

        while (s.length() > 0)
        {
            // get the length using the delimiter

            int index = s.find('#');

            int k = stoi(s.substr(0, index));

            std::string numberString = std::to_string(k);
            int digitsLen = numberString.length();

            string str = s.substr(index + 1, index + k - digitsLen);

            result.push_back(str);

            s = s.substr(index + 1 + k);
        }

        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));