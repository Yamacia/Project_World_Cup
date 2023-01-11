all: compile

classes:
	g++ -c utility.cpp -I"SFML-2.5.1\include"
	g++ -c character.cpp -I"SFML-2.5.1\include"
	g++ -c player.cpp -I"SFML-2.5.1\include"
	g++ -c field.cpp -I"SFML-2.5.1\include"
	g++ -c game.cpp -I"SFML-2.5.1\include"
	g++ -c goal.cpp -I"SFML-2.5.1\include"
	g++ -c referee.cpp -I"SFML-2.5.1\include"
	g++ -c team.cpp -I"SFML-2.5.1\include"
	g++ -c inputmanager.cpp -I"SFML-2.5.1\include"
	g++ -c main1.cpp -I"SFML-2.5.1\include"
	g++ main1.o utility.o character.o player.o field.o game.o goal.o referee.o team.o -o main1 -L"SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


compile:
	g++ -c utility.cpp -I"SFML-2.5.1\include"
	g++ -c character.cpp -I"SFML-2.5.1\include"
	g++ -c player.cpp -I"SFML-2.5.1\include"
	g++ -c field.cpp -I"SFML-2.5.1\include"
	g++ -c game.cpp -I"SFML-2.5.1\include"
	g++ -c goal.cpp -I"SFML-2.5.1\include"
	g++ -c referee.cpp -I"SFML-2.5.1\include"
	g++ -c team.cpp -I"SFML-2.5.1\include"
	g++ -c inputmanager.cpp -I"SFML-2.5.1\include"
	g++ -c main.cpp -I"SFML-2.5.1\include"
	g++ main.o utility.o character.o player.o field.o game.o goal.o referee.o team.o inputmanager.o -o main -L"SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -f main *.o

cleanw:
	erase -f main.exe *.o

cleanclasses:
	rm -f main1 *.o
