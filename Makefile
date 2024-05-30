all: sort_tests

sort_tests:
	g++ -DTEST test.cpp stack.cpp -o build/Test_Sort

clean:
	rm -rf *.o build/Test_1 build/Test_2 build/Test_3 build/Test_4 build/Test_Sort

rebuild: clean all

