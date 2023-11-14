CODE_SRC	:= ../
SRC	:= $(wildcard ./*.cpp $(CODE_SRC)glad/*.c $(CODE_SRC)framework/*.cpp $(CODE_SRC)shader/*.cpp)
OBJS	:= $(patsubst %.c %.cpp,%.o, $(SRC))

NAME	:= sample05-transformation
OUTPUT	:= $(shell pwd)/../../bin

CC	:= g++
CXXFLAGS	:= -g

LDFLAGS	:= -lpthread -ldl -lglfw
INCLUDE	:= -I../../include -I../../include/glad -I../../include/framework -I../../include/shader -I../../include/texture -I../../include/glm

.PHONY : everything objs clean veryclean rebuild
all : $(NAME)

clean :
	rm -rf $(OUTPUT)

$(NAME) : $(OBJS)
	mkdir -p $(OUTPUT)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(INCLUDE) $(LDFLAGS)
	mv $(NAME) $(OUTPUT)
