#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> in_bridge;
    vector<int> timer;
    int answer = 0;

    while(!truck_weights.empty()){
        answer += 1;
        if (!timer.empty() && timer[0] == 0){
            timer.erase(timer.begin());
            weight += in_bridge.front();
            in_bridge.pop();
        }
        if (truck_weights.front() <= weight){
            in_bridge.push(truck_weights.front());
            timer.push_back(bridge_length);
            weight -= truck_weights.front();
            truck_weights.erase(truck_weights.begin());
        }
        for (int i=0 ; i < timer.size() ; i++){
            timer[i] -= 1;
        }
    }
    return answer+bridge_length;
}
