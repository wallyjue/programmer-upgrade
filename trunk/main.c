#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dlist.h"
#include "darray.h"

int main(int argc, char** argv)
{
	DArray* darray = (DArray*) malloc( sizeof( DArray ));
	
	
	darray_destory( darray );
	return 0;
}
