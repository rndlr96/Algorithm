#include <iostream>

using namespace std;

void DFS(int v){
    if(v > 7) return;
    else{
        DFS(v*2);
        cout << v << " ";
        DFS(v*2+1);
    }
}

int main() {
    int number;
    cin >> number;
    DFS(1);
    return 0;
}
