all:
	g++ -std=c++17 UnitTestHW.h -o UnitTestHW
	g++ -std=c++17 UnitTestHW.cpp -o UnitTestHW
	g++ -std=c++17 UnitTestHWTest.cpp -o UnitTestHWTest

test:
	chmod +x UnitTestHW
	./UnitTestHWTest

clean:
	$(RM) UnitTestHW UnitTestHWTest