#ifndef POP3_CLIENTLIB_H
#define POP3_CLIENTLIB_H

#include <stdbool.h>
#include "ssl_connection.h"

#define MAX_BUFF_SIZE 180
#define MAX_MSG_SIZE 512

#define NO_ARGS ""
#define USER "USER "
#define QUIT "QUIT "
#define PASS "PASS "
#define STAT "STAT "
#define LIST "LIST "
#define RETR "RETR "
#define DELE "DELE "
#define NOOP "NOOP "
#define RSET "RSET "
#define END "\r\n"
#define TERMINATION_STR "\r\n.\r\n"


int GetServerResponse(SSL *ssl_con);

char *READ_SingleLineResponse(SSL *ssl_con);
int READ_MultiLineResponse(SSL *ssl_con);

int Send_USER(SSL *ssl, char *username);
int Send_PASS(SSL *ssl);
int Send_QUIT(SSL *ssl);
int Send_STAT(SSL *ssl);
int Send_LIST(SSL *ssl, char *msgNr);
int Send_RETR(SSL *ssl, char *msgNr);
int Send_DELE(SSL *ssl, char *msgNr);
int Send_NOOP(SSL *ssl);
int Send_RSET(SSL *ssl);

char *ConstructMsg(const char *command, char* args);
int CheckIfZipAttached(char *response);


#endif //POP3_CLIENTLIB_H