class Solution {
public:
    string repeatChar(int count,int chIdx){
        char ch = chIdx+'a';
        string ans = "";

        for(int i=0;i<count;i++){
            ans+=ch;
        }
        return ans;

    }
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26]={0};

        for(char c:s){
            freq[c-'a']++;
        }
        string ans = "";
        int i =25,j;

        while(i>=0){
            if(freq[i]==0){
                i--;
            }else{
                int curCount = min(repeatLimit,freq[i]);
                ans+= repeatChar(curCount,i);
                freq[i]-=curCount;
                
                if(curCount==repeatLimit && freq[i]!=0){
                    j = i-1;
                    while(j>=0 && freq[j]==0){
                        j--;
                    } 

                    if(j==-1) break;

                    freq[j]-=1;
                    ans+=repeatChar(1,j);
                }
            }
        }

        return ans;
    }
};