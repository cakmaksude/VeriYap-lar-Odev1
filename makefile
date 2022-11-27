hepsi: derle calistir


derle:
	g++ -I ./include/ -o ./lib/Sayi.o -c ./src/Sayi.cpp
	g++ -I ./include/ -o ./lib/SatirlarListesi.o -c ./src/SatirlarListesi.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./bin/Program ./lib/Sayi.o ./lib/SatirlarListesi.o ./lib/YoneticiListesi.o ./src/Program.cpp
	
calistir:
	./bin/Program
	