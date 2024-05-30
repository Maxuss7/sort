all: sort_tests

sort_tests:
	g++ -DTEST test.cpp stack.cpp -o Test_Sort

clean:
	build/Test_Sort

rebuild: clean all

