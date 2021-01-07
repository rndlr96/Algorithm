#include <iostream>

using namespace std;

int answer = 0, size = 0, target = 0;

void DFS(int n, int target, int *arr, int sum){
    if( n == size){
        if(sum == target){
            answer++;
        }
    } else{
        DFS(n+1, target, arr, sum+arr[n]);
        DFS(n+1, target, arr, sum-arr[n]);
        DFS(n+1, target, arr, sum);
    }
}

int main() {
    cin >> size >> target;
    int arr[size];
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }
    DFS(0, target, arr, 0);
    if(answer == 0){
        cout << "-1" << endl;
    } else{
        cout << answer << endl;
    }
    return 0;
}
