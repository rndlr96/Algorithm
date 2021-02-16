#include <iostream>
#include <algorithm>;

using namespace std;

int answer[10002];
int n;

void func(){
    if (next_permutation(answer, answer + n) == true)
    {
        for (int i = 0 ; i < n; i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> answer[i];
    }
    func();
    return 0;
}
