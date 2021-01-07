#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int size, number;
    vector<int> answer;

    cin >> size;
    vector<int> first(size);
    for(int i = 0 ; i < size ; i++){
        scanf("%d", &first[i]);
    }

    cin >> size;
    vector<int> second(size);
    for(int i = 0 ; i < size ; i++){
        scanf("%d", &second[i]);
    }


    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    int p1 = 0, p2 = 0;
    while( p1 < first.size() && p2 < second.size()){
        if (first[p1] < second[p2]){
            p1 += 1;
        } else if (first[p1] == second[p2]){
            answer.push_back(first[p1]);
            p1 += 1;
            p2 += 1;
        } else{
            p2 += 1;
        }
    }

    for ( int i = 0 ; i < answer.size() ; i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}
