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
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            ans.push_back(q.back()->val);
            int len = q.size();

            for (int i = 0; i < len; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
        }
        return ans;
    }
};