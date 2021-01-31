#include <iostream>
#include <stack>

using namespace std;

int arr[28];

int main() {
    int n;
    string input;
    stack<double> nums;
    cin >> n;
    cin >> input;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < input.size() ; i++){
        if(input[i] <= 'Z' && input[i] >= 'A'){
            nums.push(arr[input[i]-'A']);
        } else {
            double back = nums.top(); nums.pop();
            double front = nums.top(); nums.pop();

            switch(input[i]){
                case '+':
                    nums.push(front + back);
                    break;
                case '-':
                    nums.push(front - back);
                    break;
                case  '*':
                    nums.push(front * back);
                    break;
                case  '/':
                    nums.push(front / back);
                    break;
            }
        }
    }
    printf("%.2f\n", nums.top());

    return 0;
}
