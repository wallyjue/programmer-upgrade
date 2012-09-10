#!/usr/bin/env python

from xml.dom.minidom import parse
from xml.parsers.expat import ExpatError
import sys

variableType = {
	('i', 'in'): 'int',
	('i', 'out'): 'int*',
	('u', 'in'): 'unsigned int',
	('u', 'out'): 'unsigned int*',
	('b', 'in'): 'bool',
	('b', 'out'): 'bool*',
	('s', 'in'): 'char',
	('ay', 'in'): 'void*',
	('sh', 'in'): 'short int',
	('l', 'in'): 'long int'
}

try:
	dom = parse(sys.argv[1])
except IndexError:
	print '<<Error>> Usage: python ipc_server_c_file_generator.py [XML File Name]' 
	exit()
except ExpatError:
	print '<<Error>> ** Incorrect xml format'
	exit()

print '#include <stdio.h>'
print '#include <stdlib.h>'
print '#include <string.h>'
print '#include <stdbool.h>'
print
print '#include "ipc_message.h"'
print '#include <stdbool.h>' 
print
print

prefix = ''
for node in dom.getElementsByTagName('server_prefix'):
	prefix = node.attributes.item(0).value + '_'

objectName = ''
for node in dom.getElementsByTagName('node'):
	nodeName = node.attributes.item(0).value
	begin = 0
	end = len(nodeName)
	for index in range(0, len(nodeName)):
		if nodeName[index] == '/' or nodeName[index] == '.':
			begin = index + 1
	objectName = nodeName[begin:end]	


commands = []
commandIndex = 0
for command in dom.getElementsByTagName('method'):
	functionName = command.attributes.item(0).value
	print '#define ' + functionName.upper() + '\t' + str(commandIndex)
	commandIndex += 1
	commands.append(functionName)

print
print


print 'int ' + objectName + '_COMMAND_HANDLER(int command_type, void* parameters);'
print
print


# IPC Server 
serverName = 'g_' + objectName + '_server'
print 'IpcSocket *' + serverName + ';'
print
print


# IPC Server Init
print 'void ' + objectName + '_Ipc_Server_Init(int listen_port)'
print '{'
print '\t' + serverName + ' = Ipc_Server_Init(listen_port, ' + objectName + '_COMMAND_HANDLER);'
print '}'
print
print


# IPC Server Destroy
print 'void ' + objectName + '_Ipc_Server_Destroy()'
print '{'
print '\t' + 'Ipc_Server_Destroy(' + serverName + ');'
print '}'
print
print


for command in dom.getElementsByTagName('method'):
	functionName = command.attributes.item(0).value

	args = []
	for arg in command.getElementsByTagName('arg'):
		args.append({arg.attributes.item(0).name: arg.attributes.item(0).value, arg.attributes.item(1).name: arg.attributes.item(1).value, arg.attributes.item(2).name: arg.attributes.item(2).value})
		

	# define the structure
	print 'struct ' + functionName + '_PARAMETERS {'
	for arg in args:
		if arg.get('type') == 's' and arg.get('direction') == 'in':
			print '\t' + variableType.get((arg.get('type'), arg.get('direction'))) + ' ' + arg.get('name') + '[128];'
		elif arg.get('type') == 'ay' and arg.get('direction') == 'in':
			print '\tchar ' + arg.get('name') + '[768];'
		else:
			print '\t' + variableType.get((arg.get('type'), arg.get('direction'))) + ' ' + arg.get('name') + ';'
	print '};'
	print
	print


	# define the execute function
	print 'void ' + functionName + '_EXECUTE(struct ' + functionName + '_PARAMETERS *parameters)'
	print '{'

	paras = ''
	size = len(args)

	for arg in args:
		if arg.get('type') == 'i' and arg.get('direction') == 'out':
			print '\tparameters->' + arg.get('name') + ' = (int*)malloc(sizeof(int));' 
			print

	if size == 0:
		paras = ''
	elif size >= 1:
		if args[0].get('name') == 'ay' and args[0].get('direction') == 'in':
			paras = '(void*)parameters->' + args[0].get('name')
		else:
			paras = 'parameters->' + args[0].get('name')
	for index in range(1, size):
		if args[index].get('name') == 'ay' and args[index].get('direction') == 'in':
			paras = '(void*)parameters->' + args[index].get('name')
		else:
			paras += ', parameters->' + args[index].get('name')

	print '\t' + prefix + functionName + '(' + paras + ');'
	print

	for arg in args:
		if arg.get('type') == 'i' and arg.get('direction') == 'out':
			print '\tfree(parameters->' + arg.get('name') + ');'

	print '}'
	print
	print


print 'int ' + objectName + '_COMMAND_HANDLER(int command_type, void* parameters)'
print '{'

print '\tswitch (command_type) {'
for command in commands:
	print '\t\tcase ' + command.upper() + ':'
	print '\t\t\t' + command + '_EXECUTE((struct ' + command + '_PARAMETERS *)parameters);';
	print '\t\t\tbreak;'
print '\t\tdefault:'
print '\t\t\treturn -1;'
print '\t\t\tbreak;'
print '\t}'
print
print '\treturn 0;'
print '}'



