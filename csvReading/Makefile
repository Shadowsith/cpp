sales_evaluator: ShopData.o Evaluator.o main.o
		g++ ShopData.o Evaluator.o main.o -std=c++11 -o sales_evaluator

main.o: main.o
	g++ -c main.cpp

Evaluator.o: Evaluator.o
		g++ -c Evaluator.cpp

ShopData.o: ShopData.o
		g++ -c ShopData.cpp
		
clean: 
	rm -f ShopData.o Evaluator.o main.o sales_evaluator
