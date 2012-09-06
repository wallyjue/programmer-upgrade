#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

Node* InitNode(int index)
{
	Node* node = (Node*) malloc( sizeof( Node));
	node->index = index;
	return node;
}

void FreeNode( Node* node)
{
	if( node == NULL)
	{
		return ;
	}
	
	if( node->content != NULL)
	{
		free( node->content );
		node->content = NULL;
	}
	free( node );
	node = NULL;
}

void print_index( Node* node)
{
	printf("index:%d\n", node->index);
}

void SumIndex(Node* node, void* ctx)
{
	long long* ret = ctx;
	*ret += node->index;
}

void FindMax( Node* node, void* ctx)
{
	long long* ret = ctx;
	if( node->index > *ret)
	{
		*ret = node->index;
	}
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

void DListTraverse(NodeList* nodelist, DListVisitNode visit_func, void* ctx)
{
	Node* cur_node = nodelist->headnode;
	while( cur_node != NULL)
	{
		visit_func( cur_node, ctx );
		cur_node = cur_node->nextnode;
	}
}



int main(int argc, char** argv)
{
	NodeList* nodelist = (NodeList*) malloc( sizeof( NodeList ));
	
	Node* node1 = InitNode( 1 );
	DListAddNode( nodelist, node1 );
	Node* node2 = InitNode( 2 );
	DListAddNode( nodelist, node2 );
	Node* node3 = InitNode( 3 );
	DListAddNode( nodelist, node3 );
	
	
	long long result = 0;
	DListTraverse( nodelist, FindMax, &result );
	printf("result:%lld\n", result);
	
	FreeNode( node1 );
	FreeNode( node2 );
	FreeNode( node3 );
	free( nodelist);
	nodelist = NULL;
	return 0;
}
