#include <iostream>
#include <stack>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> buildings;
    int n;
    int num;

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> num;

        while(!buildings.empty()){
            if(buildings.top().first > num){
                cout << buildings.top().second+1 << " ";
                buildings.push({num,i});
                break;
            } else{
                buildings.pop();
            }
        }
        if(buildings.empty()) {
            cout << "0 ";
            buildings.push({num,i});
        }
    }
    return 0;
}
