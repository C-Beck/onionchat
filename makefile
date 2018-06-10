onionchat:onionchat.o network.o
	gcc onionchat.o network.o -o onionchat

onionchat.o:onionchat.c
	gcc -c onionchat.c -o onionchat.o

network.o:network.c
	gcc -c network.c -o network.o
clean:
	rm onionchat onionchat.o network.o
