hex: driver.o
	g++ -o hex driver.o
driver.o: driver.cpp
	g++ -c driver.cpp
clean:
	rm *.o hex