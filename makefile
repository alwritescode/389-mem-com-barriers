central: central.c
	gcc -O3 -o central central.c

central: dissem.c
	gcc -O3 -o dissem dissem.c

central: mcs.c
	gcc -O3 -o mcs mcs.c
