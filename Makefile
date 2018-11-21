CC       := g++
CPPFLAGS := -std=c++11 -O3
LDFLAGS  := -std=c++11 -O3
LDLIBS   := -lSDL2
SRC      := $(wildcard *.cpp)
OBJ      := $(SRC:.cpp=.o)

arkanoid: $(OBJ)

.PHONY: format
format:
	clang-format -i *.cpp *.h

.PHONY: run
run:
	./arkanoid

.PHONY: clean
clean:
	$(RM) arkanoid *.o
