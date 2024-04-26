#include <iostream>
using namespace std;



int main() {
    int miVector[9] = {5,12,23,27,32,34,38,40,45};
    int size=9;
    int numero=32;
    int l=0;
    int r=size-1;
    int mid=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(miVector[mid]==numero){
            cout<<mid<<endl;
            return false;
        }else
        if(numero<miVector[mid]){
            r=mid-1;
        }else
        if(numero>miVector[mid]){
            l=mid+1;
        }
    }
    

    return 0;
}
