class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for(int col = 0; col < strs[0].size(); col++){
            for(int i = 0; i < strs.size()-1; i++){
                if(strs[i][col] > strs[i+1][col])
                {
                    count++;break;
                }
            }
        }
        return count;
    }
};
