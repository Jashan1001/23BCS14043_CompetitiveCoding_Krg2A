#include<bits/stdc++.h>
using namespace std;
bool ispossible(int mid, vector<int> &nums, int maxOp){
    int op=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid){
            op+=(nums[i]-1)/mid;
        }
    }
    return op<=maxOp;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int maxOp;
    cin>>maxOp;
    int s=1;
    int e=*max_element(nums.begin(), nums.end());
    int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(ispossible(mid,nums,maxOp)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<ans<<endl;
}
