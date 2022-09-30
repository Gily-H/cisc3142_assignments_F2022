LAB1_DIR=./lab1/src
LAB2_DIR=./lab2/src
LAB4_DIR=./lab4/src

#### LAB 1 ####
lab1: $(LAB1_DIR)/hello_world
	echo "Starting Lab 1 Hello World Program"
	@cd $(LAB1_DIR) && ./hello_world
	make clean_lab1

hello_world: $(LAB1_DIR)/hello_world.cpp
	cd $(LAB1_DIR) && g++ -o hello_world hello_world.cpp

#### LAB 2 ####
lab2: $(LAB2_DIR)/exercise1_5 $(LAB2_DIR)/exercise1_11_for_loop $(LAB2_DIR)/exercise1_11_while_loop
	echo "Starting Lab 2 Exercise 1.5"
	cd $(LAB2_DIR) && ./exercise1_5
	echo "Starting Lab 2 Exercise 1.11 - for-loop"
	cd $(LAB2_DIR) && ./exercise1_11_for_loop
	echo "Starting Lab 2 Exercise 1.11 - while-loop"
	cd $(LAB2_DIR) && ./exercise1_11_while_loop 
	make clean_lab2

exercise1_5: $(LAB2_DIR)/exercise1_5.cpp
	cd $(LAB2_DIR) && g++ -o exercise1_5 exercise1_5.cpp

exercise1_11_for_loop: $(LAB2_DIR)/exercise1_11_for_loop.cpp
	cd $(LAB2_DIR) && g++ -o exercise1_11_for_loop exercise1_11_for_loop.cpp

exercise1_11_while_loop: $(LAB2_DIR)/exercise1_11_while_loop.cpp
	cd $(LAB2_DIR) && g++ -o exercise1_11_while_loop exercise1_11_while_loop.cpp

#### LAB 3 ####
lab3:

#### LAB 4 ####
lab4: $(LAB4_DIR)/exercise3_17 $(LAB4_DIR)/exercise3_23 $(LAB4_DIR)/exercise4_28 $(LAB4_DIR)/inflation $(LAB4_DIR)/nutrition_calculator
	echo "Starting lab 4 exercise 3.17"
	cd $(LAB4_DIR) && ./exercise3_17
	echo "Starting lab 4 exercise 3.23"
	cd $(LAB4_DIR) && ./exercise3_23
	echo "Starting lab 4 exercise 4.28"
	cd $(LAB4_DIR) && ./exercise4_28
	echo "Starting lab 4 inflation"
	cd $(LAB4_DIR) && ./inflation
	echo "Starting lab 4 nutrition calculator"
	cd $(LAB4_DIR) && ./nutrition_calculator
	make clean_lab4

exercise3_17: $(LAB4_DIR)/exercise3_17.cpp
	cd $(LAB4_DIR) && g++ -o exercise3_17 exercise3_17.cpp

exercise3_23: $(LAB4_DIR)/exercise3_23.cpp
	cd $(LAB4_DIR) && g++ -o exercise3_23 exercise3_23.cpp

exercise4_28: $(LAB4_DIR)/exercise4_28.cpp
	cd $(LAB4_DIR) && g++ -o exercise4_28 exercise4_28.cpp

inflation: $(LAB4_DIR)/inflation.cpp
	cd $(LAB4_DIR) && g++ -o inflation inflation.cpp

nutrition_calculator: $(LAB4_DIR)/nutrition_calculator.cpp
	cd $(LAB4_DIR) && g++ -o nutrition_calculator nutrition_calculator.cpp

# removes all files that are not source files with extension .cpp
clean_lab1:
	@cd $(LAB1_DIR) && rm hello_world 

clean_lab2:
	cd $(LAB2_DIR) && rm exercise1_5 exercise1_11_for_loop exercise1_11_while_loop

clean_lab3:

clean_lab4:
	cd $(LAB4_DIR) && rm exercise3_17 exercise3_23 exercise4_28 inflation nutrition_calculator

# phony target removes shell command from output
.SILENT:

all: lab1 lab2 lab3 lab4