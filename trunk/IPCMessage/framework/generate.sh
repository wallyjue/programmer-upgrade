#!/bin/bash
cp ../src/ipc_message.c files
cp ../src/ipc_message.h files
python ../tool/ipc_server_c_file_generator.py framework_api.xml > files/framework_ipc_server_api.c
python ../tool/ipc_server_h_file_generator.py framework_api.xml > files/framework_ipc_server_api.h
python ../tool/ipc_client_c_file_generator.py framework_api.xml > files/framework_ipc_client_api.c
python ../tool/ipc_client_h_file_generator.py framework_api.xml > files/framework_ipc_client_api.h