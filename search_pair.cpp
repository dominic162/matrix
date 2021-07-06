/*
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes 
such that both c > a and d > b.
*/

#include<iostream>
using namespace std;

class Solution{
    public:
        int max_diff(int ** mat , int n , int m);
};

int main(){

    int n,m;
    cin>>n>>m;
    int ** mat = new int * [n];

    for(int i = 0 ; i < n ; ++i){
        mat[i] = new int [m];
        for(int j = 0 ; j < m ; ++j){
            cin>>mat[i][j];
        }
    }
    Solution sl;
    cout<<"Max diff: "<<sl.max_diff(mat , n , m);

    for(int i = 0 ; i < n ; ++i){
        delete []mat[i];
    }
    delete []mat;
    return 0;
}

int Solution::max_diff(int ** mat , int n , int m){

    int ans = INT_MIN;

    int ** dp = new int * [n];

    for(int i = 0 ; i < n ;++i){
        dp[i] = new int [m];
    }

    int cmin = INT_MAX;
    for(int i = 0 ; i < m ; ++i){
        cmin = min(cmin , mat[0][i]);
        dp[0][i] = cmin;
    }

    for(int i = 1 ; i < n ; ++i){
        
        dp[i][0] = min(mat[i][0] , dp[i-1][0]);
        for(int j = 1 ; j < m ; ++j){

            dp[i][j] = min(mat[i][j] , min(dp[i-1][j] , dp[i][j-1]));

            ans = max(ans , mat[i][j] - dp[i-1][j-1]);

        }   
    }

    for(int i = 0 ; i < n ; ++i){
        delete []dp[i];
    }

    delete []dp;

    return ans;


}