CC = gcc
CFLAGS = -Wall -O2
OBJS = main.o encrypt.o decrypt.o keygen.o utils.o

otp: $(OBJS)
	$(CC) -o otp $(OBJS)

clean:
	rm -f *.o otp