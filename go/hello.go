package main

import "fmt"
import "errors"

//learn how to define a function
func max(a int, b int) (int, bool) {
	var max int
	if a == b {
		return a, false
	}
	if a > b {
		max = a
	} else {
		max = b
	}
	return max, true
}

//multi args
func sum(nums ...int) {
	fmt.Println("nums are ....", nums)
}

//closure args
func outfunc() func() int {
	i, j := 1, 2
	return func() int {
		var temp int = i + j
		i, j = temp, i
		return temp
	}
}

//recursive method
func fact(n int) int {
	if n == 1 {
		return 1
	}
	return n * fact(n-1)
}

//struct define
type Person struct {
	name  string
	age   int
	email string
}

//struct method
type rect struct {
	width int
	hight int
}

func (re *rect) area() int {
	return re.hight * re.width
}

func (re *rect) primeter() int {
	return 2 * (re.width + re.hight)
}

//interface about go
type shape interface {
	area() int
	primeter() int
}

type square struct {
	edge int
}

func (s *square) area() int {
	return s.edge * s.edge
}

func (s *square) primeter() int {
	return 4 * s.edge
}

//error interface for error handler
type myError struct {
	arg    int
	errMsg string
}

func (e *myError) Error() string {
	return fmt.Sprintf("%d - %s", e.arg, e.errMsg)
}

func error_test(arg int) (int, error) {
	if arg < 0 {
		return -1, errors.New("Bad Arguments--negative")
	} else if arg > 256 {
		return -1, &myError{arg, "Bad Arguments--too large"}
	}
	return arg * arg, nil
}

//error handler for panic and recover
func panic_test(i int) {
	if i > 1 {
		fmt.Println("Panic!....")
		panic(fmt.Sprintf("%v", i))
	}
}

func recover_test() {
	defer func() {
		if r := recover(); r != nil {
			fmt.Println("recovered in recover_test  .....", r)
		}
	}()

	for i := 0; i < 4; i++ {
		fmt.Println("call panic_test with i = ", i)
		panic_test(i)
		fmt.Println("return normally from panic_test..")
	}
}

func main() {
	var s string = "Hello World"
	var x int = 10
	//var b = true
	//y := 100

	//const z int = 200
	const pi float32 = 3.1415

	fmt.Printf("%d %f %s \n", x, pi, s)

	var a [5]int
	fmt.Println("array ..", a)
	for i := 0; i < 5; i++ {
		a[i] = i
	}
	fmt.Println("after assignment ...", a)

	var c [2][3]int
	for i := 0; i < 2; i++ {
		for j := 0; j < 3; j++ {
			c[i][j] = i + j + 1
		}
	}

	fmt.Println("2d array ...", c)

	d := [5]int{1, 2, 3, 4, 5}
	fmt.Println("After slice ...", d[:4])

	var e int = 7
	if e%2 == 0 {
		fmt.Println("e is odd number ...", e)
	} else {
		fmt.Println("e is even number...", e)
	}

	var i int = 2
	switch i {
	case 1:
		fmt.Println("i is 1")
	case 2:
		fmt.Println("i is 2")
	case 3, 4, 5:
		fmt.Println("i is 3 or 4 or 5")
	}

	//map test
	m := make(map[string]int)
	m["one"] = 1
	m["two"] = 2
	m["three"] = 3
	fmt.Println("map m is ...", m)

	fmt.Println("two value is ...", m["two"])

	delete(m, "two")
	fmt.Println("after delete two m is ...", m)

	m1 := map[string]int{"one": 1, "four": 4, "five": 5}
	fmt.Println("m1 value is ....", m1)

	//print map key value 
	for key, value := range m1 {
		fmt.Println("key is ", key, " value is ", value)
	}

	//pointer
	i = 2
	var pInt *int = &i
	fmt.Println("i's point is", pInt)
	fmt.Println("i's value from point is ..", *pInt)

	//the difference between new and make
	var p *[]int = new([]int)
	fmt.Println("new *p is ...", p)
	*p = make([]int, 10, 10)
	fmt.Println("make *p and p is... ", p)
	fmt.Println("make *p and *p 2 is ...", (*p)[2])

	var pp []int = make([]int, 10)
	fmt.Println("make pp and pp is ...", pp)

	//definite size []int
	var dp *[10]int = new([10]int)
	fmt.Println("definite new pointer is...", dp)

	//use a customer function
	rd, re := max(2, 3)
	fmt.Println("rd and re are ....", rd, re)
	//function may return false then we can diagnose what happen
	if rd, re = max(3, 5); re {
		fmt.Println("function is normal")
	} else {
		fmt.Println("function is abnormal")
	}

	//function with indefinite args 
	sum(1, 2, 34)
	sum(1, 2, 3, 4, 5, 6)

	//closure
	innerFunc := outfunc()
	fmt.Println("fist call innerFunc... ", innerFunc())
	fmt.Println("second call innerFunc... ", innerFunc())

	//recursive
	fmt.Println("recursive result is...", fact(5))

	//struct 
	var person Person = Person{"tom", 30, "tom@gmail.com"}
	fmt.Println("person is ...", person)
	person.age = 40
	fmt.Println("after change person ....", person)
	pPerson := &person
	fmt.Println("point of person ....", pPerson)
	cPerson := person
	fmt.Println("copy of person ....", cPerson)
	cPerson.name = "jerry"
	fmt.Println("after copy change ....", cPerson, person)

	//struct method
	r := rect{width: 10, hight: 20}
	fmt.Println("area is .....", r.area())
	fmt.Println("perimeter is....", r.primeter())

	//interface test
	ss := square{edge: 20}
	sh := []shape{&r, &ss}
	fmt.Println("interface test result...")
	for _, shr := range sh {
		fmt.Println(shr)
		fmt.Println(shr.area())
		fmt.Println(shr.primeter())
	}

	//error handler test
	for _, i := range []int{-1, 4, 1000} {
		if err_r, err_e := error_test(i); err_e != nil {
			fmt.Println("failed :", err_e)
		} else {
			fmt.Println("sucucess :", err_r)
		}
	}

	//panic and recover 
	fmt.Println()
	fmt.Println("panic and recover test begin...")
	recover_test()
	fmt.Println("return normally from recover_test....in main")
}
