#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool arr[52], partys[52][52], true_party[52];
int n,m, human, tmp;

bool find(int p){
    for(int i = 1 ; i < n ; i++){
        if(partys[p][i] && arr[i]){
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    cin >> human;
    for(int i = 0 ; i < human ; i++){
        cin >> tmp;
        arr[tmp] = true;
    }

    for(int i = 1 ; i <= n ; i++){
        cin >> human;
        for(int j = 1 ; j <= human ; j++){
            cin >> tmp;
            partys[i][tmp] = true;
        }
    }
    fill(true_party, true_party+52, false);

    while(1){
        bool member = false;
        for(int i = 1 ; i <= m ; i++){
            if(true_party[i]) continue;
            if(find(i)){
                for(int j = 1 ; j <= n ; j++){
                    if(partys[i][j] && !arr[j]){
                        arr[j] = true;
                        member = true;
                    }
                }
                true_party[i] = true;
            }
        }
        if(!member) break;
    }
    int answer = 0;
    for(int i = 1 ; i <= m ; i++) {
        if (!true_party) answer++;
    }
    cout << answer << endl;
    return 0;
}
