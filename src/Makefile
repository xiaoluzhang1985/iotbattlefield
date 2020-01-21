tmp=./tmp


#lmdd:lmdd.o lib_sched.o lib_timing.o
#	gcc -m32 -static ${tmp}/lmdd.o ${tmp}/lib_sched.o ${tmp}/lib_timing.o -o ./bin/lmdd
main server:server.c main.o lmdd.o lib_sched.o lib_timing.o
	@gcc -m32 ${tmp}/main.o ${tmp}/lmdd.o ${tmp}/lib_timing.o ${tmp}/lib_sched.o -o ./bin/main
	@gcc server.c -o ./bin/server
main.o:main.c
	@gcc -m32 -c main.c -o ${tmp}/main.o 
lmdd.o:lmdd.c
	@gcc -m32 -c lmdd.c -o ${tmp}/lmdd.o
lib_sched.o:lib_sched.c
	@gcc -m32 -c lib_sched.c -o ${tmp}/lib_sched.o
lib_timing.o:lib_timing.c
	@gcc -m32 -c lib_timing.c -o ${tmp}/lib_timing.o

