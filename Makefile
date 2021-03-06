#declare variable
CC = g++
INCLUDE_FILES = ./include ../Linked_List/include
INCLUDE_FLAGS = $(foreach d, $(INCLUDE_FILES), -I $d)
CTAGS_UTIL = /usr/local/bin/
CTAGS_FILES = ./include ../Linked_List ../Linked_List/include
CTAGS_FLAGS = $(foreach d, $(CTAGS_FILES),-a $d/*)
CFLAGS = -g -Wall -O3 -std=c++11 
COMPILE_FLAGS = -c
MAIN_OBJECT_NAME_MAIN = AdjList_main
MAIN_OBJECT_SOURCE_MAIN = $(MAIN_OBJECT_NAME_MAIN).cpp
MAIN_OBJECT_EXEC_MAIN = $(MAIN_OBJECT_NAME_MAIN).o
MAIN_OBJECT_NAME = AdjList
MAIN_OBJECT_SOURCE = $(MAIN_OBJECT_NAME).cpp
MAIN_OBJECT_EXEC = $(MAIN_OBJECT_NAME).o
MAIN_OBJECT_EXEC_OUTPUT = ./exec_output/
SUB_LINKED_LIST_SOURCE_PATH = ../Linked_List/

all : clean AdjList all_file_tags
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(MAIN_OBJECT_EXEC_OUTPUT)Linked_List.o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC) $(MAIN_OBJECT_SOURCE_MAIN) -o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC_MAIN)
	${MAIN_OBJECT_EXEC_OUTPUT}$(MAIN_OBJECT_EXEC_MAIN)

AdjList : $(MAIN_OBJECT_SOURCE) Linked_List
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) $(MAIN_OBJECT_SOURCE) $(INCLUDE_FLAGS) -o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC)

Linked_List : $(SUB_LINKED_LIST_SOURCE_PATH)Linked_List.cpp | $(MAIN_OBJECT_EXEC_OUTPUT)
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) $(SUB_LINKED_LIST_SOURCE_PATH)Linked_List.cpp $(INCLUDE_FLAGS) -o $(MAIN_OBJECT_EXEC_OUTPUT)Linked_List.o

all_file_tags : 
	$(CTAGS_UTIL)ctags -R ./*
	$(CTAGS_UTIL)ctags $(CTAGS_FLAGS)

$(MAIN_OBJECT_EXEC_OUTPUT): 
	@mkdir $(MAIN_OBJECT_EXEC_OUTPUT)

clean :
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)Linked_List.o
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC)
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC_MAIN)
	rm -rf ./tags
