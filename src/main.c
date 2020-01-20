#include<stdio.h>
#include<string.h>
#include"lmdd.h"

#define	DEBUG


int recgarg(char* arg);

char lmddarg[4]={"lmdd"};


void main(int argc, char* argv[]){
	int args;
	int ar;
	for(args=1; args < argc ;args++){
		switch(recgarg(argv[args])){
			case 1:	//lmdd
				ar=4;
				char*av[]={"lmdd","if=internal","of=./test","count=1000"};
				lmdd(ar,av);		
			case 2:

			default:
			return;
		}	

	}	
	
}

int recgarg(char* arg){
	if (!strcmp(lmddarg,arg)){
		#ifdef DEBUG
		printf("%s\n",arg);
		#endif
		return 1;
	}
	//if(!strcmp(cmd,arg)){
	//	
	//}

}
