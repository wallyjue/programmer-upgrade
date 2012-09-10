#include "ipc_port_management.h"
#include "ipc_message.h"
#include <stdlib.h>
#include <stdio.h>


int get_initial_port(int *port)
{
	FILE *ipc_port = fopen("/tmp/ipc_port", "r");
	if (ipc_port == NULL) return -1;
	if (fscanf(ipc_port, "%d\n", port) == EOF) return -1;
	fclose(ipc_port);

	return 0;
}


int Ipc_Get_QStream_Server_Port()
{
	int port;
	int ret = get_initial_port(&port);

	if (ret < 0) port = QSTREAM_SERVER;

	return port;
}


int Ipc_Get_Sip_Server_Port()
{
	int port;
	int ret = get_initial_port(&port);
	port += 2;

	if (ret < 0) port = SIP_SERVER;
	
	return port;
}


int Ipc_Get_Framework_Server_Port()
{
	int port;
	int ret = get_initial_port(&port);
	port += 4;

	if (ret < 0) port = FRAMEWORK_SERVER;

	return port;
}


int Ipc_Get_Dect_Server_Port()
{
	int port;
	int ret = get_initial_port(&port);
	port += 6;
	
	if (ret < 0) port = FRAMEWORK_FOR_DECT_SERVER;

	return port;
}
