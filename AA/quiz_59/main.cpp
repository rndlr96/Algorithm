
#include <iostream>
#include <vector>

using namespace std;

void DFS(int n, int * arr, vector<int> check, bool *answer){
    if( n == check.size() ){
        int a=0, b=0;
        for(int i = 0 ; i < check.size() ; i++){
            if(check[i] == 1){
                a += arr[i];
            } else{
                b += arr[i];
            }
        }
        if ( a == b){
            *answer = true;
        }
    } else{
        DFS(n+1, arr, check, answer);
        check[n] = 1;
        DFS(n+1, arr, check, answer);
    }
}

int main() {
    int number;
    cin >> number;
    int arr[number];
    bool answer = false;
    vector<int> check(number, 0);

    for(int i = 0 ; i < number ; i++){
        cin >> arr[i];
    }
    DFS(0, arr, check, &answer);
    if ( answer == true){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}
