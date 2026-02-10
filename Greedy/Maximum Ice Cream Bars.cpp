class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Find the maximum cost to determine the range for counting sort
        int maxCost = *max_element(costs.begin(), costs.end());
        
        // Frequency array for counting sort
        vector<int> freq(maxCost + 1, 0);
        
        // Count frequency of each cost
        for(int cost : costs) {
            freq[cost]++;
        }
        
        // Greedily buy ice creams starting from cheapest
        int count = 0;
        for(int cost = 1; cost <= maxCost; cost++) {
            if(freq[cost] > 0) {
                // Buy as many ice creams at this cost as possible
                int canBuy = min(freq[cost], coins / cost);
                count += canBuy;
                coins -= canBuy * cost;
                
                // If we run out of coins, break
                if(coins <= 0) break;
            }
        }
        
        return count;
    }
};
