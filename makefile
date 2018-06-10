onionchat:onionchat.o
	gcc onionchat.o -o onionchat

onionchat.o:onionchat.c
	gcc -c onionchat.c -o onionchat.o

clean:
	rm onionchat onionchat.o
