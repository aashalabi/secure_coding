CC = gcc
CFLAGS = -lm
TARGETS = sim1 sim3

all: $(TARGETS)

sim1: sim1.c
    $(CC) -o $@ $^ $(CFLAGS)

sim3: sim3.c
    $(CC) -o $@ $^ $(CFLAGS)

clean:
    rm -f $(TARGETS)

