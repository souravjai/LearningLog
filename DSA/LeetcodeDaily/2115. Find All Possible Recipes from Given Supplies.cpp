class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        
        unordered_set st(supplies.begin(),supplies.end());
        vector<string> result;

        int n = recipes.size();

        //T(N*N*M)
        for(int repeat=0; repeat<n; repeat++){
            bool isNewFoodCooked = false;

            for(int i = 0;i<n;i++){
                if(st.count(recipes[i])){
                    continue;
                }

                bool isCookable = true;
                for(string ing:ingredients[i]){
                    if(!st.count(ing)){
                        isCookable = false;
                        break;
                    }
                }
                
                if(isCookable){
                    st.insert(recipes[i]);
                    result.push_back(recipes[i]);
                    isNewFoodCooked = true;
                }
            }

            if(!isNewFoodCooked){
                break;
            }
        }
        return result;
    }
};
