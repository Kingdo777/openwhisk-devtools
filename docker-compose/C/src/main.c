#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <zconf.h>
#include "cJSON.h"

#define MSG_LENGTH 1000

void handle(char *req,char *res){
    char data[1000];
    cJSON *root = cJSON_Parse(req);
    sprintf(data,"Hello,%s",cJSON_GetObjectItem(cJSON_GetObjectItem(root,"value"),"name")->valuestring);
    cJSON *content=cJSON_Parse("{}");
    cJSON *msg=cJSON_Parse("{}");
    cJSON_AddStringToObject(content,"C",data);
    cJSON_AddItemToObject(msg,"msg",content);
    strcpy(res,cJSON_Print(msg));
    cJSON_Delete(root);
    cJSON_Delete(msg);
}

int main1() {
    char request[MSG_LENGTH];
    char respond[MSG_LENGTH];
    while (true){
        fgets(request,MSG_LENGTH,stdin);
        handle(request,respond);
        for (int i = 0; i < strlen(respond); ++i) {
            if(respond[i]=='\n')
                respond[i]=' ';
        }
        respond[strlen(respond)]='\n';
        respond[strlen(respond)+1]=0;
        printf("%s",respond);
//        write(3, respond,strlen(respond));
        write(3, "{\"bash\": \"Hello, '$name'\"}\n",strlen("{\"bash\": \"Hello, '$name'\"}\n"));
    }
}

int main() {
    char request[MSG_LENGTH];
    char respond[MSG_LENGTH];
    while (true){
        fgets(request,MSG_LENGTH,stdin);
        write(3, "{\"bash\": \"Hello, '$name'\"}\n",strlen("{\"bash\": \"Hello, '$name'\"}\n"));
    }
}

