// ************************************************ Approach No 1 ************************************************
//TC = O(n)
//SC = O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small, large;

        for (int& value : nums) {
            if (value < pivot) {
                small.push_back(value);
            } else if (value > pivot) {
                large.push_back(value);
            }
        }
        for (int& value : nums) {
            if (value == pivot) {
                small.push_back(value);
            }
        }
        int idx = 0;
        for (int i = 0; i < small.size(); i++) {
            nums[idx++] = small[i];
        }
        for (int i = 0; i < large.size(); i++) {
            nums[idx] = large[i];
            idx++;
        }
        return nums;
    }
};

// ************************************************ Approach No 2 ************************************************
//TC = O(n)
//SC = O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> right;
        int n = nums.size();
        int l = 0, mid = 0, idx = n;

        for (int& x : nums) {
            if (x < pivot) {
                nums[l++] = x;
            } else if (x > pivot) {
                right.push_back(x);
                idx--;
            } else {
                mid++;
            }
        }
        auto positio_for_mid_elements = nums.begin() + l;
        // Insert from element that are equal to pivot in center
        fill(positio_for_mid_elements, positio_for_mid_elements + mid, pivot);
        // insert elements that are greater then pivot on right side
        int rightFillIdx = l + mid;
        for (int i = 0; i < right.size(); i++) {
            nums[rightFillIdx++] = right[i];
        }

        return nums;
    }
};

// ************************************************ Approach No 3 ************************************************
//TC = O(n)
//SC = O(n)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        for (int x : nums) {
            if (x < pivot)
                ans.push_back(x);
        }

        for (int x : nums) {
            if (x == pivot)
                ans.push_back(x);
        }

        for (int x : nums) {
            if (x > pivot)
                ans.push_back(x);
        }

        return ans;
    }
};
