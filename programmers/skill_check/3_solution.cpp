#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<> > q;
    int tmp = 0, answer = 0;
    for (int target : scoville){
        q.push(target);
    }
    while(q.top() < K){
        if (q.size() < 2){
            return -1;
        } else{
            tmp = q.top(); q.pop();
            tmp = tmp + q.top()*2; q.pop();
            q.push(tmp);
            answer++;
        }
    }
    return answer;
}
