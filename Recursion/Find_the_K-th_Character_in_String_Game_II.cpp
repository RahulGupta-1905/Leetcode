// 3307. Find the K-th Character in String Game II

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {   
        int n=operations.size();
        if(k==1) return 'a';
        long long len=1;
        long long newK=-1;
        int opType=-1;
        for(int i=0;i<n;i++){
            len*=2;
            if(len>=k){
                opType=operations[i];
                newK=k-len/2;
                break;
            }
        }
        char ch=kthCharacter(newK,operations);

        if(opType==0) return ch;
        else {
            if(ch=='z') return 'a';
            else return ch+1;
        }
    }
};

// T.C((logk)^2)
// S.C(logk)
