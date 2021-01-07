#include <iostream>

using namespace std;

int main(){
    int *ptr;
    int input,i;
    cin >> input;

    ptr = (int *)malloc(sizeof(int)*input);
    ptr[0] = 1;
    ptr[1] = 2;

    if(input ==1){
        cout << "1" << endl;
    } else if(input == 2){
        cout << "2" << endl;
    } else {
        for(i=2 ; i < input ; i++){
            ptr[i] = (ptr[i-1]+ptr[i-2])%10007;
        }
        cout << ptr[input-1]%10007 << endl;
    }
    return 0;
}
