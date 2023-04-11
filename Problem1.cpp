#include<iostream>
using namespace std;

int solve(int m,int n){
	int Notsum = 0;
	int sum = 0;

	for(int i = 1; i<=n; i++){
		if(i%m==0){
			sum += i;
		}
		if(i%m != 0){
			Notsum += i;
		}
	}
	return Notsum-sum;
}

int main(){
	int n;
	int m;
	cin>>n>>m;
	cout<<solve(m,n);
	return 0;
}