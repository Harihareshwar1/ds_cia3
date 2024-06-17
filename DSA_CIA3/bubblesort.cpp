#include "iostream"
#include "vector"
using namespace std;

vector<int> nums = {23,11,-2,54,2,0,31,4,7,3};
void bubblesort(){
 for(int i = 0;i < nums.size() -1;i++){
    for(int j = 0;j< nums.size()-i-1;j++){
        if(nums.at(j) > nums.at(j+1)){
            int temp = nums[j];
            nums[j] = nums[j+1];
            nums[j+1] = temp;
        }
    }
 }
}


int main(){
    for(auto i:nums){
        cout<<i<<" ";

    }
    cout<<endl;

    bubblesort();
    for(auto i:nums){
        cout<<i<<" ";

    }
    cout<<endl;
}