#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;
    int arr[number];
    for(int i = 0 ; i < number ; i++){
        cin >> arr[i];
    }

    for( int i = 1 ; i < number+1 ; i++){
        int tmp = arr[i];
        int j;
        for ( j = i-1 ; j < i ; j--){
            if(arr[j] > tmp) {
                arr[j + 1] = arr[j];
            } else{
                break;
            }
        }
        arr[j+1] = tmp;
    }

    for ( int i = 0 ; i < number ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
