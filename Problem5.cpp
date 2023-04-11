#include<iostream>
using namespace std;

int solve(int n1,int n2){
	int count = 0;
	int carry = 0;

	while(n1>0 or n2>0){
		int digit1 = n1%10;
		int digit2 = n2%10;

		int sum = digit2+digit1+carry;

		if(sum>9){
			count++;
			carry =1;
		}
		else{
			carry = 0;
		}

		n1 = n1/10;
		n2 = n2/10;
	}
	return count;
}

int main(){

	int num1 = 154;
	int num2 = 678;

	cout<<solve(num1,num2);
	return 0; 
}