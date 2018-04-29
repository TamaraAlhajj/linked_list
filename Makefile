
run: main_test.o linked_list.o
	gcc -g main_test.o linked_list.o 

main_test.o: main_test.c 
	gcc -g -c main_test.c


linked_list.o: linked_list.c linked_list.h 
	gcc -g -c linked_list.c

clean:
	rm -f *.o

