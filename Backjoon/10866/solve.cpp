#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

struct command {
	string key;
	int value;
};

int main(){
	int n, i; // 명령의 수
	cin >> n; // 명령의 수 입력
	char *input = (char*)malloc(20);
	int value;
	command tmp;
	queue<command> comm;
	vector<int> deck;

	for(i = 0 ; i < n ; i++){
		cin.ignore();
		cin >> input;
		if(strcmp(input, "push_back") == 0) {
			cin >> value;
			tmp.key = "push_back";
			tmp.value = value;
			comm.push(tmp);
		}
		else if(strcmp(input, "push_front") == 0) {
			cin >> value;
			tmp.key = "push_front";
			tmp.value = value;
			comm.push(tmp);
		}
		else if(strcmp(input, "pop_front") == 0) {
			tmp.key = "pop_front";
			comm.push(tmp);
		}
		else if(strcmp(input, "pop_back") == 0){
			tmp.key = "pop_back";
			comm.push(tmp);
		}
		else if(strcmp(input, "front") == 0){
			tmp.key = "front";
			comm.push(tmp);
		}
		else if(strcmp(input, "back") == 0){
			tmp.key = "back";
			comm.push(tmp);
		}
		else if(strcmp(input, "empty") == 0){
			tmp.key = "empty";
			comm.push(tmp);
		}
		else if(strcmp(input, "size") == 0){
			tmp.key = "size";
			comm.push(tmp);
		}
	}

	while(!comm.empty()){
		tmp = comm.front();
		if(tmp.key.compare("push_back") == 0) {
			deck.push_back(tmp.value);
		}
		else if(tmp.key.compare("push_front") == 0) {
			deck.insert(deck.begin(),tmp.value);
		}
		else if(tmp.key.compare("pop_front") == 0) {
			if(deck.empty() == 1){
				printf("-1\n");
			} else {
				printf("%d\n", deck.front());
				deck.erase(deck.begin());
			}
		}
		else if(tmp.key.compare("pop_back") == 0){
			if(deck.empty() == 1){
				printf("-1\n");
			} else{
				printf("%d\n", deck.back());
				deck.pop_back();
			}
		}
		else if(tmp.key.compare("front") == 0){
			printf("%d\n", deck.front());
		}
		else if(tmp.key.compare("back") == 0){
			printf("%d\n", deck.back());
		}
		else if(tmp.key.compare("empty") == 0){
			printf("%d\n", deck.empty());
		}
		else if(tmp.key.compare("size") == 0){
			printf("%d\n", (int)deck.size());
		}
		comm.pop();
	}
}
