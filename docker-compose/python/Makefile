#!/bin/bash

OPENWHISK_PROJECT_HOME ?= $(CURDIR)/openwhisk-src
WSK_CLI ?= $(OPENWHISK_PROJECT_HOME)/bin/wsk

create:
	${WSK_CLI} -i action create helloPython hello.py --web true
	${WSK_CLI} -i api create  /hello /python get helloPython --response-type json

url:
	${WSK_CLI} -i api list | grep /hello

curl:
	curl http://10.0.2.15:9090/api/23bc46b1-71f6-4ed5-8c54-816aa4f8c502/hello/python

list:
	${WSK_CLI} -i action list

get:
	 ${WSK_CLI} -i action get helloPython

delete:
	${WSK_CLI} -i api delete /hello
	${WSK_CLI} -i action delete helloPython
