#ifndef IPC_TEST_CLIENT_H
#define IPC_TEST_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ipc_message.h"




void test_Ipc_Client_Init(int listen_port);
void test_Ipc_Client_Destroy();


void test_function1(int a, int b);
void test_function2(int a, int* b, unsigned int c, bool d, char* e, void* f, int f_SIZE, short int g, long int h);


#endif
