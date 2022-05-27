WSK?=wsk -i
OW_USER?=openwhisk
OW_RUNTIME?=$(OW_USER)/actionloop-base:nightly
NAME=helloC
PACKAGE=test
BIN_ZIP=bin/hello.zip
BIN=bin/exec
SRC="src/cJSON.c  src/cJSON.h  src/main.c"
CC=gcc

deploy: 
	$(CC) -w  src/cJSON.c  src/cJSON.h  src/main.c -o $(BIN) -lm
	zip -j $(BIN_ZIP) $(BIN)
	$(WSK) action update $(PACKAGE)/$(NAME) $(BIN_ZIP) --docker $(OW_RUNTIME)

devel: deploy

test: test.json
	#$(WSK) action invoke $(PACKAGE)/$(NAME) -r 
	$(WSK) action invoke $(PACKAGE)/$(NAME) -P test.json -r

clean:
	-$(WSK) action delete $(PACKAGE)/$(NAME)
	-rm package.done test.json
	-rm test.out

test.json:
	echo '{ "name": "Mike" }' >test.json

.PHONY: test devel deploy clean
