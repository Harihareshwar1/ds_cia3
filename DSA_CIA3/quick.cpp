#include "iostream"
#include "vector"
using namespace std;

vector<int> nums = {23,11,-2,54,2,0,31,4,7,3};


int helper(int start,int end){
    int pivot = nums[end];
    int i = start-1;
    for(int j=start;j<=end-1;j++){
        if(nums[j] < pivot){
                  i++;
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    


    }
        i++;
      nums[end] = nums[i];
      nums[i] = pivot;
      return i;
}
void quickSort(int start,int end){
      if(start >=end){
        return;
      }
    int pivot = helper(start,end);
    quickSort(start,pivot-1);
quickSort(pivot+1,end);
}


int main(){
    for(auto i:nums){
        cout<<i<<" ";

    }
    cout<<endl;

    quickSort(0,nums.size());
    for(auto i:nums){
        cout<<i<<" ";

    }
    cout<<endl;
}