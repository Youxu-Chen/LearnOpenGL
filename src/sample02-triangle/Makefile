CODE_SRC	:= ../
SRC	:= $(wildcard ./*.cpp $(CODE_SRC)glad/*.c $(CODE_SRC)framework/*.cpp)
OBJS	:= $(patsubst %.c %.cpp,%.o, $(SRC))

NAME	:= sample02-triangle
OUTPUT	:= $(shell pwd)/../../bin

CC	:= g++
CXXFLAGS	:= -g

LDFLAGS	:= -lpthread -ldl -lglfw
INCLUDE	:= -I../../include -I../../include/glad -I../../include/framework

.PHONY : everything objs clean veryclean rebuild
all : $(NAME)

clean :
	rm -rf $(OUTPUT)

$(NAME) : $(OBJS)
	mkdir -p $(OUTPUT)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(INCLUDE) $(LDFLAGS)
	mv $(NAME) $(OUTPUT)
