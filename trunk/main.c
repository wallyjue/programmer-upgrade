#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data.h"

Node* InitNode(int index, char* content)
{
	Node* node = (Node*) malloc( sizeof( Node));
	node->index = index;
	node->content = (char*) malloc( sizeof(char) * strlen(content));
	node->content_len = strlen(content);
	strncpy( node->content, content, strlen(content));
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

void print_index( Node* node, void* ctx)
{
	printf("index:%d\n", node->index);
}

void print_content( Node* node, void* ctx)
{
	printf("content:%s\n", node->content);
}

void content_to_upper(Node* node, void* ctx)
{
	int cnt = 0;
	for( cnt = 0; cnt < strlen(node->content); cnt++)
	{
		if( islower( node->content[cnt] ))
			node->content[cnt] -= 32;
	}
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
	return 0;
}
