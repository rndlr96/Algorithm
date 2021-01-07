#include <iostream>

using namespace std;
void insert(int *cache, int n, int end){
    for ( int i = 0 ; i < sizeof(cache)/sizeof(int) ; i++){

    }
}

int main() {
    int cache_size, work_size;
    cin >> cache_size >> work_size;
    int task[work_size], cache[cache_size];

    for (int i = 0 ; i < work_size ; i++){
        cin >> task[i];
    }

    for (int i = 0 ; i < work_size ; i++){
        int j = 0;
        for ( j = 0 ; j < cache_size ; j++){
            if ( cache[j] == task[i]){
                break;
            }
        }
        for ( int k = j ; k > 0 ; k--){
            int tmp = cache[k];
            cache[k] = cache[k-1];
            cache[k-1] = tmp;
        }
        cache[0] = task[i];

        for ( int i = 0 ; i < cache_size ; i++){
            cout << cache[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
