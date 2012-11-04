
CXX     = g++
#CFLAGS  = -march=native -O3 -s
CFLAGS  = -g -O0 -std=c++0x
#CFLAGS += -Wall -W -pedantic -Wextra -Wunused -Wformat=2 -Weffc++ -Wpadded -fexceptions
LDLIBS  =  -lsfml-graphics -lsfml-window
OBJ     = core.o
NAME    = powwer-terry

all: title clean $(NAME)

clean:
	@echo " . Cleaning ... "
	rm -f *.o $(NAME)

title:
	@echo " ~ Powwer Terry!"

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(LDLIBS) $^ tectum.cc -o $@

$(OBJ):
	@echo " + Building $* module ..."
	$(CXX) $(CFLAGS) -c $*/$*.cc

check:
	valgrind --leak-check=full --show-reachable=yes ./$(NAME)

love:
	@echo "I'm free, you could find my email ID into source files ;)"

sandwich.: sandwich

me a sandwich:
	@if [ "$@" = "sandwich" ]; then echo $(shell if [ $(shell id -ru) = 0 ]; then echo "Okay."; else echo "What? Make it yourself."; fi); fi
