class Solution {
public:
    bool canCook(string recipe,
    unordered_map<string,vector<string>>& mapper,
    unordered_set<string>& canMake,
    unordered_set<string>& cannotMake,
    unordered_set<string> &inMaking 
    ){
        //We can make this recipe
        if(canMake.count(recipe)) return true;

        if(cannotMake.count(recipe) //We cannot make this 
            || inMaking.count(recipe)  //We are already cooking this recipe but it is still require
            || !mapper.count(recipe) //We dont know how to make this
        ) return false;

        //Try to make this now
        inMaking.insert(recipe);

        for(string ing:mapper[recipe]){
            if(!canCook(ing,mapper,canMake,cannotMake,inMaking)){
                //We cant cook this food
                inMaking.erase(recipe);
                cannotMake.insert(recipe);
                return false;
            }
        }

        //we Have cooked this food
        inMaking.erase(recipe);
        canMake.insert(recipe);
        return true;
    }
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        
        unordered_set<string> canMake(supplies.begin(),supplies.end());
        unordered_set<string> inMaking;
        unordered_set<string> cannotMake;


        unordered_map<string,vector<string>> mapper;
        vector<string> result;
        int n = recipes.size();
        for(int i = 0 ;i<n;i++){
            mapper[recipes[i]] = ingredients[i];
        }

        for(string recipe:recipes){
            if(canCook(recipe,mapper,canMake,cannotMake,inMaking)){
                result.push_back(recipe);
            }
        }

        return result;
    }
};
