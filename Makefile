CC=gcc
CFLAGS= -std=c99 -ggdb
readprint: readprint.c
readsscanf: readsscanf.c
readstrtok: readstrtok.c
safeprint: safeprint.c
readppm: readppm.c
clean:
	rm readprint readsscanf readstrtok safeprint readppm
