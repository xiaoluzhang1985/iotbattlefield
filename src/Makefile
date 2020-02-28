tmp=./tmp


main server:server.c main.o lmdd.o lib_sched.o lib_timing.o lat_pipe.o getopt.o lat_select.o lib_tcp.o lat_sem.o lat_rand.o lat_ops.o lat_fcntl.o lat_fifo.o lat_fs.o lat_proc.o lat_sig.o lat_syscall.o lat_tcp.o lat_unix.o lat_connect.o lat_unix_connect.o lib_unix.o lat_usleep.o lib_mem.o lat_mem_rd.o lat_dram_page.o lat_pmake.o lat_ctx.o lat_mmap.o lat_cmd.o
	@gcc -m32 ${tmp}/main.o ${tmp}/lmdd.o ${tmp}/lib_timing.o ${tmp}/lib_sched.o ${tmp}/lat_pipe.o ${tmp}/getopt.o ${tmp}/lat_select.o ${tmp}/lib_tcp.o ${tmp}/lat_sem.o ${tmp}/lat_rand.o ${tmp}/lat_ops.o ${tmp}/lat_fcntl.o ${tmp}/lat_fifo.o ${tmp}/lat_fs.o ${tmp}/lat_proc.o ${tmp}/lat_sig.o ${tmp}/lat_syscall.o ${tmp}/lat_tcp.o ${tmp}/lat_unix.o ${tmp}/lat_connect.o ${tmp}/lat_unix_connect.o ${tmp}/lib_unix.o ${tmp}/lat_usleep.o ${tmp}/lib_mem.o ${tmp}/lat_mem_rd.o ${tmp}/lat_dram_page.o ${tmp}/lat_pmake.o ${tmp}/lat_ctx.o ${tmp}/lat_mmap.o ${tmp}/lat_cmd.o -o ./bin/main
	
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
	
lat_rand.o:lat_rand.c
	@gcc -m32 -c lat_rand.c -o ${tmp}/lat_rand.o
		
lat_ops.o:lat_ops.c
	@gcc -m32 -c lat_ops.c -o ${tmp}/lat_ops.o
			
lat_fcntl.o:lat_fcntl.c
	@gcc -m32 -c lat_fcntl.c -o ${tmp}/lat_fcntl.o
	
lat_fifo.o:lat_fifo.c
	@gcc -m32 -c lat_fifo.c -o ${tmp}/lat_fifo.o
		
lat_fs.o:lat_fs.c
	@gcc -m32 -c lat_fs.c -o ${tmp}/lat_fs.o

lat_proc.o:lat_proc.c
	@gcc -m32 -c lat_proc.c -o ${tmp}/lat_proc.o
	
lat_sig.o:lat_sig.c
	@gcc -m32 -c lat_sig.c -o ${tmp}/lat_sig.o

lat_syscall.o: lat_syscall.c
	@gcc -m32 -c lat_syscall.c -o ${tmp}/lat_syscall.o

lat_tcp.o: lat_tcp.c
	@gcc -m32 -c lat_tcp.c -o ${tmp}/lat_tcp.o

lat_unix.o: lat_unix.c
	@gcc -m32 -c lat_unix.c -o ${tmp}/lat_unix.o

lat_connect.o: lat_connect.c
	@gcc -m32 -c lat_connect.c -o ${tmp}/lat_connect.o

lat_unix_connect.o: lat_unix_connect.c
	@gcc -m32 -c lat_unix_connect.c -o ${tmp}/lat_unix_connect.o

lib_unix.o: lib_unix.c
	@gcc -m32 -c lib_unix.c -o ${tmp}/lib_unix.o

lat_usleep.o: lat_usleep.c
	@gcc -m32 -c lat_usleep.c -o ${tmp}/lat_usleep.o

lib_mem.o: lib_mem.c
	@gcc -m32 -c lib_mem.c -o ${tmp}/lib_mem.o

lat_mem_rd.o: lat_mem_rd.c
	@gcc -m32 -c lat_mem_rd.c -o ${tmp}/lat_mem_rd.o

lat_dram_page.o: lat_dram_page.c
	@gcc -m32 -c lat_dram_page.c -o ${tmp}/lat_dram_page.o

lat_pmake.o: lat_pmake.c
	@gcc -m32 -c lat_pmake.c -o ${tmp}/lat_pmake.o

lat_ctx.o: lat_ctx.c
	@gcc -m32 -c lat_ctx.c -o ${tmp}/lat_ctx.o

lat_mmap.o: lat_mmap.c
	@gcc -m32 -c lat_mmap.c -o ${tmp}/lat_mmap.o

lat_cmd.o: lat_cmd.c
	@gcc -m32 -c lat_cmd.c -o ${tmp}/lat_cmd.o

