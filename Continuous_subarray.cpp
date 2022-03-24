#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        long long sum=0;
        int i,j=0;
        vector<int>v;
        while(true)
        {
            if(sum<s){
                sum+=arr[i];
                i++;
            }
            if(sum>s){
                sum-=arr[j];
                j++;
            }
            if(sum==s){
                v.push_back(j+1);
                v.push_back(i);
                return v;
            }
            if(i>n){
                v.push_back(-1);
                return v;
            }
        }
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends