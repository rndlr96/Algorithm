#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int arr[9];
int n,m;

void func(int num, int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    bool check[10002];
    fill(check, check+10002, false);
    for(int i = num ; i < n ; i++){
        if(!check[nums[i]]){
            check[nums[i]] = true;
            arr[cnt] = nums[i];
            func(i,cnt+1);
        }

    }
}

int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int tmp; cin >> tmp; nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end(), less<int>());
    func(0, 0);
    return 0;
}
