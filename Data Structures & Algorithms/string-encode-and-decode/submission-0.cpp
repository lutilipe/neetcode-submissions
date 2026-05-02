class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (string s : strs) {
            ans+=to_string(s.size()) + '#';
            ans+=s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for (int i = 0; i < s.size(); i++) {
            string size = "";
            while (s[i] != '#') {
                size+=s[i];
                i++;
            }
            int length = stoi(size);
            if (length == 0) {
                ans.push_back("");
                continue;
            }
            ans.push_back(s.substr(i+1, length));
            i+=length;
        }        
        return ans;
    }
};


// Size + 