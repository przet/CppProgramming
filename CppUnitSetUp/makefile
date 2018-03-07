#Initial skeleton courtesy of StackOverflow user Alex44
#Additions made following cs.colby.edu, A simple Makefile Tutorial, and others
#-----------------------------------------------------------------

CC=clang++-5.0
CFLAGS=-std=c++17, -Wall
LDFLAGS=-lcppunit
TARGET = output.bin


$(TARGET): test_main.cpp test.o source.a
	$(CC) $^ $(LDFLAGS) -o $@

test.o: test.cpp
	$(CC) -c $<
	

source.a: source.o
	ar rcs source.a $<

source.o: source.cpp header.hpp
	$(CC) -c $< -o source.a

clean:
	rm *.o *.a $(TARGET)
