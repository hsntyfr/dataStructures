all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/AVL.cpp -o ./lib/AVL.o
	g++ -c -I "./include" ./src/DugumYigin.cpp -o ./lib/DugumYigin.o
	g++ -c -I "./include" ./src/DugumAVL.cpp -o ./lib/DugumAVL.o	
	g++ -c -I "./include" ./src/Yigin.cpp -o ./lib/Yigin.o
	g++ -c -I "./include" ./src/DinamikDizi.cpp -o ./lib/DinamikDizi.o

bagla:
	g++ ./lib/DugumAVL.o ./lib/DinamikDizi.o ./lib/DugumYigin.o ./lib/Yigin.o ./lib/AVL.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program