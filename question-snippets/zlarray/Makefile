TARGETS = vla_a vla_q

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%: %.o
	$(CC) $(CFLAGS) -o $@

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)

.PHONY: all clean
