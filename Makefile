CC=c++
LEX=reflex/src/reflex
LIBS=reflex/lib/libreflex.so
COFLAGS=-O2
CWFLAGS=-Wall -Wextra
CIFLAGS=-I. -Ireflex/include
CMFLAGS=
CFLAGS=$(CWFLAGS) $(COFLAGS) $(CIFLAGS) $(CMFLAGS)
pretty:         pretty.o
		$(CC) $(CFLAGS) -opretty $(LIBS) $<
.cpp.o:
		$(CC) $(CFLAGS) -c $<
pretty.cpp:     pretty.l
		$(LEX) -+ -opretty.cpp pretty.l
