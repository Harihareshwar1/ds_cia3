
#include "iostream"
#include "vector"
using namespace std;

vector<int> nums = {1,5,9,23,31,34,56,59,78};
int binarySearch(int k){
    int low = 0;
    int high = nums.size() - 1;
    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] == k){
            return mid;
        }
        else if(nums[mid] < k){
            low = mid+1;

        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    cout<<binarySearch(34*2 + 10);
}