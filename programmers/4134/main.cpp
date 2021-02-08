#include <iostream>

using namespace std;

bool IsPrime(int num){
    int k = num/2+1;
    for(int i = 2 ; i < k ; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t_case;
    cin >> t_case;
    for(int i = 0 ; i < t_case ; i++){
        int num;
        cin >> num;
        while(!IsPrime(num++));
        cout << num << endl;
    }
    return 0;
}
