tmp=./tmp


main server:server.c main.o lmdd.o lib_sched.o lib_timing.o lat_pipe.o getopt.o lat_select.o lib_tcp.o lat_sem.o
	@gcc -m32 ${tmp}/main.o ${tmp}/lmdd.o ${tmp}/lib_timing.o ${tmp}/lib_sched.o ${tmp}/lat_pipe.o ${tmp}/getopt.o ${tmp}/lat_select.o ${tmp}/lib_tcp.o ${tmp}/lat_sem.o -o ./bin/main
	
	@gcc server.c -o ./bin/server
main.o:main.c headers.h
	@gcc -m32 -c main.c -o ${tmp}/main.o 

lmdd.o:lmdd.c
	@gcc -m32 -c lmdd.c -o ${tmp}/lmdd.o

lat_pipe.o:lat_pipe.c
	@gcc -m32 -c lat_pipe.c -o ${tmp}/lat_pipe.o

getopt.o:getopt.c
	@gcc -m32 -c getopt.c -o ${tmp}/getopt.o

lat_select.o: lat_select.c
	@gcc -m32 -c lat_select.c -o ${tmp}/lat_select.o

lib_sched.o:lib_sched.c
	@gcc -m32 -c lib_sched.c -o ${tmp}/lib_sched.o

lib_timing.o:lib_timing.c
	@gcc -m32 -c lib_timing.c -o ${tmp}/lib_timing.o

lib_tcp.o:lib_tcp.c
	@gcc -m32 -c lib_tcp.c -o ${tmp}/lib_tcp.o	

lat_sem.o:lat_sem.c
	@gcc -m32 -c lat_sem.c -o ${tmp}/lat_sem.o
	
