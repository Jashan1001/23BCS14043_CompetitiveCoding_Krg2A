#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

int solve(vector<int>&A){
    long long n=A.size(),ans=0;
    for(int bit=0;bit<32;bit++){
        long long c1=0;
        for(int i=0;i<n;i++)
            if(A[i]&(1LL<<bit))
                c1++;
        long long c0=n-c1;
        long long contrib=((c1*c0)%MOD*2)%MOD;
        ans=(ans+contrib)%MOD;
    }
    return ans;
}

int main(){
    vector<int>A={1,3,5};
    cout<<solve(A);
}
