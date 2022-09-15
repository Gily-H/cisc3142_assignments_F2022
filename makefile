LAB1=./lab1/src
LAB2=./lab2/src

#### LAB 1 ####
lab1: $(LAB1)/hello_world
	echo "Starting Lab 1 Hellow World Program"
	cd $(LAB1) && ./hello_world

hello_world: $(LAB1)/hello_world.cpp
	cd $(LAB1) && g++ -o hello_world hello_world.cpp

#### LAB 2 ####
lab2: $(LAB2)/exercise1_5 $(LAB2)/exercise1_11_for_loop $(LAB2)/exercise1_11_while_loop
	echo "Starting Lab 2 Exercise 1.5"
	cd $(LAB2) && ./exercise1_5
	echo "Starting Lab 2 Exercise 1.11 - for-loop"
	cd $(LAB2) && ./exercise1_11_for_loop
	echo "Starting Lab 2 Exercise 1.11 - while-loop"
	cd $(LAB2) && ./exercise1_11_while_loop 
	make clean_lab2

exercise1_5: $(LAB2)/exercise1_5.cpp
	cd $(LAB2) && g++ -o exercise1_5 exercise1_5.cpp

exercise1_11_for_loop: $(LAB2)/exercise1_11_for_loop.cpp
	cd $(LAB2) && g++ -o exercise1_11_for_loop exercise1_11_for_loop.cpp

exercise1_11_while_loop: $(LAB2)/exercise1_11_while_loop.cpp
	cd $(LAB2) && g++ -o exercise1_11_while_loop exercise1_11_while_loop.cpp


# removes all files that are not source files with extension .cpp
clean_lab1:
	cd $(LAB1) && rm -rf hello_world hello_world.o

clean_lab2:
	cd $(LAB2) && rm -rf exercise1_5 exercise1_5.o exercise1_11_for_loop exercise1_11_while_loop exercise1_11_for_loop.o exercise1_11_while_loop.o
