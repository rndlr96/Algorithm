#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        int mx = max(b-a, c-b);
        cout << mx-1 << '\n';
    }
    return 0;
}
