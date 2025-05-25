CC = gcc               # Используем компилятор gcc
CFLAGS = -Wall -Wextra # Флаги компиляции: включить все предупреждения
TARGET = bdz_3         # Имя итогового исполняемого файла

all: $(TARGET)  # Сборка главной цели (TARGET)

$(TARGET): main.o MyList.o # Линковка object-файлов
	$(CC) main.o MyList.o -o $(TARGET)    

main.o: main.c MyList.h  # Компиляция main.c
	$(CC) $(CFLAGS) -c main.c -o main.o 

MyList.o: MyList.c MyList.h # Компиляция MyList.c
	$(CC) $(CFLAGS) -c MyList.c -o MyList.o 

clean: # Удаление всех .o-файлов и бинарника
	rm -f *.o $(TARGET)

# Указание, что это "виртуальные" цели (не файлы)
.PHONY: all clean