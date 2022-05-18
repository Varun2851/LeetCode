
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
	priority_queue<int>pq1;
    priority_queue<int>pq2;

    int arr1[] = {7, 4, 8, 0, 1};
    int arr2[] = {9, 17, 2, 3, 6};

    vector<int>ans(10);

    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);

    for(int i = 0; i<n; i++){
        pq1.push(arr1[i]);
    }

    for(int i = 0; i<m; i++){
        pq2.push(arr2[i]);
    }
    while(!pq1.empty() or !pq2.empty()){
        if(pq2.empty() or pq1.top() >= pq2.top()){
            ans.push_back(pq1.top());
            pq1.pop();
        }
        else if(pq1.empty() or pq2.top() >= pq1.top()){
            ans.push_back(pq2.top());
            pq2.pop();
        }
    }

    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
	return 0;
}

