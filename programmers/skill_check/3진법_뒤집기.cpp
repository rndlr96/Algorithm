#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 0;
    while(pow(3,i) < n){
        i++;
    }
    for(int j = i-1 ; j >= 0 ; j--){
        int tmp1 = int(n / pow(3,j)) * int(pow(3,i-j-1));
        //int tmp2 = (n/pow(3,j));
        answer += tmp1;
        n %= int(pow(3,j));
    }
    return answer;
}

int main(){
  cout << solution(125);
}
