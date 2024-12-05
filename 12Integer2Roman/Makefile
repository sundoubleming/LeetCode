CC := gcc
BIN := main
SRC := $(wildcard *.c)
OBJ := $(SRC:%c=%o)

COMPILE_FLAG = -I../common/include
CFLAG := -L../common/so -Wl,-rpath=../common/so
LIBS :=

ALL:$(BIN)

clean:
	rm -f $(OBJ) $(BIN)

$(OBJ):%.o:%.c
	$(CC) -c $^ -o $@ -g $(COMPILE_FLAG)

$(BIN):$(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAG) $(LIBS)