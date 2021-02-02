#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int n,m,num,idx, cnt;

int main() {
    cin >> n >> m;
    cnt = 0;
    for(int i = 1 ; i <= n ; i++){
        dq.push_back(i);
    }
    for(int i = 0 ; i < m ; i++){
        cin >> num;
        for(int i = 0 ; i < dq.size() ; i++){
            if(dq[i] == num){
                idx = i;
                break;
            }
        }
        if(idx > dq.size()-idx){
            while(dq.front() != num){
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.pop_front();
        } else {
            while(dq.front() != num){
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        }
    }
    cout << cnt;
    return 0;
}
