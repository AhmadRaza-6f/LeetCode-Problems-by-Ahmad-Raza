class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();
        int deleteCols = 0;
        vector<bool> sorted(row-1,false);

        for(int i = 0; i < col; i++){
            bool doSorting = false;
            for(int j = 0 ; j < row - 1; j++){
                if(sorted[j] == false && strs[j][i] > strs[j + 1][i]){
                    doSorting = true;
                    break;
                }
            }

            if(doSorting == true){
                deleteCols += 1;
                continue;
            }
            for(int k = 0 ; k < row - 1; k++){
                if(sorted[k] == false && strs[k][i] < strs[k + 1][i]){
                    sorted[k] = true;
                }
            }
        }
        return deleteCols;
    }
};
