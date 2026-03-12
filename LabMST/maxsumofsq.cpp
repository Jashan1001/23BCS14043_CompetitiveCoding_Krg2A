#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    //brute force approach
    int maxSum=0;
    for(int i=0; i<(1<<n); i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                temp.push_back(nums[j]);
            }
        }
        if(temp.size()==k){
            int sum=0;
            for(int x: temp){
                sum+=x*x;
            }
            maxSum=max(maxSum, sum);
        }
    }
    cout<<maxSum<<endl;
}