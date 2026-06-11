class TrieNode {
    public:
        TrieNode* children[26];
        int count = 0;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode();
        root->count = strs.size();

        for (string s : strs) {
            TrieNode* curr = root;
            for (char c : s) {
                int idx = c - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
                curr->count++;
            }
        }

        string first = strs[0];
        string ans = "";
        TrieNode* curr = root;

        for (char c : first) {
            int idx = c - 'a';
            if (!curr->children[idx]) break;
            if (curr->children[idx]->count < strs.size()) break;
            ans+=c;
            curr = curr->children[idx];
        }

        return ans;
    }
};