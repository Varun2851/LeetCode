// https://practice.geeksforgeeks.org/problems/largest-number-with-given-sum-1587115620/1
// Geek lost the password of his super locker. 
// He remembers the number of digits N as well as the sum S of all the digits of his password. 
// He know that his password is the largest number of N digits that can be made with given sum S. 
// As he is busy doing his homework, help him retrieving his password.

#include<iostream>
using namespace std;

string solve(int n , int sum){

	string ans = "";

	if(n*9 < sum){
		return -1;
	}

	for(int i = 0; i<n; i++){
		if(9 <= sum){
			ans += "9";
			sum -= 9;
		}
		else{
			ans += to_string(sum);
			sum = 0;
		}
	}
	return ans;
}

int main(){
	int N;
	cin>>N;
	int sum;
	cin>>sum;

}