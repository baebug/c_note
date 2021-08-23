CC = gcc
CFLAGS = -W -Wall
TARGET = test_exe
OBJECTS = test.o human.o # .c file 다 적어주기

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# str.o : str.c
# 	$(CC) $(CFLAGS) -c -o str.o str.c

# test.o : test.c
# 	$(CC) $(CFLAGS) -c -o test.o test.c

clean :
	rm *.o test_exe
