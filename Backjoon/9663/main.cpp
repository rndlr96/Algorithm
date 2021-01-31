#include <iostream>

using namespace std;

bool visit1[17];
bool visit2[33];
bool visit3[33];
int n;
int answer = 0;

void func(int cnt){
    if(cnt == n){
        answer++;
        return;
    }
    for(int i = 0 ; i < n ; i++){
        if(visit1[i] || visit2[cnt+i] || visit3[cnt-i+n-1]) continue;
        visit1[i] = true;
        visit2[cnt+i] = true;
        visit3[cnt-i+n-1] = true;
        func(cnt+1);
        visit1[i] = false;
        visit2[cnt+i] = false;
        visit3[cnt-i+n-1] = false;

    }
}

int main() {
    cin >> n;
    fill(visit1, visit1+n, false);
    fill(visit2, visit2+(2*n-1), false);
    fill(visit3, visit3+(2*n-1), false);
    func(0);
    cout << answer;
    return 0;
}
