BIN      := arkanoid
CC       := g++
CPPFLAGS := -std=c++11 -O3
LDFLAGS  := -std=c++11 -O3
LDLIBS   := -lSDL2
SRC      := $(wildcard *.cpp)
HEADERS  := $(wildcard *.h)
OBJ      := $(SRC:.cpp=.o)
DEPS     := $(SRC:.cpp=.d)

$(BIN): $(OBJ)

%.d: %.cpp
	$(CC) $(CPPFLAGS) -MF"$@" -MG -MM -MP -MT"$@" -MT"$(<:.cpp=.o)" "$<"

-include $(DEPS)

.PHONY: format
format:
	clang-format -i $(SRC) $(HEADERS)

.PHONY: run
run:
	./$(BIN)

.PHONY: clean
clean:
	$(RM) $(BIN) $(OBJ) $(DEPS)
