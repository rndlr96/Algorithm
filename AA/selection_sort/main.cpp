#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;
    int arr[number];
    for (int i = 0 ; i < number ; i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < number ; i++){
        int min_index = i;
        for (int j = i+1 ; j < number+1 ; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int tmp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = tmp;
    }

    for(int i = 0 ; i < number ; i++){
        cout << arr[i] << ' ';
    }


    return 0;
}
