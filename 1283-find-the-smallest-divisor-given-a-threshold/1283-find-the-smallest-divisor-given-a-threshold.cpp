class Solution {
private:
    int findMax(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int sumbyD(vector<int> nums, int div) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(div));
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (n > threshold)
            return -1;
        int low = 1;
        int high = findMax(nums);
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumbyD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};