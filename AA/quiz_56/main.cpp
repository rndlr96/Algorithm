#include <iostream>

using namespace std;

void binary(int x){
    if(x == 0){
        return;
    } else{
        binary(x/2);
        cout << x%2;
    }
}

int main() {
    int number;
    cin >> number;

    binary(number);

    return 0;
}
