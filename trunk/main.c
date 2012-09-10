#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dlist.h"



int main(int argc, char** argv)
{
	//CU_pSuite pSuite = NULL;
	//if (CUE_SUCCESS != CU_initialize_registry())
		//return CU_get_error();
		
	NodeList* nodelist = (NodeList*) malloc( sizeof( NodeList ));
	
	Node* node1 = InitNode( 1, "chaojue" );
	DListAddNode( nodelist, node1 );
	Node* node2 = InitNode( 2, "chang" );
	DListAddNode( nodelist, node2 );
	Node* node3 = InitNode( 3, "kakasi" );
	DListAddNode( nodelist, node3 );
	
	
	
	DListTraverse( nodelist, print_content, NULL );
	DListTraverse( nodelist, content_to_upper, NULL );
	DListTraverse( nodelist, print_content, NULL );
	
	FreeNode( node1 );
	FreeNode( node2 );
	FreeNode( node3 );
	free( nodelist);
	nodelist = NULL;
	//CU_cleanup_registry();
	return 0;
}
