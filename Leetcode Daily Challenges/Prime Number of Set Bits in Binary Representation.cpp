/******************************************************* Approach 1 *******************************************************/
class Solution {
bool isPrime(int n){
        if(n < 2) return false;  
        for(int i = 2; i < n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for(int i = left; i <= right;i++){
            int count = __builtin_popcount(i);
            if(isPrime(count)){
                result++;
            }
        }
        return result;
    }
};
/******************************************************* Approach 2 *******************************************************/
//Approach (Simple loop and check)
//T.C : O((right - left) * log(num))
//S.C : O(1)
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
        
        int result = 0;

        for (int num = left; num <= right; num++) {
            int setBits = __builtin_popcount(num);
            
            if(primes.count(setBits))
                result += 1;
        }

        return result;
    }
};
