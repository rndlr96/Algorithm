#include <iostream>
#include <queue>

using namespace std;

void Print(vector<int> arr){
    cout << "<";
    for(int i = 0 ; i < arr.size()-1 ; i++){
        cout << arr[i] << ", ";
    }
    cout << arr.back() << ">" << endl;
}

int main(void){
    int N, K;
    cin >> N >> K;
    queue<int> numbers;
    vector<int> result;
    for(int i = 0 ; i < N ; i++) {
        numbers.push(i + 1);
    }
    while(!numbers.empty()){
        if(numbers.size() == 1){
            result.push_back(numbers.front());
            numbers.pop();
            break;
        }
        for(int i = 1 ; i < K ; i++){
            numbers.push(numbers.front());
            numbers.pop();
        }
        result.push_back(numbers.front());
        numbers.pop();
    }
    Print(result);
}