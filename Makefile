all: Test_Sort Test_Add Test_Del Test_Length Test_Get_Set
Test_Sort:
	g++ -DTEST1 test.cpp stack.cpp -o Test_Sort
Test_Add:
	g++ -DTEST2 test.cpp stack.cpp -o Test_Add
Test_Del:
	g++ -DTEST3 test.cpp stack.cpp -o Test_Del
Test_Length:
	g++ -DTEST4 test.cpp stack.cpp -o Test_Length
Test_Get_Set:
	g++ -DTEST5 test.cpp stack.cpp -o Test_Get_Set
clean:
	rm -rf Test_Sort Test_Add Test_Del Test_Length Test_Get_Set

rebuild: clean all

