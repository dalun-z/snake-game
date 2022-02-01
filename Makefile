CC=g++
CFLAGS=-I. -g
DEPS =
OBJS = gui.o play.o room.o snake.o apple.o

snake: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) -lncurses

play.o: play.cpp position.h snake.h apple.h room.h gui.h
	$(CC) -c play.cpp $(CFLAGS)

room.o: room.cpp position.h gui.h
	$(CC) -c room.cpp $(CFLAGS)

apple.o: apple.cpp apple.h position.h gui.h
	$(CC) -c apple.cpp $(CFLAGS)

snake.o: snake.cpp snake.h position.h gui.h
	$(CC) -c snake.cpp $(CFLAGS)

gui.o: gui.cpp gui.h
	$(CC) -c gui.cpp $(CFLAGS)

clean:
	rm $(OBJS)
