all : compile

compile:
	g++ -c character.cpp -I"SFML-2.5.1\include"
	g++ -c player.cpp -I"SFML-2.5.1\include"
	g++ -c field.cpp -I"SFML-2.5.1\include"
	g++ -c game.cpp -I"SFML-2.5.1\include"
	g++ -c goal.cpp -I"SFML-2.5.1\include"
	g++ -c referee.cpp -I"SFML-2.5.1\include"
	g++ -c team.cpp -I"SFML-2.5.1\include"
	g++ -c main.cpp -I"SFML-2.5.1\include"
	g++ main.o character.o player.o field.o game.o goal.o referee.o team.o -o main -L"SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f main *.o

cleanw:
	erase -f main *.o
