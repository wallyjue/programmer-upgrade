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
	('s', 'in'): 'char*',
	('s', 'out'): 'char**',
	('ay', 'in'): 'void*',
	('sh', 'in'): 'short int',
	('l', 'in'): 'long int'
}

try:
	dom = parse(sys.argv[1])
except IndexError:
	print '<<Error>> Usage: python ipc_client_h_file_generator.py [XML File Name]' 
	exit()
except ExpatError:
	print '<<Error>> ** Incorrect xml format'
	exit()


objectName = ''
for node in dom.getElementsByTagName('node'):
	nodeName = node.attributes.item(0).value
	begin = 0
	end = len(nodeName)
	for index in range(0, len(nodeName)):
		if nodeName[index] == '/' or nodeName[index] == '.':
			begin = index + 1
	objectName = nodeName[begin:end]	



print '#ifndef IPC_' + objectName.upper() + '_CLIENT_H'
print '#define IPC_' + objectName.upper() + '_CLIENT_H'
print
print '#include <stdio.h>'
print '#include <stdlib.h>'
print '#include <string.h>'
print '#include <stdbool.h>'
print
print '#include "ipc_message.h"'
print
print


commands = []
commandIndex = 0
for command in dom.getElementsByTagName('method'):
	functionName = command.attributes.item(0).value
	commandIndex += 1
	commands.append(functionName)

print
print

# IPC Client Init
print 'void ' + objectName + '_Ipc_Client_Init(int listen_port);'

# IPC Client Destroy
print 'void ' + objectName + '_Ipc_Client_Destroy();'
print
print


for command in dom.getElementsByTagName('method'):
	functionName = command.attributes.item(0).value

	args = []
	for arg in command.getElementsByTagName('arg'):
		args.append({arg.attributes.item(0).name: arg.attributes.item(0).value, arg.attributes.item(1).name: arg.attributes.item(1).value, arg.attributes.item(2).name: arg.attributes.item(2).value})
		

	# define the receive function
	paras = ''
	size = len(args)
	
	if size == 0:
		paras = ''
	elif size >= 1:
		paras = variableType.get((args[0].get('type'), args[0].get('direction'))) + ' ' + args[0].get('name')
		if args[0].get('type') == 'ay':
			paras += ', int ' + args[0].get('name') + '_SIZE'
	for index in range(1, size):
		paras += ', ' + variableType.get((args[index].get('type'), args[index].get('direction'))) + ' ' + args[index].get('name')
		if args[index].get('type') == 'ay':
			paras += ', int ' + args[index].get('name') + '_SIZE'

	print 'void ' + functionName + '(' + paras + ');'

print
print
print '#endif'
