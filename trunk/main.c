#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
/*
void DListFindNode();
void DListAddNode(NodeList nodelist, Node node);
void DListDelNode();

void DListTraverse(NodeList nodelist);
*/

static void print_index( Node* node)
{
	printf("index:%d\n", node->index);
}

static int DListAddNode( NodeList* nodelist, Node* node)
{
	if( nodelist == NULL)
	{
		return RET_FAIL;
	}
	
	if( nodelist->headnode == NULL )
	{
		nodelist->headnode = node;
	}
	else
	{
		nodelist->tailnode->nextnode = node;
		node->prevnode = nodelist->tailnode;
	}
	
	nodelist->tailnode = node;
	return RET_OK;
}

void DListTraverse(NodeList* nodelist, DListPrintNodeInt print_node_index, void* ctx)
{
	Node* cur_node = nodelist->headnode;
	while( cur_node != NULL)
	{
		print_node_index( cur_node );
		cur_node = cur_node->nextnode;
	}
}

Node* InitNode(int index)
{
	Node* node = (Node*) malloc( sizeof( Node));
	node->index = index;
	return node;
}

void FreeNode( Node* node)
{
	if( node->content != NULL)
	{
		free( node->content );
		node->content = NULL;
	}
	free( node );
	node = NULL;
}

int main(int argc, char** argv)
{
	NodeList* nodelist = (NodeList*) malloc( sizeof( NodeList ));
	
	Node* node = InitNode( 1 );
	DListAddNode( nodelist, node );
	
	DListTraverse( nodelist, print_index, NULL );
	
	FreeNode( node );
	
	free( nodelist);
	nodelist = NULL;
	return 0;
}
