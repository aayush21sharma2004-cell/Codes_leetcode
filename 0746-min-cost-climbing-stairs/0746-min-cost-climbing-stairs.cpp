#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

   int solve(vector<int>& cost, int n, vector<int>& dp) {
    if(n==0) {
        return cost[0];
    }
    if(n==1) {
        return cost[1];
    }

    //step3.
    if(dp[n]!=-1) {
        return dp[n];
    }

    //step2.
    dp[n]= cost[n]+ min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return dp[n];


   }

   int solve2(vector<int>& cost, int n) {
    vector<int> dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2; i<n; i++) {
        dp[i]=cost[i]+ min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
   

   }
    
  /*  int solve2(vector<int>& cost, int n) {
    vector<int> dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2; i<n; i++) {
        dp[i]=cost[i]+ min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
   

   }*/
    
     int solve3(vector<int>& cost, int n) {
     
     int prev01=cost[1];
     int prev02=cost[0];

     for(int i=2; i<n; i++) {
        int current= cost[i]+ min(prev01,prev02);
        prev02=prev01;
        prev01=current;
     }
     return min(prev01,prev02);


     }


    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
    /*    //step1.
        vector<int> dp(n+1,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans; */
       // return solve2(cost,n);
        return solve3(cost,n);


    }
};