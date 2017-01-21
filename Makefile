#OBJS specifies which files to compile as part of the project
OBJS	=	src/main.cpp\
		src/World.cpp\
		src/Tile.cpp\
		src/Sprite.cpp\
		src/Parser.cpp\
		src/PhysicsEngine.cpp\
		src/CollideBox.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -W -Wall -Wextra -Werror -g -I include/

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lBox2D

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = daGame

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
