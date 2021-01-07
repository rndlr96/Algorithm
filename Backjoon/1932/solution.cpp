#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(void) {
	int input, *arr1, *arr2, max_val;
	string line;
	cin >> input;

	arr1 = (int*)calloc(input,sizeof(int));
	arr2 = (int*)calloc(input,sizeof(int));
	getline(cin, line);

	for (int i = 0; i < input; i++) {
		getline(cin, line);
		stringstream ss(line);
		string buffer;
		if (i == 0) {
			arr1[0] = atoi(line.c_str());
			max_val = arr1[0];
		}
		else {
			int j = 0;
			while (getline(ss, buffer, ' ')) {
				arr2[j++] = atoi(buffer.c_str());
			}
			for (j = 0; j < i; j++) {
				if (j == 0) {					// 제일 앞
					arr2[0] = arr2[0] + arr1[0];
					max_val = max(max_val, arr2[0]);
				}
				else if (j == i - 1) {			// 제일 뒤
					arr2[j] = arr2[j] + arr1[j - 1];
					max_val = max(max_val, arr2[j]);
				}
				else {
					arr2[j] = max(arr2[j] + arr1[j - 1], arr2[j] + arr1[j]);
					max_val = max(max_val, arr2[j]);
				}
			}
            copy(arr2, arr2+input, arr1);
		}
	}
	cout << max_val << endl;

}
