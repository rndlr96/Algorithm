#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> rope;
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++){
        int tmp;
        cin >> tmp;
        rope.push_back(tmp);
    }
    sort(rope.begin(), rope.end());
    for(int i = 0 ; i < rope.size() ; i++){
        rope[i] = rope[i]* (num-i);
    }
    sort(rope.begin(), rope.end(), greater<int>());
    cout << rope[0];
    return 0;
}
