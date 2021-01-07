#include <iostream>
#include <vector>

using namespace std;

void DFS(int n, vector<int> check){
    if(n == check.size()){
        for(int i = 0 ; i < check.size() ; i++){
            if(check[i] == 1){
                cout << i+1 << " ";
            }
        }
        cout << endl;
    } else{
        check[n] = 1;
        DFS(n+1, check);
        check[n] = 0;
        DFS(n+1, check);
    }
}

int main() {
    int number;
    cin >> number;
    vector<int> check(number, 0);
    DFS(0, check);
    return 0;
}
