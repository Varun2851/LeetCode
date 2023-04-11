#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n){
    if(n<4){
        return 0;
    }
    vector<int> v1, v2;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            v1.push_back(arr[i]);
        }
        else {
            v2.push_back(arr[i]);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return v1[1]+v2[1];
}

int main(){
    int arr[] = {3, 2, 1, 7, 5, 4};
    int n = sizeof(arr)/sizeof(int);
    //sort(arr,arr+n);
    cout << solve(arr, n);
    return 0;
}
