
//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

int plateform(int *arr , int *dep , int n){
    vector<pair<int , int>>v;
    priority_queue<int, vector<int>, greater<int> > q;
    
    for(int i = 0; i<6; i++){
        v.push_back({arr[i],dep[i]});
    }

    q.push(v[0].second); // Add the end time of meeting[0]
		for (int i = 1 ; i < v.size(); i++) {
			int new_train_arrival = v[i].first;
			int new_train_depart = v[i].second;
			int purani_train_depart = q.top();
			if (purani_train_depart <= new_train_arrival) {
				q.pop();
				q.push(new_train_depart);
			}
			else {
				q.push(new_train_depart);
			}
		}

		return q.size();

}

int main() {
	// your code goes here

   int  arr[] = {900, 945, 955, 1100, 1500, 1800} ;
   int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
   int n = 6;
   sort(arr , arr+6);
   sort(dep,dep+6);
   
   int a = plateform(arr , dep , 6);

   cout<<a;

   return 0;
}

