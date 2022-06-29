CC = g++
CCFLAGS = -g -std=c++11
TYPE = -lncurses

run: Stage.o About_game.o About_snake.o Main.o
	$(CC) $(CCFLAGS) -o run Stage.o About_game.o About_snake.o Main.o $(TYPE)

clean:
	rm -f *.o run

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<
