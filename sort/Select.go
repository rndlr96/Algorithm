package main

import "fmt"

func main(){
  var length int;
  fmt.Scanln(&length);
  arr := make([]int, length);

  for i:=0 ; i < length ; i++ {
    fmt.Scanln(&arr[i]);
  }

  for i:=0 ; i < length-1 ; i++{
    min := arr[i];
    index := i;
    for j:=i ; j < length ; j++{
      if arr[j] < min{
        min = arr[j];
        index = j;
      }
    }
    arr[i], arr[index] = arr[index], arr[i];
  }

  fmt.Println(arr);
}
