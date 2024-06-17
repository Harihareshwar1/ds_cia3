#include "iostream"
#include "vector"
using namespace std;

vector<int> nums = {23,11,-2,54,2,0,31,4,7,3};
void insertionSort(){
 for(int i = 1;i < nums.size();i++){
  int temp = nums[i];
  int j = i - 1;
  while(j>=0 && nums[j] > temp){
         nums[j+1] = nums[j];
         j--;
  }
  nums[j+1] = temp;
 }
}


int main(){
    for(auto i:nums){
        cout<<i<<" ";

    }
    cout<<endl;

    insertionSort();
    for(auto i:nums){
        cout<<i<<" ";

    }
    cout<<endl;
}