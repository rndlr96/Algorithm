#include <iostream>

using namespace std;

int arr[10];
bool visit[10];
int n,m;

void func(int num, int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    for(int i = num ; i < n ; i++){
        if(!visit[i]){
            visit[i] = true;
            arr[cnt] = i+1;
            func(i,cnt+1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    fill(visit, visit+m, false);
    func(0, 0);
    return 0;
}
