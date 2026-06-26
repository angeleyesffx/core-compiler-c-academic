TARGET  = compiler
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -Isrc
SRCDIR  = src

SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/lexer.c \
       $(SRCDIR)/buffer.c \
       $(SRCDIR)/symtable.c \
       $(SRCDIR)/parser.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

UNIT_BIN = tests/unit/test_lexer

$(UNIT_BIN): tests/unit/test_lexer.c $(SRCDIR)/lexer.c
	$(CC) $(CFLAGS) -o $@ $^

test: $(TARGET) $(UNIT_BIN)
	@bash tests/run_tests.sh

clean:
	rm -f $(SRCDIR)/*.o $(TARGET) $(UNIT_BIN) output.txt

.PHONY: all test clean
