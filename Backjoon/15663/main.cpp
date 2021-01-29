#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int arr[10];
int before[10];
bool visit[10];
int n, m;

void func(int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            before[i] = arr[i];
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    bool check[10002];
    fill(check, check+10002, false);
    for(int i = 0 ; i < n ; i++){
        if(!visit[i] && !check[nums[i]]){
            visit[i] = true;
            check[nums[i]] = true;
            arr[cnt] = nums[i];
            func(cnt+1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    fill(visit, visit+m, false);
    sort(nums.begin(), nums.end(), less<int>());
    func(0);
    return 0;
}
