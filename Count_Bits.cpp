#include<iostream>
using namespace std;

int countBits(int n){
	int count = 0;

	while(n>0){
		int lastBit = (n&1);
		cnt += lastBit;
		n = n>>1; // right shift
	} 
	return count;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int setbits = countBits(n);

	cout<<setbits<<endl;
	return 0;

}