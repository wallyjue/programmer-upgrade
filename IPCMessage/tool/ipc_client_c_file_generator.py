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
	('ay', 'in'): 'void *',
	('sh', 'in'): 'short int',
	('l', 'in'): 'long int'
}

try:
	dom = parse(sys.argv[1])
except IndexError:
	print '<<Error>> Usage: python ipc_client_c_file_generator.py [XML File Name]' 
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
print
print

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


# IPC Client 
clientName = 'g_' + objectName + '_client'
print 'IpcSocket *' + clientName + ';'
print
print


# IPC Client Init
print 'void ' + objectName + '_Ipc_Client_Init(int listen_port)'
print '{'
print '\t' + clientName + ' = Ipc_Client_Init(listen_port);'
print '}'
print
print


# IPC Client Destroy
print 'void ' + objectName + '_Ipc_Client_Destroy()'
print '{'
print '\t' + 'Ipc_Client_Destroy(' + clientName + ');'
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


	# define the send function
	paras = ''
	size = len(args)
	
	if size == 0:
		paras = ''
	elif size >= 1:
		if args[0].get('type') == 's' and args[0].get('direction') == 'in':
			paras = variableType.get((args[0].get('type'), args[0].get('direction'))) + '* ' + args[0].get('name')
		else:
			paras = variableType.get((args[0].get('type'), args[0].get('direction'))) + ' ' + args[0].get('name')
		
		if args[0].get('type') == 'ay' and args[0].get('direction') == 'in':
			paras += ', int ' + args[0].get('name') + '_SIZE'
	for index in range(1, size):
		if args[index].get('type') == 's' and args[index].get('direction') == 'in':
			paras += ', ' + variableType.get((args[index].get('type'), args[index].get('direction'))) + '* ' + args[index].get('name')
		else:
			paras += ', ' + variableType.get((args[index].get('type'), args[index].get('direction'))) + ' ' + args[index].get('name')
		
		if args[index].get('type') == 'ay' and args[index].get('direction') == 'in':
			paras += ', int ' + args[index].get('name') + '_SIZE'

	print 'void ' + functionName + '(' + paras + ')'
	print '{'
	
	print '\tstruct ' + functionName + '_PARAMETERS p;'
	print '\tint i;'
	print

	for arg in args:
		if arg.get('type') == 's' and arg.get('direction') == 'in':
			argName = arg.get('name')
			print '\tstrncpy(p.' + argName + ', ' + argName + ', 128);'
			print
		elif arg.get('type') == 'ay' and arg.get('direction') == 'in':
			argName = arg.get('name')
			print '\tmemcpy(p.' + argName + ', ' + argName + ', ' + arg.get('name') +  '_SIZE);'
			print
		else:
			argName = arg.get('name')
			print '\tp.' + argName + ' = ' + argName + ';'
			print

	
	#print '\tQStream_Command_Queue_Insert_Command(' + functionName.upper() + ', (void*)&p, sizeof(struct ' + functionName + '_PARAMETERS));'
	print '\tIpc_Send(' + clientName + ', ' + functionName.upper() + ', (void*)&p, sizeof(struct ' + functionName + '_PARAMETERS));'
	print
	print '}'
	print
	print


