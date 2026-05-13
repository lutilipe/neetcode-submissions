class Solution {
    vector<string> ans;
public:
    void helper(int n, string& curr, int openCount, int closedCount) {
        if (curr.size() == n*2) {
            ans.push_back(curr);
            return;
        }

        if (openCount < n) {
            curr.push_back('(');
            helper(n, curr, openCount+1,closedCount);
            curr.pop_back();
        }

        if (closedCount < openCount) {
            curr.push_back(')');
            helper(n, curr, openCount,closedCount+1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";

        helper(n, curr, 0, 0);

        return ans;
    }
};

// open_count = ( = 0
// closed_count = ) = 0

/* 

se open_count < n, add[(]
se closed_count < open_count, add[closed_count]

*/