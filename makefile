LAB2=./lab2/src/

$(LAB2): $(LAB2)exercise1_5 $(LAB2)exercise1_11
	cd ./lab2/src
	echo "starting exercise 1.5"
	./exercise1_5
	echo "starting exercise 1.11"
	./exercise1_11

exercise1_5: $(LAB2)exercise1_5.cpp
	cd $(LAB2)
	g++ -o exercise1_5 exercise1_5.cpp

exercise1_11: $(LAB2)exercise1_11.cpp
	cd $(LAB2)
	g++ -o exercise1_11 exercise1_11.cpp

clean:
	cd $(LAB2)
	rm -rf exercise1_5 
	rm -rf exercise1_11 
