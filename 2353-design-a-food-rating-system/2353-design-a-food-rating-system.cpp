class FoodRatings {
public:
    map<string, set<pair<int, string>>> mp;
    unordered_map<string, string> m1;
    unordered_map<string, int> m2;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++) {
            mp[cuisines[i]].insert({-ratings[i], foods[i]});
            m1[foods[i]]=cuisines[i];
            m2[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &cuisine = m1.find(food)->second;
        mp[cuisine].erase({ -m2[food], food });
        mp[cuisine].insert({ -newRating, food });
        m2[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return begin(mp[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */