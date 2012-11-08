package main

import "fmt"

func main() {
	mychannel := make(chan string)

	go func() {
		mychannel <- "hello world"
	}()

	msg := <-mychannel
	fmt.Println(msg)
}
