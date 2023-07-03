all:
	g++ -std=c++17 AbstractMoving.h -o AbstractionHW
	g++ -std=c++17 AbstractMoving.cpp -o AbstractionHW
	g++ -std=c++17 Test/AbstractionTest.cpp -o AbstractionHWTest

test:
	chmod +x AbstractionHW
	./Test/AbstractionHWTest

clean:
	$(RM) AbstractionHW AbstractionHWTest