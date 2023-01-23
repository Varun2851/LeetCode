#include<bits/stdc++.h>
using namespace std;

class Minheap{
private:
	void heapify(int i){
		int min_index = i;
		int left = 2*i;
		int right = 2*i+1;

		if(left<v.size() and v[min_index]>v[left]){
			min_index = left;
		}
		if(right<v.size() and v[min_index]>v[right]){
			min_index = right;
		}

		if(min_index != i){
			swap(v[min_index],v[i]);
			heapify(min_index);
		}
	}
public:
	vector<int>v;
	Minheap(){
		v.push_back(-1); //to avoid 0th index
	}

	void push(int data){
		v.push_back(data);
		int c = v.size()-1;
		int p = c/2;
		while(c>1 and v[p]>v[c]){
			swap(v[p],v[c]);
			c = p;
			p = p/2;
		}
	}

	void pop(){
		swap(v[1],v[v.size()-1]);
		v.pop_back(); //remove the last ele
		heapify(1);
	}
	int top(){
		return v[1];
	}
	bool empty(){
		return v.size()==1;
	}
};

int main(){

	Minheap h;

	h.push(-1);
	h.push(10);
	h.push(150);
	h.push(160);
	h.push(-100);
	h.push(400);
	h.push(1900);
	h.push(10000);

	while(!h.empty()){
		cout<<h.top()<<" "<<endl;
		h.pop();

	}
	return 0;
}