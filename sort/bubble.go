package main

import "fmt"

func main(){
  var length int;
  fmt.Scanln(&length);
  arr := make([]int, length);

  for i:=0 ; i < length ; i++ {
    fmt.Scanln(&arr[i]);
  }

  for i:=0 ; i < length-1 ; i++ {
    for j:=1 ; j < length-i ; j++ {
      if arr[j-1] > arr[j]{
        arr[j-1], arr[j] = arr[j], arr[j-1];
      }
    }
  }

  fmt.Println(arr)
}
