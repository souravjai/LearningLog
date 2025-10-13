class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prevWord = "";
        for(string word:words){
            string curWord = word;
            sort(curWord.begin(),curWord.end());
            if(curWord!=prevWord){
                ans.push_back(word);
                prevWord = curWord;
            }
        }

        return ans;
    }
};