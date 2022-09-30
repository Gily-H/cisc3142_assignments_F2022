LAB1_DIR=./lab1/src
LAB2_DIR=./lab2/src
LAB4_DIR=./lab4/src

#### LAB 1 ####
lab1: $(LAB1_DIR)/hello_world
	echo "Starting Lab 1 Hello World Program"
	$(LAB1_DIR)/hello_world
	make clean_lab1

hello_world: $(LAB1_DIR)/hello_world.cpp
	g++ $(LAB1_DIR)/hello_world.cpp -o hello_world

#### LAB 2 ####
lab2: $(LAB2_DIR)/exercise1_5 $(LAB2_DIR)/exercise1_11_for_loop $(LAB2_DIR)/exercise1_11_while_loop
	echo "Starting Lab 2 Exercise 1.5"
	$(LAB2_DIR)/exercise1_5
	echo "Starting Lab 2 Exercise 1.11 - for-loop"
	$(LAB2_DIR)/exercise1_11_for_loop
	echo "Starting Lab 2 Exercise 1.11 - while-loop"
	$(LAB2_DIR)/exercise1_11_while_loop 
	make clean_lab2

exercise1_5: $(LAB2_DIR)/exercise1_5.cpp
	g++ $(LAB2_DIR)/exercise1_5.cpp -o $(LAB2_DIR)/exercise1_5

exercise1_11_for_loop: $(LAB2_DIR)/exercise1_11_for_loop.cpp
	g++ $(LAB2_DIR)/exercise1_11_for_loop.cpp -o $(LAB2_DIR)/exercise1_11_for_loop

exercise1_11_while_loop: $(LAB2_DIR)/exercise1_11_while_loop.cpp
	g++ $(LAB2_DIR)/exercise1_11_while_loop.cpp -o $(LAB2_DIR)/exercise1_11_while_loop

#### LAB 3 ####
lab3:

#### LAB 4 ####
lab4: $(LAB4_DIR)/exercise3_17 $(LAB4_DIR)/exercise3_23 $(LAB4_DIR)/exercise4_28 $(LAB4_DIR)/inflation $(LAB4_DIR)/nutrition_calculator
	echo "Starting lab 4 exercise 3.17"
	$(LAB4_DIR)/exercise3_17
	echo "Starting lab 4 exercise 3.23"
	$(LAB4_DIR)/exercise3_23
	echo "Starting lab 4 exercise 4.28"
	$(LAB4_DIR)/exercise4_28
	echo "Starting lab 4 inflation"
	$(LAB4_DIR)/inflation
	echo "Starting lab 4 nutrition calculator"
	$(LAB4_DIR)/nutrition_calculator
	make clean_lab4

exercise3_17: $(LAB4_DIR)/exercise3_17.cpp
	g++ $(LAB4_DIR)/exercise3_17.cpp -o $(LAB4_DIR)/exercise3_17

exercise3_23: $(LAB4_DIR)/exercise3_23.cpp
	g++ $(LAB4_DIR)/exercise3_23.cpp -o $(LAB4_DIR)/exercise3_23

exercise4_28: $(LAB4_DIR)/exercise4_28.cpp
	g++ $(LAB4_DIR)/exercise4_28.cpp -o $(LAB4_DIR)/exercise4_28

inflation: $(LAB4_DIR)/inflation.cpp
	g++ $(LAB4_DIR)/inflation.cpp -o $(LAB4_DIR)/inflation

nutrition_calculator: $(LAB4_DIR)/nutrition_calculator.cpp
	g++ $(LAB4_DIR)/nutrition_calculator.cpp -o $(LAB4_DIR)/nutrition_calculator

# removes all files that are not source files with extension .cpp
clean_lab1:
	rm $(LAB1_DIR)/hello_world 

clean_lab2:
	rm $(LAB2_DIR)/exercise1_5 $(LAB2_DIR)/exercise1_11_for_loop $(LAB2_DIR)/exercise1_11_while_loop

clean_lab3:

clean_lab4:
	rm $(LAB4_DIR)/exercise3_17 $(LAB4_DIR)/exercise3_23 $(LAB4_DIR)/exercise4_28 \
	$(LAB4_DIR)/inflation $(LAB4_DIR)/nutrition_calculator

# phony target removes shell command from output
.SILENT:

all: lab1 lab2 lab3 lab4