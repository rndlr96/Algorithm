#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int *arr, size, *tmp;

void divide(int lt, int rt){
    int mid;
    int p1, p2, p3;
    if(lt < rt){
        mid = (lt+rt)/2;
        cout << lt << " " << mid << " " << rt << endl;
        divide(lt, mid);
        divide(mid+1, rt);
        p1 = lt;
        p2 = mid+1;
        p3 = lt;
        while(p1 <= mid && p2 <= rt){
            if(arr[p1] < arr[p2]) tmp[p3++] = arr[p1++];
            else tmp[p3++] = arr[p2++];
        }
        while(p1 <= mid) tmp[p3++] = arr[p1++];
        while(p2 <= rt) tmp[p3++] = arr[p2++];
        for(int i = lt ; i <= rt ; i++){
            arr[i] = tmp[i];
        }
    }
}


int main() {
    cin >> size;
    arr = new int[size];
    tmp = new int[size];
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }
    divide(0, size-1);
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
