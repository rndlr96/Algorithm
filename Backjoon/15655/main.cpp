#include <iostream>
#include <vector>

using namespace std;

int arr[10];
bool visit[10];
vector<int> nums;
int n,m;

void func(int num, int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = num ; i < n ; i++){
        if(!visit[i]){
            visit[i] = true;
            arr[cnt] = nums[i];
            func(i, cnt+1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    fill(visit, visit+n, false);
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end(), less<int>());
    func(0,0);
    return 0;
}
