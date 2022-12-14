LAB1_DIR=./lab1/src
LAB2_DIR=./lab2/src
LAB4_DIR=./lab4/src
LAB5_DIR=./lab5/src
LAB7_DIR=./lab7/src
LAB9_DIR=./lab9/src
LAB10_DIR=./lab10/src

####################### LAB 1 #######################

lab1: $(LAB1_DIR)/hello_world
	$(LAB1_DIR)/hello_world
	make clean_lab1

hello_world: $(LAB1_DIR)/hello_world.cpp
	g++ $(LAB1_DIR)/hello_world.cpp -o hello_world

####################### LAB 2 #######################

lab2: $(LAB2_DIR)/exercise1_5 $(LAB2_DIR)/exercise1_11_for_loop $(LAB2_DIR)/exercise1_11_while_loop
	$(LAB2_DIR)/exercise1_5
	$(LAB2_DIR)/exercise1_11_for_loop
	$(LAB2_DIR)/exercise1_11_while_loop
	make clean_lab2

exercise1_5: $(LAB2_DIR)/exercise1_5.cpp
	g++ $(LAB2_DIR)/exercise1_5.cpp -o $(LAB2_DIR)/exercise1_5

exercise1_11_for_loop: $(LAB2_DIR)/exercise1_11_for_loop.cpp
	g++ $(LAB2_DIR)/exercise1_11_for_loop.cpp -o $(LAB2_DIR)/exercise1_11_for_loop

exercise1_11_while_loop: $(LAB2_DIR)/exercise1_11_while_loop.cpp
	g++ $(LAB2_DIR)/exercise1_11_while_loop.cpp -o $(LAB2_DIR)/exercise1_11_while_loop

####################### LAB 3 #######################

lab3:
	echo "Starting Lab 3 Textbook Exercises"
	cat ./lab3/exercise-answers.md

####################### LAB 4 #######################

lab4: $(LAB4_DIR)/exercise3_17 $(LAB4_DIR)/exercise3_23 $(LAB4_DIR)/exercise4_28 $(LAB4_DIR)/inflation $(LAB4_DIR)/nutrition_calculator
	$(LAB4_DIR)/exercise3_17
	$(LAB4_DIR)/exercise3_23
	$(LAB4_DIR)/exercise4_28
	$(LAB4_DIR)/inflation
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

####################### LAB 5 #######################
lab5: $(LAB5_DIR)/sum_of_digits $(LAB5_DIR)/prime_numbers $(LAB5_DIR)/linear_regression
	echo "Starting Lab 5 Textbook Exercises"
	cat ./lab5/lab5_answers.md
	$(LAB5_DIR)/sum_of_digits
	$(LAB5_DIR)/prime_numbers
	$(LAB5_DIR)/linear_regression
	make clean_lab5

sum_of_digits: $(LAB5_DIR)/sum_of_digits.cpp
	g++ $(LAB5_DIR)/sum_of_digits.cpp -o $(LAB5_DIR)/sum_of_digits

prime_numbers: $(LAB5_DIR)/prime_numbers.cpp
	g++ $(LAB5_DIR)/prime_numbers.cpp -o $(LAB5_DIR)/prime_numbers

linear_regression: $(LAB5_DIR)/linear_regression.cpp
	g++ $(LAB5_DIR)/linear_regression.cpp -o $(LAB5_DIR)/linear_regression
	
####################### LAB 7 #######################
lab7: $(LAB7_DIR)/rectangle $(LAB7_DIR)/sample
	echo "Starting Lab 7"
	cat ./lab7/struct_output.md
	$(LAB7_DIR)/rectangle
	$(LAB7_DIR)/sample
	make clean_lab7
	
rectangle: $(LAB7_DIR)/rectangle.cpp
	g++ $(LAB7_DIR)/rectangle.cpp -o $(LAB7_DIR)/rectangle

sample: $(LAB7_DIR)/sample.cpp
	g++ $(LAB7_DIR)/sample.cpp -o $(LAB7_DIR)/sample

####################### LAB 9 #######################
lab9: $(LAB9_DIR)/weather
	echo "Starting Lab 9"
	$(LAB9_DIR)/weather
	make clean_lab9

weather: $(LAB9_DIR)/weather.cpp
	g++ $(LAB9_DIR)/weather.cpp -o $(LAB9_DIR)/weather

####################### LAB 10 #######################
lab10: $(LAB10_DIR)/film_algorithms
	echo "Starting Lab 10"
	$(LAB10_DIR)/film_algorithms
	make clean_lab10

film_algorithms: $(LAB10_DIR)/film_algorithms.cpp
	g++ $(LAB10_DIR)/film_algorithms.cpp -o $(LAB10_DIR)/film_algorithms

# removes all files that are not source files with extension .cpp
clean_lab1:
	rm $(LAB1_DIR)/hello_world 

clean_lab2:
	rm $(LAB2_DIR)/exercise1_5 $(LAB2_DIR)/exercise1_11_for_loop $(LAB2_DIR)/exercise1_11_while_loop

clean_lab3:

clean_lab4:
	rm $(LAB4_DIR)/exercise3_17 $(LAB4_DIR)/exercise3_23 $(LAB4_DIR)/exercise4_28 \
	$(LAB4_DIR)/inflation $(LAB4_DIR)/nutrition_calculator

clean_lab5:
	rm $(LAB5_DIR)/sum_of_digits $(LAB5_DIR)/prime_numbers $(LAB5_DIR)/linear_regression

clean_lab6:

clean_lab7:
	rm $(LAB7_DIR)/rectangle $(LAB7_DIR)/sample

clean_lab8:

clean_lab9:
	rm $(LAB9_DIR)/weather

clean_lab10:
	rm $(LAB10_DIR)/film_algorithms

