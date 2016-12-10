CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -Wall

OBJS = main.o Game.o Ash.o Space.o StartingSpace.o Pokeball.o Charmander.o Bulbasaur.o Squirtle.o Oak.o

SRCS = main.cpp Game.cpp Ash.cpp Space.cpp StartingSpace.cpp Pokeball.cpp Charmander.cpp Bulbasaur.cpp Squirtle.cpp Oak.cpp

HEADERS = Game.hpp Ash.hpp Space.hpp StartingSpace.hpp Pokeball.hpp Charmander.hpp Bulbasaur.hpp Squirtle.hpp Oak.hpp

final: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o final

clean:
	rm -f final *.o *~