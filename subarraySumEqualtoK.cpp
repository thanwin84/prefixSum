//time: o(n^2) and space: O(1)
// time limit exceed
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            long sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        return count;

    }
};
//time:O(n) 
//uing hashmap for O(1) access
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currentSum = 0;
        int count = 0;
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); i++){
            currentSum += nums[i];
            if (currentSum == k){
                count++;
            }
          //currentSum - k = value -> currentSum = k + value
          // it means that k is present in the array
            if (lookup.count(currentSum - k)){
                count += lookup[currentSum -k];
            }
            lookup[currentSum] += 1;
        }
        return count;

    }
};
