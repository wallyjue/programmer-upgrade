#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"


#define TEST_FUNCTION1	0
#define TEST_FUNCTION2	1


IpcSocket *g_test_client;


void test_Ipc_Client_Init(int listen_port)
{
	g_test_client = Ipc_Client_Init(listen_port);
}


void test_Ipc_Client_Destroy()
{
	Ipc_Client_Destroy(g_test_client);
}


struct test_function1_PARAMETERS {
	int a;
	int b;
};


void test_function1(int a, int b)
{
	struct test_function1_PARAMETERS p;
	int i;

	p.a = a;

	p.b = b;

	Ipc_Send(g_test_client, TEST_FUNCTION1, (void*)&p, sizeof(struct test_function1_PARAMETERS));

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


void test_function2(int a, int* b, unsigned int c, bool d, char* e, void * f, int f_SIZE, short int g, long int h)
{
	struct test_function2_PARAMETERS p;
	int i;

	p.a = a;

	p.b = b;

	p.c = c;

	p.d = d;

	strncpy(p.e, e, 128);

	memcpy(p.f, f, f_SIZE);

	p.g = g;

	p.h = h;

	Ipc_Send(g_test_client, TEST_FUNCTION2, (void*)&p, sizeof(struct test_function2_PARAMETERS));

}


