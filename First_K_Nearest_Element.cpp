//first k nearest element

//https://leetcode.com/problems/find-k-closest-elements/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

      int n = arr.size();

      //we are going to apply two pointer approach
      int low = 0;
      int high = n-1;

      int minele = arr[0]; //beacuse array is sorted
      int maxele = arr[n-1]; //because array is sorted


      if(x<=minele){ //example 1,2,3,4,5,6 , x = -1 , k = 3 then output 1 ,2 3
        arr.resize(k);
        return arr;
      }

      else if(x>=maxele){
        arr.erase(arr.begin(),arr.begin()+n-k);
        return arr;
      }

      int p = n-k;

      while(p--){
        int dl = abs(arr[low]-x);
        int dh = abs(arr[high]-x);

        if(dl<=dh){
          high--;
        }
        else if(dl>dh){
          low--;
        }
      }

      vector<int>ans;

      for(int j = low; j<=high; j++){
        ans.push_back(arr[j]);
      }

      return ans;
       
    }
};