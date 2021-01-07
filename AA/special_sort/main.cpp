#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;
    int arr[number];
    for ( int i = 0 ; i < number ; i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < number ; i++){
        if (arr[i] < 0){
            for(int j = i ; j > 0 ; j--){
                if (arr[j-1] > 0){
                    int tmp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = tmp;
                }
            }
            for(int i = 0 ; i < number ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}
