#include <iostream>

using namespace std;

int main() {
    int n,m, answer;
    cin >> n >> m;
    int boxs=0, books=0, tmp;
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        boxs += tmp;
    }
    for(int i = 0 ; i < m ; i++){
        cin >> tmp;
        books += tmp;
    }
    answer = boxs-books;
    cout << answer;
    return 0;
}
