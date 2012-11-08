package main

import "fmt"
import "time"
import "math/rand"
import "runtime"
import "sync"

var total_ticket = 10

func sell_ticket(i int) {
	for {
		if total_ticket > 0 {
			time.Sleep(time.Duration(rand.Intn(5)) * time.Millisecond)
			total_ticket--
			fmt.Println("id: ", i, "  remain ticket :...", total_ticket)
		} else {
			break
		}
	}
}

func main() {
	runtime.GOMAXPROCS(4)
	rand.Seed(time.Now().Unix())

	for i := 0; i < 5; i++ {
		go sell_ticket(i)
	}

	var input string
	fmt.Scanln(&input)
	fmt.Println(total_ticket, "  done")
}
