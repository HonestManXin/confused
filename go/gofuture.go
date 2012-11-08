package main

import "fmt"
import "time"
import "math/rand"
import "runtime"

func routine(name string, delay time.Duration) {
	t0 := time.Now()
	fmt.Println(name, " routine start at :..", t0)

	time.Sleep(delay)

	t1 := time.Now()
	fmt.Println(name, " routine end at ", t1)

	fmt.Println(name, " routine lasted ", t1.Sub(t0))
}

func main() {
	runtime.GOMAXPROCS(4)
	rand.Seed(time.Now().Unix())

	var name string

	for i := 0; i < 3; i++ {
		name = fmt.Sprintf("go_%02d", i)
		go routine(name, time.Duration(rand.Intn(5))*time.Second)
	}

	var input string
	fmt.Scanln(&input)
	fmt.Println("done ", input)
}
