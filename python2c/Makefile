
default: clib.c
	gcc -c -fPIC clib.c -o clib.o
	gcc -shared -Wl,-soname,libclib.so -o libclib.so clib.o
