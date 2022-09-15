LAB2=./lab2/src/

lab2: $(LAB2)exercise1_5 $(LAB2)exercise1_11_for_loop $(LAB2)exercise1_11_while_loop
	echo "Starting exercise 1.5"
	cd $(LAB2) && ./exercise1_5
	echo "Starting exercise 1.11 - for-loop"
	cd $(LAB2) && ./exercise1_11_for_loop
	echo "Starting exercise 1.11 - while-loop"
	cd $(LAB2) && ./exercise1_11_while_loop 

exercise1_5: $(LAB2)exercise1_5.cpp
	cd $(LAB2) && g++ -o exercise1_5 exercise1_5.cpp

exercise1_11_for_loop: $(LAB2)exercise1_11_for_loop.cpp
	cd $(LAB2) && g++ -o exercise1_11_for_loop exercise1_11_for_loop.cpp

exercise1_11_while_loop: $(LAB2)exercise1_11_while_loop.cpp
	cd $(LAB2) && g++ -o exercise1_11_while_loop exercise1_11_while_loop.cpp

clean:
	cd $(LAB2) && rm -rf exercise1_5 exercise1_5.o exercise1_11_for_loop exercise1_11_while_loop exercise1_11_for_loop.o exercise1_11_while_loop.o
