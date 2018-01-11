//Implement a C function called ex2 such that it achieves 
//the same functionality as the machine code of objs/ex2_sol.o
//Note: you need to figure out ex2()'s function signature yourself; 
//the signature is not void ex2()
  
#include <assert.h>

int
ex2(char *a){
	int count = 0;
	int index = 0;
	do {
		if (a[index] == 'a'){
			count++;
		}
		index++;
	}
	while (a[index] != '\0');
	return count;	
}
