
CXX     = g++
#CFLAGS  = -march=native -O3 -s
CFLAGS  = -g -O0
CFLAGS += -Wall -W -pedantic -Wextra -Wunused -Wformat=2 -fexceptions -Weffc++ -Wpadded
LDLIBS  = -lsfml-graphics -lsfml-window
LIB     = ConvertUTF.o
OBJ     = config.o logger.o core.o
NAME    = powwer-terry

all: clean $(NAME)

clean:
	@echo " . Cleaning ... "
	rm -f *.o $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CXX) $(CFLAGS) $(LDLIBS) $^ src/tectum.cc -o $@

$(LIB):
	$(CXX) $(CFLAGS) -c src/lib/$*.c

$(OBJ):
	$(CXX) $(CFLAGS) -c src/components/$*.cc

check:
	valgrind --leak-check=full --show-reachable=yes ./$(NAME)

love:
	@echo "I'm free, you could find my email ID into source files ;)"

sandwich.: sandwich

me a sandwich:
	@if [ "$@" = "sandwich" ]; then echo $(shell if [ $(shell id -ru) = 0 ]; then echo "Okay."; else echo "What? Make it yourself."; fi); fi
