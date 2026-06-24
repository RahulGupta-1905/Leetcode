// Leetcode 3154 Find Number of Ways to Reach the K-th Stair

class Solution {
public:
    unordered_map<string,int>mp;
    long long solve(long long i,long long jump,bool jumpBack,long long k){
        if(i>k+1) return 0;

        long long ans=0;
        if(i==k) ans++;

        string key=to_string(i)+" "+to_string(jump)+" "+to_string(jumpBack);
        if(mp.find(key)!=mp.end()) return mp[key];

        ans+=solve(i+(1LL<<jump),jump+1,true,k);

        if(i>0 && jumpBack==true)
        ans+=solve(i-1,jump,false,k);

        return mp[key]=ans;
    }
    int waysToReachStair(int k) {
        return solve(1,0,true,k);
    }
};
