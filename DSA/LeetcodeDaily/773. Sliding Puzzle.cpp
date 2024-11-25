
class Solution {
    public:
        string getString(vector<vector<int>>& board){
            string ans ="";
    
            for(int i = 0 ;i<2;i++){
                for(int j=0;j<3;j++){
                   ans+=std::to_string(board[i][j]);
                }
            }
            return ans;
        }
        vector<vector<int>> getBoard(string& s){
            vector<vector<int>> ans(2,vector<int>(3,0));
    
            ans[0][0] = s[0]-'0';
            ans[0][1] = s[1]-'0';
            ans[0][2] = s[2]-'0';
            ans[1][0] = s[3]-'0';
            ans[1][1] = s[4]-'0';
            ans[1][2] = s[6]-'0';
    
            return ans;
        }
        pair<int,int> getZeroPos(vector<vector<int>>& board){
            for(int i = 0 ;i<2;i++){
                for(int j=0;j<3;j++){
                    if(board[i][j]==0)
                        return {i,j};
                }
            }
    
            return {-1,-1};
        }
    
        int slidingPuzzle(vector<vector<int>>& board) {
            unordered_set<string> st;
            queue<vector<vector<int>>> q;
            vector<vector<int>> temp;
            string tempstr;
    
            q.push(board);
            st.insert(getString(board));
            
            int ans = 0;
    
            while(!q.empty()){
                
                if(st.find("123450") !=st.end()){
                        return ans;
                }
    
                // for(auto xx:st){
                //     cout<<xx<<" ";
                // }
                // cout<<endl;
                ans++;   
                int qlen = q.size();
            
                for(int i = 0;i<qlen;i++){
                    
                    temp = q.front();
                    q.pop();
    
                    pair<int,int> idx = getZeroPos(temp);
    
                    if(idx.first!=0){
                        //up
                        temp[idx.first][idx.second] = temp[idx.first-1][idx.second];
                        temp[idx.first-1][idx.second] = 0;
    
                        tempstr = getString(temp);
                        if(st.find(tempstr)==st.end()){
                            st.insert(tempstr);
                            q.push(temp);
                        }
    
                        temp[idx.first-1][idx.second]=temp[idx.first][idx.second];
                        temp[idx.first][idx.second] = 0;
                    }
    
                    if(idx.first!=1){
                        //down
                        temp[idx.first][idx.second] = temp[idx.first+1][idx.second];
                        temp[idx.first+1][idx.second] = 0;
    
                        tempstr = getString(temp);
                        if(st.find(tempstr)==st.end()){
                            st.insert(tempstr);
                            q.push(temp);
                        }
    
                        temp[idx.first+1][idx.second]=temp[idx.first][idx.second];
                        temp[idx.first][idx.second] = 0;
                    }
    
                    if(idx.second!=0){
                        //left
                        temp[idx.first][idx.second] = temp[idx.first][idx.second-1];
                        temp[idx.first][idx.second-1] = 0;
    
                        tempstr = getString(temp);
                        if(st.find(tempstr)==st.end()){
                            st.insert(tempstr);
                            q.push(temp);
                        }
    
                        temp[idx.first][idx.second-1]=temp[idx.first][idx.second];
                        temp[idx.first][idx.second] = 0;
                    }
    
                    if(idx.second!=2){
                        //right
                        temp[idx.first][idx.second] = temp[idx.first][idx.second+1];
                        temp[idx.first][idx.second+1] = 0;
    
                        tempstr = getString(temp);
                        if(st.find(tempstr)==st.end()){
                            st.insert(tempstr);
                            q.push(temp);
                        }
    
                        temp[idx.first][idx.second+1]=temp[idx.first][idx.second];
                        temp[idx.first][idx.second] = 0;
                    }     
                }
            }    
    
            return -1;    
        }
    };
    