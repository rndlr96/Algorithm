#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int n;


int main() {
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string command;
        cin >> command;
        if(command == "push"){
            int num;
            cin >> num;
            a.push_back(num);
        }
        else if(command == "pop"){
            if(!a.empty()){
                cout << a.back();
                a.pop_back();
            } else cout << -1;
            cout << '\n';
        }
        else if(command == "size"){
            cout << a.size();
            cout << '\n';
        }
        else if(command == "empty"){
            if(!a.empty())  cout << 0;
            else cout << 1;
            cout << '\n';
        }
        else if(command == "top"){
            if(a.empty()) cout << -1;
            else cout << a.back();
            cout << '\n';
        }
    }
    return 0;
}
