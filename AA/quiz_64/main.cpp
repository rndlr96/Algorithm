#include <iostream>
#include <algorithm>

using namespace std;

int size, cnt = 0;
int arr[30][30];
int check[30];

void DFS(int k){
    int i;
    if( k == size-1 ){
        cnt += 1;
    } else{
        for(i = 0 ; i < size ; i++){
            if(arr[k][i] == 1 && check[i] == 0){
                check[i] = 1;
                DFS(i);
                check[i] = 0;
            }
        }
    }
}

int main() {
    int input, start, end;
    cin >> size >> input;
    memset(arr, 0, size*size*sizeof(int));
    for(int i = 0 ; i < input ; i++){
        cin >> start >> end;
        arr[start-1][end-1] = 1;
    }
    check[0] = 1;

    DFS(0);

    cout << cnt << endl;
    return 0;
}
