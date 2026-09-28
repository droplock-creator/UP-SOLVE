// Link to question: https://leetcode.com/problems/maximum-equal-adjacent-pairs-after-at-most-one-replacement/

/*

SOLUTION-: 
Ans = Existing equal pairs + New Adjacent pairs after operation.
Since we need to get max pairs equal thus we'll find frequency of each pair of elements where both number aren't equal.


*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int m=0;
        int ct = 0;
        unordered_map<long long,int> f;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                ct++;
                continue;
            }
            long long s = (1ll*max(nums[i],nums[i-1]) << 32) | min(nums[i],nums[i-1]); 
            m=max(m,++f[s]);
        }
        return m+ct;
    }
};