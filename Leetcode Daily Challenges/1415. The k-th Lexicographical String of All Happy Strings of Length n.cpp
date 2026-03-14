class Solution {
void solve(int n, string &curr, vector<string> &temp){
    if(curr.size() == n){
        temp.push_back(curr);
        return;
    }

    for(char ch = 'a'; ch <= 'c'; ch++){
        if(curr.empty() || curr.back() != ch){ //curr = "" or s[i] != s[i + 1];
            curr += ch;
            solve(n,curr,temp);
            curr.pop_back();
        }
    }
}
public:
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> get;
        solve(n,curr,get);

        if(get.size() < k)
            return "";
        return get[k - 1];
    }
};
