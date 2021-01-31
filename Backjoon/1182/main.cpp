#include <iostream>

using namespace std;

int nums[22];
int n,s;
int answer=0;

void func(int sum, int cnt){
    if(cnt == n){
        if(sum == s){
            answer++;
        }
        return;
    }
    func(sum+nums[cnt], cnt+1);
    func(sum, cnt+1);
}

int main() {
    cin >> n >> s;
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }
    func(0,0);
    if(s == 0) answer--;
    cout << answer;
    return 0;
}
