#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"
#include <stdbool.h>


#define TEST_FUNCTION1	0
#define TEST_FUNCTION2	1


int test_COMMAND_HANDLER(int command_type, void* parameters);


IpcSocket *g_test_server;


void test_Ipc_Server_Init(int listen_port)
{
	g_test_server = Ipc_Server_Init(listen_port, test_COMMAND_HANDLER);
}


void test_Ipc_Server_Destroy()
{
	Ipc_Server_Destroy(g_test_server);
}


struct test_function1_PARAMETERS {
	int a;
	int b;
};


void test_function1_EXECUTE(struct test_function1_PARAMETERS *parameters)
{
	test_function1(parameters->a, parameters->b);

}


struct test_function2_PARAMETERS {
	int a;
	int* b;
	unsigned int c;
	bool d;
	char e[128];
	char f[768];
	short int g;
	long int h;
};


void test_function2_EXECUTE(struct test_function2_PARAMETERS *parameters)
{
	parameters->b = (int*)malloc(sizeof(int));

	test_function2(parameters->a, parameters->b, parameters->c, parameters->d, parameters->e, parameters->f, parameters->g, parameters->h);

	free(parameters->b);
}


int test_COMMAND_HANDLER(int command_type, void* parameters)
{
	switch (command_type) {
		case TEST_FUNCTION1:
			test_function1_EXECUTE((struct test_function1_PARAMETERS *)parameters);
			break;
		case TEST_FUNCTION2:
			test_function2_EXECUTE((struct test_function2_PARAMETERS *)parameters);
			break;
		default:
			return -1;
			break;
	}

	return 0;
}
