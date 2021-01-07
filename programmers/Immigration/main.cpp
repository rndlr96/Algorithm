#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end(), greater<int>());
    vector<pair<int,int>> fin_time;
    for(auto i : times){
        fin_time.push_back(make_pair(i, i));
    }

    while(n > 1){
        n -= 1;
        fin_time[0].first += fin_time[0].second;

        if(n == 1){
            for(int i = 1 ; i < fin_time.size() ; i++){
                fin_time[i].first -= fin_time[i].second;
            }
        }

        sort(fin_time.begin(), fin_time.end(), less<pair<int,int>>());
        for(int i = 0 ; i < fin_time.size() ; i++){
            cout << fin_time[i].first << " ";
        }
        cout << endl;
    }
    return fin_time.back().first;
}

int main() {
    cout << solution(6, {7,10}) << endl;
    return 0;
}
