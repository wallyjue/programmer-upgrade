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
}_NodeList;
