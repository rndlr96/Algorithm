#include <iostream>

int arr[10];
int visit[10];
int n,m;

using namespace std;

void func(int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 0 ; i < n ; i++){
        if(!visit[i]){
            arr[cnt] = i+1;
            visit[i] = 1;
            func(cnt+1);
            visit[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    fill(visit, visit+n, 0);
    func(0);
    return 0;
}
