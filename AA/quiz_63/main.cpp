#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int input, size, start, fin;
    cin >> input >> size;
    int arr[size][size];
    memset(arr, 0, size*size*sizeof(int));
    for ( int i = 0 ; i < input ; i++){
        cin >> start >> fin;
        arr[start-1][fin-1] = 1;
        arr[fin-1][start-1] = 1;
    }
    for (int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
