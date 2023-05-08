TARGETS = q1 q2 q2-answer

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%: %.o
	$(CC) $(CFLAGS) -o $@

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)

.PHONY: all clean
