#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
  int arr1[3], arr2[3];
  int input;
  string line;
  cin >> input;
  getline(cin, line);
  if(input == 1){
      getline(cin, line);
      stringstream ss(line);
      string buffer;
      int i = 0;
      while(getline(ss,buffer,' ')){
          arr1[i++] = atoi(buffer.c_str());
      }
      cout << min(min(arr1[0], arr1[1]), arr1[2]) << endl;
  } else {

    for(int j = 0 ; j < input ; j++){
      getline(cin, line);
      stringstream ss(line);
      string buffer;
      int i = 0;
      if ( j == 0 ){
        while(getline(ss,buffer,' ')){
            arr1[i++] = atoi(buffer.c_str());
        }
      } else {
        while(getline(ss,buffer,' ')){
            arr2[i++] = atoi(buffer.c_str());
        }

        arr2[0] = min(arr2[0]+arr1[1], arr2[0]+arr1[2]);
        arr2[1] = min(arr2[1]+arr1[0], arr2[1]+arr1[2]);
        arr2[2] = min(arr2[2]+arr1[0], arr2[2]+arr1[1]);
        copy(arr2, arr2+3, arr1);
      }
    }
  }
  cout << min(min(arr1[0], arr1[1]), arr1[2]) << endl;


  return 0;
}
