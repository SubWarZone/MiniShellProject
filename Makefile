CC=gcc
CFLAGS=
LDFLAGS=
EXEC=exe
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

exe: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
