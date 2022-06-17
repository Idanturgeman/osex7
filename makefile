.PHONY: all clean
CXX=gcc

all: test_mylibc test_fs 
	./test_fs
	./test_mylibc
test_mylibc: test_mylibc.o mylibc.o fs.o
	$(CXX) -g -o test_mylibc test_mylibc.o mylibc.o fs.o
test_mylibc.o: test_mylibc.c mylibc.h
	$(CXX) -g -c test_mylibc.c
mylibc.o: mylibc.c mylibc.h
	$(CXX) -g -c mylibc.c
test_fs: test_fs.o fs.o 
	$(CXX) -g -o test_fs test_fs.o fs.o
test_fs.o: test_fs.c fs.h
	$(CXX) -g -c test_fs.c
fs.o: fs.c fs.h
	$(CXX) -g -c fs.c
clean:
	rm -f *.o test_fs fs test_mylibc