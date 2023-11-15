CODE_SRC	:= ..
SRC			:= $(wildcard ./*.cpp)
TARGET		:= $(patsubst %.cpp, %, $(SRC))

SRC_DEPENDENCY := $(CODE_SRC)/glad/glad.c $(CODE_SRC)/framework/framework.cpp $(CODE_SRC)/shader/shader.cpp
OUTPUT			:= $(shell pwd)/../../bin

CC			:= g++
CXXFLAGS	:= -g

LDFLAGS		:= -lpthread -ldl -lglfw
INCLUDE		:= -I../../include -I../../include/glad -I../../include/framework -I../../include/shader -I../../include/texture -I../../include/glm

all: $(TARGET)

$(TARGET):%:%.cpp
	mkdir -p $(OUTPUT)
	$(CC) $(CXXFLAGS) $< $(SRC_DEPENDENCY) -o $@  $(INCLUDE) $(LDFLAGS)
	mv $@ $(OUTPUT)

.PHONY : all clean
clean :
	rm -rf $(OUTPUT)
