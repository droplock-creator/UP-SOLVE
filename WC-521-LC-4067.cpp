// Link to question: https://leetcode.com/problems/longest-subarray-with-restricted-pair-sums/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        if(nums.size() < 3){
            return nums.size();
        }
        vector<int>A(1001,0);
        unordered_map<int,int>B;
        int len=2,a=0;
        A[nums[0]+nums[1]]++;
        B.insert({nums[1]+nums[0],0});
        A[abs(nums[1]-nums[0])]++;
        B.insert({abs(nums[1]-nums[0]),0});
        for(int i = 2; i < nums.size(); i++){
            if(A[nums[i]] > 0){
                a = B[nums[i]]+1;
                len = max(len,i-a+1);
                B[nums[i]] = -1;;
                A[nums[i]] = 0;
                for(int j = a; j < i; j++){
                    A[nums[i]+nums[j]]++;
                    B[nums[i]+nums[j]] = max(B[nums[i]+nums[j]],j);
                    A[abs(nums[i]-nums[j])]++;
                    B[abs(nums[i]-nums[j])] = max(B[abs(nums[i]-nums[j])],j);
                }
                for(auto x:B){
                    if(x.second<a){
                        A[x.first] = 0;
                    }
                }
            }else{
                len = max(len,i-a+1);
                for(int j = a; j < i; j++){
                    A[nums[i]+nums[j]]++;
                    B[nums[i]+nums[j]] = max(B[nums[i]+nums[j]],j);
                    A[abs(nums[i]-nums[j])]++;
                    B[abs(nums[i]-nums[j])] = max(B[abs(nums[i]-nums[j])],j);
                }
            }
        }
        return len;
        
    }
};