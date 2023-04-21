hexCalc: driver.o
	g++ -o hexCalc driver.o
driver.o: driver.cpp
	g++ -c driver.cpp
clean:
	rm *.o hexCalc