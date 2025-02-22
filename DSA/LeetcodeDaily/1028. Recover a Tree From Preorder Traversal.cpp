/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    pair<int, int> getValAndDepth(string& s, int& index) {
        int depth = 0;
        string val = "";
        
        while (s[index] == '-') {
            index++;
            depth++;
        }
        while (s[index] >= '0' && s[index] <= '9') {
            val += s[index];
            index++;
        }
        return {stoi(val), depth};
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        TreeNode *root, *temp;
        int index = 0, curDepth = 0;
        root = new TreeNode(getValAndDepth(traversal, index).first);
        st.push(root);

        while (index < traversal.size()) {
            curDepth++;

            auto [val, depth] = getValAndDepth(traversal, index);
            temp = new TreeNode(val);

            while (depth != curDepth) {
                curDepth--;
                st.pop();
            }
            if(st.top()->left == nullptr)   st.top()->left = temp;
            else st.top()->right = temp;

            st.push(temp);
        }
        return root;
    }
};
