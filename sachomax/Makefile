CXX=g++
CXXFLAGS=-Wall -pedantic -Wno-long-long -O0 -ggdb -std=c++11
LD=g++
LDFLAGS=-lncurses

all: compile doc

sachomax: warrior.o clan.o player.o user.o bot.o map.o save.o game.o main.o
	$(LD)  warrior.o clan.o player.o user.o bot.o map.o save.o game.o main.o -o sachomax $(LDFLAGS)

compile: sachomax

doc: config src/Headers/*.h src/main.cpp 
	doxygen config 

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f sachomax
	rm -f save.txt
	rm -rf doc

run: sachomax 
	./sachomax

warrior.o: src/warrior.cpp src/Headers/warrior.h

main.o: src/main.cpp src/Headers/game.h src/Headers/player.h src/Headers/clan.h src/Headers/warrior.h src/Headers/save.h src/Headers/map.h src/Headers/bot.h src/Headers/user.h

clan.o: src/clan.cpp src/Headers/clan.h src/Headers/warrior.h

user.o: src/user.cpp src/Headers/player.h src/Headers/clan.h src/Headers/warrior.h src/Headers/user.h

map.o: src/map.cpp src/Headers/map.h src/Headers/clan.h src/Headers/warrior.h

player.o: src/player.cpp src/Headers/player.h src/Headers/clan.h src/Headers/warrior.h

save.o: src/save.cpp src/Headers/clan.h src/Headers/map.h src/Headers/warrior.h src/Headers/save.h

bot.o: src/bot.cpp src/Headers/player.h src/Headers/clan.h src/Headers/warrior.h src/Headers/bot.h

game.o: src/game.cpp src/Headers/player.h src/Headers/clan.h src/Headers/warrior.h src/Headers/save.h src/Headers/map.h src/Headers/bot.h src/Headers/user.h src/Headers/game.h