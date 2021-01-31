#include <iostream>

    int arr[12];
    bool visit[12];
    int n,m,t;

    using namespace std;
    int answer = 0;
    void func(int num, int cnt){
        if(cnt == n){
            answer++;
            return;
        }
        for(int i = num ; i <= m ; i++){
            if(!visit[i]){
                if(cnt > 0 && int(arr[cnt-1]*2) > i) continue;
                arr[cnt] = i;
                func(i, cnt+1);
            }
        }
    }

    int main() {
        cin >> t;
        for(int i = 0 ; i < t ; i++){
            cin >> n >> m;
            fill(visit, visit+n, false);
            func(1,0);
            cout << answer << '\n';
        }
        return 0;
}
