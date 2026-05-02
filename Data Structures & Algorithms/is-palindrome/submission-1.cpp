class Solution {
public:
    bool isPalindrome(string s) {
        string parsedString = "";

        for (char c : s) {
            if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z') && !(c >= '0' && c<='9')) continue;
            parsedString += tolower(c);
        }

        for (int i = 0; i <= parsedString.size() / 2; i++) {
            if (parsedString[i] != parsedString[parsedString.size() - 1 - i]) return false;
        }
        return true;
    }
};
