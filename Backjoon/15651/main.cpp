#include <iostream>

using namespace std;

int n,m;
int arr[9];

void func(int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 0 ; i < n ; i++){
        arr[cnt] = i+1;
        func(cnt+1);
    }
}

int main() {
    cin >> n >> m;
    func(0);
    return 0;
}
