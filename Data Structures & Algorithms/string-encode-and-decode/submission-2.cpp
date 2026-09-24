class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (string s: strs) {
            res+=to_string(s.size()) + '#' + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        for (int i = 0; i< s.size(); i++) {
            int size = 0;
            while (i < s.size() && s[i] <= '9' && s[i]>= '0') {
                size = (10*size) + s[i] - '0';
                i++;
            }

            i++;

            string curr = s.substr(i, size);

            ans.push_back(curr);

            i+= size-1;
        }

        return ans;
    }
};
