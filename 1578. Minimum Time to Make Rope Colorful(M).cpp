// 1578. Minimum Time to Make Rope Colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        for(int i = 0 ; i < colors.size()-1; i++){
            if(colors[i] == colors[i + 1])
            {
                cost = cost +  min(neededTime[i],neededTime[i + 1]);
                neededTime[i + 1] = max(neededTime[i], neededTime[i + 1]);
            }
        }
        return cost;
    }
};

/*
Approach
When we have consecutive balloons of the same color, we need to remove all but one. The trick is to keep the balloon that takes the most time to remove (most expensive) and remove all the cheaper ones.
We iterate through the string comparing adjacent balloons. When we find two consecutive balloons with the same color:

Add the cost of removing the cheaper one to our total cost
Update the next position to keep the more expensive balloon's time for future comparisons

This way, when we have a group like "aaa" with times [1, 2, 3], we progressively keep the most expensive one and accumulate the cost of removing the others.
Time Complexity: O(n)
Space Complexity: O(1)
*/
