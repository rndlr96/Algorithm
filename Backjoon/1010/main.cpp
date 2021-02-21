#include <iostream>

int factor[32][32];

using namespace std;

int main() {
    for(int i = 1 ; i <= 30 ; i++) factor[1][i] = i;
    for(int i = 2 ; i <= 30 ; i++){
        for(int j = i ; j <= 30 ; j++){
            for(int k = 1 ; k < j ; k++){
                factor[i][j] += factor[i-1][k];
            }
        }
    }
    int case_n;
    cin >> case_n;
    for(int i = 0 ; i < case_n ; i++){
        int n,m;
        cin >> n >> m;
        cout << factor[n][m] << '\n';
    }
    return 0;
}
