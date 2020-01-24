tmp=./tmp


main server:server.c main.o lmdd.o lib_sched.o lib_timing.o lat_pipe.o getopt.o
	@gcc -m32 ${tmp}/main.o ${tmp}/lmdd.o ${tmp}/lib_timing.o ${tmp}/lib_sched.o ${tmp}/lat_pipe.o ${tmp}/getopt.o  -o ./bin/main
	
	@gcc server.c -o ./bin/server
main.o:main.c lat_pipe.h lmdd.h
	@gcc -m32 -c main.c -o ${tmp}/main.o 

lmdd.o:lmdd.c
	@gcc -m32 -c lmdd.c -o ${tmp}/lmdd.o

lat_pipe.o:lat_pipe.c
	@gcc -m32 -c lat_pipe.c -o ${tmp}/lat_pipe.o

getopt.o:getopt.c
	@gcc -m32 -c getopt.c -o ${tmp}/getopt.o

lib_sched.o:lib_sched.c
	@gcc -m32 -c lib_sched.c -o ${tmp}/lib_sched.o

lib_timing.o:lib_timing.c
	@gcc -m32 -c lib_timing.c -o ${tmp}/lib_timing.o

