#
#	Makefile -- Build instructions for user level apps
#
all: ipc_message ipc_test_server ipc_test_client test_ipc_port_management

ipc_test_client:
	gcc -c -g test_ipc_client.c 
	gcc -o test_client ipc_message.o test_ipc_client.o -lpthread
	
ipc_test_server:
	gcc -c -g test_ipc_server.c 
	gcc -o test_server ipc_message.o test_ipc_server.o -lpthread

ipc_message:
	gcc -c -g ipc_message.c -lpthread
	
test_ipc_port_management: test_ipc_port_management.c ipc_port_management.c
	gcc -g -o test_ipc_port_management test_ipc_port_management.c ipc_port_management.c

clean:
	rm -rf *.o
	rm test_client
	rm test_server

