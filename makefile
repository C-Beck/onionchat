all: onionchat onionconfig

onionchat:onionchat.o network.o
	gcc onionchat.o network.o -o onionchat

onionchat.o:onionchat.c
	gcc -c onionchat.c -o onionchat.o

network.o:network.c
	gcc -c network.c -o network.o

onionconfig:onionconfig.o password.o
	gcc onionconfig.o password.o -o onionconfig -lcrypto

onionconfig.o:onionconfig.c
	gcc -c onionconfig.c -o onionconfig.o

password.o:password.c
	gcc -c password.c -o password.o

clean:cleane cleano

cleane:
	rm onionchat
	rm onionconfig
cleano:
	rm network.o
	rm onionchat.o
	rm onionconfig.o
	rm password.o
