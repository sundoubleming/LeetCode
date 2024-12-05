CC = gcc
DEBUG_FLAG = -g
TARGET_PATH = ../so
INC_PATH = ../include
SRC = $@.c
TARGET = lib$@.so

graph :
	gcc -o $(TARGET) $(SRC) $(DEBUG_FLAG) -I$(INC_PATH) -shared -fPIC
	mv $(TARGET) ../so/$(TARGET)

stringCommon : 
	gcc -o $(TARGET) $(SRC) $(DEBUG_FLAG) -I$(INC_PATH) -shared -fPIC
	mv $(TARGET) ../so/$(TARGET)

tree :
	gcc -o $(TARGET) $(SRC) $(DEBUG_FLAG) -I$(INC_PATH) -shared -fPIC
	mv $(TARGET) ../so/$(TARGET)

list :
	gcc -o $(TARGET) $(SRC) $(DEBUG_FLAG) -I$(INC_PATH) -shared -fPIC
	mv $(TARGET) ../so/$(TARGET)

print :
	gcc -o $(TARGET) $(SRC) $(DEBUG_FLAG) -I$(INC_PATH) -shared -fPIC
	mv $(TARGET) ../so/$(TARGET)

all : print list tree stringCommon graph

clean : 
	rm -f ../so/*