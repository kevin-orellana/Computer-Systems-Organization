//Implement a C function called ex4 such that it achieves 
//the same functionality as the machine code of objs/ex4_sol.o
//Note: you need to figure out ex4()'s function signature yourself; 
//the signature is not void ex4()
  
#include <assert.h>
#include <stdio.h>
int 
ex4(int a){
	if (a <= 1){
		return a;
	}
	return ex4(a - 1) + ex4(a - 2);
}

