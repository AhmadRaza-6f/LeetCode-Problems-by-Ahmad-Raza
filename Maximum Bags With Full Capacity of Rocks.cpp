class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int extraRocks) {
        int n = cap.size();
        vector<int> extra(n);
        for(int i = 0 ; i < n; i++){
            extra[i] = cap[i] - rocks[i];
        }
        int ans = 0;
        sort(extra.begin(),extra.end());
        for(int val : extra){
            if(val <= extraRocks){
                ans += 1;
                extraRocks -= val;
            }
        }
        return ans;
    }
};
