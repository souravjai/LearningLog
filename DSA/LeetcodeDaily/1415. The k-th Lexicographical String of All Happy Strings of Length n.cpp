class Solution {
public:
    vector<char> alpha = {'a', 'b', 'c'};
    vector<string> combo(int size, vector<string> cur) {
        if (size == 0) {
            return cur;
        }

        vector<string> ans;

        for (string current : cur) {
            for (char ch : alpha) {
                if (current.size()==0 || current.back() != ch) {
                    ans.push_back(current + ch);
                }
            }
        }

        return combo(size - 1, ans);
    }
    string getHappyString(int n, int k) {
        if (k > 3 * pow(2, n - 1))
            return "";
        return combo(n, vector<string>(1,""))[k-1];
    }
};