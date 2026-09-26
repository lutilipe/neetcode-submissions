class Solution {
public:
    bool isPalindrome(string s) {
        string parsed = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') parsed+= (char)(s[i] - 'A' + 'a');
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) parsed+=s[i];

        }
        for (int i = 0; i <= parsed.size() / 2; i++) {
            if (parsed[i] != parsed[parsed.size() - i - 1]) return false;
        }
        return true;
    }
};
