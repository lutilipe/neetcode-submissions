class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        if (words.size() == 1) {
            unordered_set<char> s;
            string ans = "";
            for (char c : words[0]) {
                if (s.find(c) != s.end()) continue;
                s.insert(c);
                ans.push_back(c);
            }
            return ans;
        };

        unordered_map<char, vector<char>> al;
        unordered_map<char, int> indegree;
        unordered_set<char> letters;

        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i];
            string b = words[i+1];

            for (char c : a) letters.insert(c);
            for (char c : b) letters.insert(c);

            bool ok = false;

            for (int j = 0; j < min(a.size(), b.size()); j++) {
                if (a[j] == b[j]) continue;
                al[a[j]].push_back(b[j]);
                indegree[b[j]]++;
                ok = true;
                break;
            }

            if (!ok && a.size() > b.size()) return "";
        }

        queue<char> q;

        for (char letter : letters) {
            if (indegree[letter] == 0) q.push(letter);
        }

        if (q.empty()) return "";

        string ans = "";

        while (!q.empty()) {
            char letter = q.front();
            q.pop();

            ans.push_back(letter);


            for (char child : al[letter]) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        if (ans.size() != letters.size()) return "";

        return ans;
    }
};

// detectar ciclos
// detectar nenhum verticie inicial