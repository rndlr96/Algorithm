#include <iostream>

using namespace std;

int test_case,n,m, answer;
int arr[2002];


void func(int num, int cnt){
    if(cnt == n){
        answer++;
        return;
    }
    for(int i = num ; i <= m ; i++){
        if(cnt > 0 && arr[cnt-1]*2 > i) continue;
        arr[cnt] = i;
        func(i,cnt+1);
    }
}

int main() {
    cin >> test_case;
    for(int i = 0 ; i < test_case ; i++){
        cin >> n >> m;
        answer = 0;
        func(1, 0);
        cout << answer << '\n';
    }
    return 0;
}
