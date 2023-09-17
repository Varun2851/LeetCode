#include<iostream>
using namespace std;

int main(){
	string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	char M[1000];

	int n = 5;
	int i = 0;
	int j = 0;

	while(i < 5 and j <5){
		if(s1[i] == s2[j]){
			M[i] = 'G';
			i++;
			j++;
		}
		else{
			M[i] = 'B';
			i++;
			j++;
		}
	}

	for(int i = 0; M[i] != '\0'; i++){
		cout<<M[i];
	}
	return 0;
}