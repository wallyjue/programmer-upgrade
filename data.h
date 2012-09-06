typedef struct _Node Node;
struct _Node
{
	int index;
	int number;
	char* content;
	Node *prevnode;
	Node *nextnode;
};

typedef struct _NodeList NodeList;
struct _NodeList{
	Node* headnode;
	Node* tailnode;
};

//typedef int (*DListAddNode) (NodeList* , Node );
//typedef void (*DListTraverse) (NodeList*);

typedef void (*DListPrintNodeInt) (Node*);
void DListTraverse( NodeList* , DListPrintNodeInt , void*);

#define RET_OK 1
#define RET_FAIL 0