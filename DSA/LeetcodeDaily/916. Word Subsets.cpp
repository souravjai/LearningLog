class Solution {
public:
    void generateFreq(string& word,vector<int>& freq){
        for (char& ch : word) {
            int index = ch - 'a';
            freq[index]++;
        }
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<int> maxFreq(26, 0);
        vector<int> curFreq(26,0);
        vector<string> answer;

        for (string& curWord : words2) {
            
            generateFreq(curWord,curFreq);

            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], curFreq[i]);
                curFreq[i] = 0;
            }
        }

        for(string& curWord : words1){

            generateFreq(curWord,curFreq);
            
            bool isUniversal = true;
            for(int i=0;i<26;i++){
                if(curFreq[i]<maxFreq[i]){
                    isUniversal = false;
                }
                curFreq[i]=0;
            }

            if(isUniversal){
                answer.push_back(curWord);
            }
        }

        return answer;
    }
};