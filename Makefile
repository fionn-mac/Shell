SOURCES.c= main.c cd.c pwd.c echo.c exit.c execute.c loop.c split.c launch.c input.c replace_str.c name.c insert.c delete.c jobs.c killallbg.c sendsig.c fg.c chld_handler.c int_handler.c tstp_handler.c redirection.c rphandle.c rpexecute.c
INCLUDES= 
CFLAGS= -g -Wall -Wextra
SLIBS= 
PROGRAM= main

OBJECTS= $(SOURCES.c:.c=.o)

.KEEP_STATE:

debug := CFLAGS= -g

all debug: $(PROGRAM)

$(PROGRAM): $(INCLUDES) $(OBJECTS)
	$(LINK.c) -o $@ $(OBJECTS) $(SLIBS)

clean:
	rm -f $(PROGRAM) $(OBJECTS)
