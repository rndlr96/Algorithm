#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    vector<int> fin_time;
    fin_time.resize((int)(times.size()));

    n -= times.size();
    copy(times.begin(), times.end(), fin_time.begin());
    while(n != 0 ){
        n -= 1;
        int min = *min_element(fin_time.begin(), fin_time.end());
        for(int i = 0 ; i < fin_time.size() ; i++){
            if(fin_time[i] == min){
                fin_time[i] += times[i];
            }
        }
        for(int i = 0 ; i < fin_time.size() ; i++){
            cout << fin_time[i] << " ";
        }
        cout << endl;
    }
    answer = *max_element(fin_time.begin(), fin_time.end());
    return answer;
}

int main() {
    solution(6, [7,10]);
    return 0;
}
