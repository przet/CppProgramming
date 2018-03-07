#Courtesy of StackOverflow user Alex44
TARGET = o_u_t_p_u_t.bin
$(TARGET): test_main.cpp test.o source.a
	clang++-5.0 -std=c++17 $^ -lcppunit -o $@

test.o: test.cpp
	clang++-5.0 -std=c++17 -c $<
	

source.a: source.o
	ar rcs source.a $<

source.o: source.cpp header.hpp
	clang++-5.0 -std=c++17 -c $< -o source.a

