#include <iostream>

using namespace std;

int main() {
    int n,s,r, idx;
    int answer = 0;
    cin >> n >> s >> r;
    int arr[12] = {0,};
    for(int i = 0 ; i < s ; i++){
        cin >> idx;
        arr[idx] -= 1;
    }
    for(int i = 0 ; i < r ; i++){
        cin >> idx;
        arr[idx] += 1;
    }
    for(int i = 1 ; i <= n ; i++){
        if(arr[i] == -1){
            if(i != 0 && arr[i-1] == 1){
                arr[i] += 1;
                arr[i-1] -= 1;
            } else if(arr[i+1] == 1){
                arr[i] += 1;
                arr[i+1] -= 1;
            }
        }
        if(arr[i] == -1){
            answer += 1;
        }
    }
    return 0;
}
