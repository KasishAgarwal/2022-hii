class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 2) return 0;
        
        int maxE = *max_element(nums.begin(), nums.end());
        int minE = *min_element(nums.begin(), nums.end());
        
        vector<int> minV(n-1, INT_MAX);
        vector<int> maxV(n-1, INT_MIN);
        
        int interval = ceil(float(maxE - minE) / (n - 1));
        
        for(auto X: nums) {
            if(X == maxE || X == minE) continue;
            int bucket = (X - minE) / interval;
            minV[bucket] = min(minV[bucket], X);
            maxV[bucket] = max(maxV[bucket], X);
        }
        
        int ans = 0, prevmax = minE;
        
        for(int i = 0; i < n-1; i++) {
            if(maxV[i] != INT_MIN) {
                ans = max(minV[i] - prevmax, ans);
                prevmax = maxV[i];
            }
        }
        
        ans = max(maxE-prevmax, ans);
        
        return ans;
    }
};
