#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    int total = 0;
    for(int i = 0 ; i < works.size() ; i++){
        total += works[i];
    }
    if (total <= n){
        return 0;
    }

    priority_queue< int, vector<int>, less<int> > q;
    while(!works.empty()){
        q.push(works.front());
        works.erase(works.begin());
    }
    int i = 0;
    for(i=0 ; i < n+1 ; i++){
        int tmp = q.top()-1;
        q.push(tmp);
        q.pop();
        cout << q.top();
    }
    //while(!q.empty()){
    //    answer += pow(q.top(),2);
    //    q.pop();
    //}
    return answer;
}

int main(){
  int n = 4;
  vector<int> works;
  works.push_back(4);
  works.push_back(3);
  works.push_back(3);
  solution(n, works);

}
