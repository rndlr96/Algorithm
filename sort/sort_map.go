package main

import "fmt"

func main() {
	var input int
	fmt.Scanln(&input)
	arr := make([]int, input)

	for i := 0; i < input; i++ {
		fmt.Scanln(&arr[i])
	}

	for i := 0; i < input-1; i++ {
		for j := i + 1; j < input; j++ {
			if arr[i] > arr[j] {
				arr[i], arr[j] = arr[j], arr[i]
			}
		}
	}

	for i := 0; i < input; i++ {
		fmt.Println(arr[i])
	}
}
