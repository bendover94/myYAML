#####################################################################
#   This Makefile builds all executables to run the openCv program	#
#####################################################################

CC= g++
CPPFLAGS= -std=c++17 -g -Wall
LIBRARIES = `pkg-config --cflags --libs yaml-cpp`
G = \033[0;32m
OFF = \033[0m


# Find sources
SRC_GET_DATA := $(shell find . -name 'main.cpp')

# Name executables
EXE := program

# main target
all: $(EXE)
	@echo "\nAll object files created and linked.\nAll executables created.\nRun with $(G)./$(EXE)$(OFF)\n"

# build exexcutables
$(EXE): $(SRC_GET_DATA)
	$(CC) $(CPPFLAGS) -o $(EXE) $< $(LIBRARIES)

clean:
	-rm -rf *.o $(EXE) 
# $(FILE_TOCLEAN)