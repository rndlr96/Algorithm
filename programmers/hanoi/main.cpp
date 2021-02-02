#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int start, int end){
    if(n == 1){
        answer.push_back({start,end});
        return;
    } else{
        int mid;
        if((start == 1 && end == 2) || (start == 2 && end == 1)) mid = 3;
        else if((start == 1 && end == 3) || (start == 3 && end == 1)) mid = 2;
        else mid = 1;
        hanoi(n-1, start, mid);
        answer.push_back({start,end});
        hanoi(n-1, mid, end);
        return;
    }
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3);
    cout << "[ ";
    for(int i = 0 ; i < answer.size() ; i++){
        cout << "[" << answer[i][0] << "," << answer[i][1] << ", ";
    }
    cout << " ]";
    return answer;
}

int main(){
    int n;
    cin >> n;
    solution(n);
}
