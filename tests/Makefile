CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
SRC= $(wildcard ../code/*.cpp)
LIBS= -L"..\code\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
ISFML = -I"..\code\SFML-2.5.1\include"
OBJ= $(SRC:.cpp=.o)
TST= $(wildcard *.cc)
OBJ_TEST = $(filter-out ../code/main.o, $(OBJ)) $(TST:.cc=.o) 

testcase : $(OBJ_TEST) 
	$(CC) $(CCFLAGS) -o $@ $^ $(ISFML) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CCFLAGS) -I../code/ -o $@ -c $< $(ISFML) $(LIBS)

clean :
	rm -f $(OBJ_TEST) testcase