# phony target removes shell command from output
.SILENT:

all: lab1 lab2 lab3 lab4 lab5 lab7 lab9 lab10

# target for running the CI/CD workflow in GitHub actions
ci_cd_workflow:
	make lab1
	echo "Input file for exercise 1.5 can be found at $(LAB2_DIR)/input/exercise1_5.txt"
	make exercise1_5 && $(LAB2_DIR)/exercise1_5 < $(LAB2_DIR)/input/exercise1_5.txt
	echo "Input file for exercise 1.11-for can be found at $(LAB2_DIR)/input/exercise1_11_for.txt"
	make exercise1_11_for_loop && $(LAB2_DIR)/exercise1_11_for_loop < $(LAB2_DIR)/input/exercise1_11_for.txt
	echo "Input file for exercise 1.11-while can be found at $(LAB2_DIR)/input/exercise1_11_while.txt"
	make exercise1_11_while_loop && $(LAB2_DIR)/exercise1_11_while_loop < $(LAB2_DIR)/input/exercise1_11_while.txt
	make clean_lab2
	echo "Starting Lab 3 Textbook Exercises"
	cat ./lab3/exercise-answers.md
	echo "Starting Lab 4"
	echo "Input file for exercise 3.17 can be found at $(LAB2_DIR)/input/exercise3_17.txt"
	make exercise3_17 && $(LAB4_DIR)/exercise3_17 < $(LAB4_DIR)/input/exercise3_17.txt
	make exercise3_23 && $(LAB4_DIR)/exercise3_23
	make exercise4_28 && $(LAB4_DIR)/exercise4_28
	echo "Input file for exercise inflation can be found at $(LAB2_DIR)/input/inflation.txt"
	make inflation && $(LAB4_DIR)/inflation < $(LAB4_DIR)/input/inflation.txt
	echo "Input file for exercise nutrition_calculator can be found at $(LAB2_DIR)/input/nutrition_calculator.txt"
	make nutrition_calculator && $(LAB4_DIR)/nutrition_calculator < $(LAB4_DIR)/input/nutrition_calculator.txt
	make clean_lab4
	echo "Starting Lab 5 Textbook Exercises"
	cat ./lab5/lab5_answers.md
	make sum_of_digits && $(LAB5_DIR)/sum_of_digits < $(LAB5_DIR)/input/sum_of_digits_input.txt
	make prime_numbers && $(LAB5_DIR)/prime_numbers
	make linear_regression && $(LAB5_DIR)/linear_regression
	make clean_lab5
	echo "Starting Lab 7"
	make rectangle && $(LAB7_DIR)/rectangle
	make sample && $(LAB7_DIR)/sample
	make clean_lab7
	echo "Starting Lab 9"
	make weather && $(LAB9_DIR)/weather
	make clean_lab9
	echo "Starting Lab 10"
	make film_algorithms && $(LAB10_DIR)/film_algorithms < $(LAB10_DIR)/input/lab10_input.txt
	make clean_lab10

################ GITHUB ACTIONS ################
cicd_lab1:
	make lab1
	
cicd_lab2:
	echo "Starting Lab 2"
	echo "Input file for exercise 1.5 can be found at $(LAB2_DIR)/input/exercise1_5.txt"
	make exercise1_5 && $(LAB2_DIR)/exercise1_5 < $(LAB2_DIR)/input/exercise1_5.txt
	echo "Input file for exercise 1.11-for can be found at $(LAB2_DIR)/input/exercise1_11_for.txt"
	make exercise1_11_for_loop && $(LAB2_DIR)/exercise1_11_for_loop < $(LAB2_DIR)/input/exercise1_11_for.txt
	echo "Input file for exercise 1.11-while can be found at $(LAB2_DIR)/input/exercise1_11_while.txt"
	make exercise1_11_while_loop && $(LAB2_DIR)/exercise1_11_while_loop < $(LAB2_DIR)/input/exercise1_11_while.txt
	make clean_lab2

cicd_lab3:
	make lab3

cicd_lab4:
	echo "Starting Lab 4"
	echo "Input file for exercise 3.17 can be found at $(LAB2_DIR)/input/exercise3_17.txt"
	make exercise3_17 && $(LAB4_DIR)/exercise3_17 < $(LAB4_DIR)/input/exercise3_17.txt
	make exercise3_23 && $(LAB4_DIR)/exercise3_23
	make exercise4_28 && $(LAB4_DIR)/exercise4_28
	echo "Input file for exercise inflation can be found at $(LAB2_DIR)/input/inflation.txt"
	make inflation && $(LAB4_DIR)/inflation < $(LAB4_DIR)/input/inflation.txt
	echo "Input file for exercise nutrition_calculator can be found at $(LAB2_DIR)/input/nutrition_calculator.txt"
	make nutrition_calculator && $(LAB4_DIR)/nutrition_calculator < $(LAB4_DIR)/input/nutrition_calculator.txt
	make clean_lab4

cicd_lab5:
	echo "Starting Lab 5 Textbook Exercises"
	cat ./lab5/lab5_answers.md
	make sum_of_digits && $(LAB5_DIR)/sum_of_digits < $(LAB5_DIR)/input/sum_of_digits_input.txt
	make prime_numbers && $(LAB5_DIR)/prime_numbers
	make linear_regression && $(LAB5_DIR)/linear_regression
	make clean_lab5

cicd_lab7:
	echo "Starting Lab 7"
	make lab7

cicd_lab9:
	echo "Starting Lab 9"
	make lab9

cicd_lab10:
	echo "Starting Lab 10"
	make film_algorithms && $(LAB10_DIR)/film_algorithms < $(LAB10_DIR)/input/lab10_input.txt
	make clean_lab10