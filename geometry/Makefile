CC = g++
FLAGS = -c -m32 
geometry:*.cpp *.hpp
	$(CC) $(FLAGS) *.cpp
	ar rvs lib$@.a *.o
example: example/main.cpp
	$(CC) -o $@/$@ $^ -lgeometry -L.
clean:
	rm *.o *.a example/example*
.PHONY: clean