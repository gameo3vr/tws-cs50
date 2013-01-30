CC = gcc
CFLAGS = # -Wall

# Program name, "C", as command line argument
run: $(C).c cs50.c cs50.h
	$(CC) $(CFLAGS) -o $(C).exe $(C).c cs50.c

crack: crack.c cs50.c cs50.h
	$(CC) $(CFLAGS) msys-crypt-0.dll -o crack.exe crack.c cs50.c
