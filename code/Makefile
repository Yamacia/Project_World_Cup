CC=g++
CCFLAGS= -Wall -Werror 
LIBS= -L"SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC= $(wildcard *.cpp) 
OBJ= $(SRC:.cpp=.o) 
ISFML = -I"SFML-2.5.1\include"
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(ISFML) $(LIBS)


%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $< $(ISFML) $(LIBS)

clean:
	rm -f $(OBJ) $(EXEC) *.*~

cleanw:
	erase -f $(OBJ) $(EXEC) *.*~

