all: elems_tests delete_tests length_tests overall_tests sort_tests
elems_tests:
	g++ -DTEST1 test.cpp stack.cpp -o build/Test_1
delete_tests:
	g++ -DTEST2 test.cpp stack.cpp -o build/Test_2
length_tests:
	g++ -DTEST3 test.cpp stack.cpp -o build/Test_3
overall_tests:
	g++ -DTEST4 test.cpp stack.cpp -o build/Test_4
sort_tests:
	g++ -DTEST5 test.cpp stack.cpp -o build/Test_Sort
clean:
	rm -rf *.o build/Test_1 build/Test_2 build/Test_3 build/Test_4 build/Test_Sort

rebuild: clean all

