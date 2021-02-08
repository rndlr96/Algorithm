#include <iostream>
#include <vector>
#include <algorithm>;

using namespace std;

int main() {
    long long n;
    unsigned long long answer=0;
    cin >> n;
    vector<long long> arr(6);
    vector<long long> mins;
    for(int i = 0 ; i < 6 ; i++){
        cin >> arr[i];
    }
    if(n == 1) {
        sort(arr.begin(), arr.end());
        cout << arr[0]+arr[1]+arr[2]+arr[3]+arr[4];
        return 0;
    }
    mins.push_back(min(arr[0], arr[5]));
    mins.push_back(min(arr[1], arr[4]));
    mins.push_back(min(arr[2], arr[3]));
    sort(mins.begin(), mins.end());
    long long three = mins[0]+mins[1]+mins[2];
    long long two = mins[0]+mins[1];
    answer += 4*three;
    answer += 4*(n-1)*two;
    answer += 4*(n-2)*two;
    answer += (n-1)*(n-2)*4*mins[0];
    answer += (n-2)*(n-2)*mins[0];
    cout << answer;
    return 0;
}
