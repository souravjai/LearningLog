class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int oneCount=0 ,zeroCount=0;
        int answer = 0;

        for(int i=0;i<n;i++){
            oneCount+=s[i]-'0';
        }


        for(int i = 0;i<n-1;i++){
            if(s[i]=='0')   zeroCount++;
            else            oneCount--;

            answer = max(answer,zeroCount+oneCount);
        }
        return answer;
    }
};