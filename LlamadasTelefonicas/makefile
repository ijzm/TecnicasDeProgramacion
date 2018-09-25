PROJECT=TEST

main : main.o
		gcc -o test.exe main.o


main.o : main.c
		gcc -c main.c

clean :
		rm main *.o

run : $(PROJECT)
	./$(PROJECT)