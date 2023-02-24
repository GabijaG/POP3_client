#include <stdlib.h>
#include <string.h>

#include "ssl_connection.h"
#include "pop3_clientLib.h"
#include "loggerLib.h"

int GetServerResponse(SSL *ssl_con)
{
  char *response = READ_SingleLineResponse(ssl_con);
  printf("Server: %s", response);

  if (strstr(response, "+OK") != NULL)
  {
    free(response);
    return 1;
  }
  else if (strstr(response, "-ERR") != NULL)
  {
    free(response);
    return 0;
  }
}

char *READ_SingleLineResponse(SSL *ssl_con)
{

  char *buff = calloc(MAX_BUFF_SIZE, sizeof(char));
  char *charRead = calloc(1, sizeof(char));
  int bytesRead = 0;

  bool foundCR = false, foundLF = false;

  while(SSL_read(ssl_con, charRead, 1) != 0)
  {
    strcat(buff,charRead);
    bytesRead++;

    if(*charRead == '\r')
      foundCR = true;
    if(*charRead == '\n')
      foundLF = true;

    if(foundCR && foundLF)
      break;
  }
  buff[bytesRead] = '\0';
  
  free(charRead);
  
  if(bytesRead <= 0)
  {
    return NULL;
  }
  return buff;
}


int READ_MultiLineResponse(SSL *ssl_con)
{

  if(GetServerResponse(ssl_con) == 0) 
  {
    return 0;
  }

  char  *response = calloc(MAX_MSG_SIZE, sizeof(char));
  char *buff = calloc(MAX_BUFF_SIZE, sizeof(char));

  int bytesRead = 0;

  //Checks for possible .\r\n leftover if first line is only line (in case of LIST command, when there is nothing to list)
  bytesRead = SSL_read(ssl_con, buff, MAX_BUFF_SIZE);
  if(strstr(buff, ".\r\n") > 0)
  {
    buff[bytesRead] = '\0';
    printf("%s", buff);
    free(response);
    free(buff);
    return 1;
  }

  bytesRead = 0;
  while((bytesRead = SSL_read(ssl_con, buff, MAX_BUFF_SIZE)) > 0)
  {
    buff[bytesRead] = '\0';
    if((strlen(response) + bytesRead) > MAX_MSG_SIZE)
    {
      response = realloc(response, (strlen(response) + MAX_MSG_SIZE));
    }

    strcat(response, buff);
    if(strstr(response, TERMINATION_STR) > 0 )
      break;
  }
  if(response != NULL)
  {
    printf("%s", response);
    LogRetrievedMessage(response);
    CheckIfZipAttached(response); 
  }

  if(response != NULL)
  {
      free(response);
  }
  free(buff);

  return 1;
}


int CheckIfZipAttached(char *response)
{
  char *attach = NULL;
  attach = strstr(response, "Content-Type: application/zip");
  
  if(attach != NULL)
  {
    FILE *out_ptr;

    out_ptr = fopen("./encoded.txt", "w");

    if (out_ptr == NULL)
    {
      printf("Error! Unable to open a file.\n");
      exit(5);
    }

    /// Gets rid of first six extra lines.
    for (int i = 0; i <= 5; i++) 
    {
      printf("found at %ld\n", attach - response + 1);
      attach = strchr(attach + 1, '\n');
    }

    attach[strcspn(attach, "-")] = '\0'; 

    printf("\n\nFound attachement: %s", attach);

    fprintf(out_ptr,"%s", attach);
    fclose(out_ptr);

    system("base64 -di ./encoded.txt > ./decoded.zip");
    system("unzip decoded.zip");
    return 1;
  }
  else
  {
    return 0;
  }
}

int Send_USER(SSL *ssl, char *username)
{
  char *msg = ConstructMsg(USER, username);

  if(SSL_write(ssl, msg, strlen(msg)) <= 0)
  {
    ERR_print_errors_fp(stderr);
    return -1;
  }
  free(msg);
  return 1;
}

int Send_QUIT(SSL *ssl)
{
  char *msg = ConstructMsg(QUIT, NO_ARGS);
  
  if(SSL_write(ssl, msg, strlen(msg)) <= 0)
  {
    ERR_print_errors_fp(stderr);
    return -1;
  }
  free(msg);
  return 1;
}

int Send_PASS(SSL *ssl)
{
  char *msg = ConstructMsg(PASS, PASSWORD);
  
  if(SSL_write(ssl, msg, strlen(msg)) <= 0)
  {
    ERR_print_errors_fp(stderr);
    return -1;
  }
  free(msg);
  return 1;
}

int Send_STAT(SSL *ssl)
{
  char *msg = ConstructMsg(STAT, NO_ARGS);

  if(SSL_write(ssl, msg, strlen(msg)) <= 0)
  {
    ERR_print_errors_fp(stderr);
    return -1;
  }
  free(msg);
  return 1;
}

int Send_LIST(SSL *ssl, char *msgNr)
{
  char *msg = ConstructMsg(LIST, msgNr);
  
  if(SSL_write(ssl, msg, strlen(msg)) <= 0)
  {
    ERR_print_errors_fp(stderr);
    return -1;
  }
  free(msg);
  return 1;
}

int Send_RETR(SSL *ssl, char *msgNr)
{
  char *msg = ConstructMsg(RETR, msgNr);
  if (SSL_write(ssl, msg, strlen(msg)) <= 0)
  {
    ERR_print_errors_fp(stderr);
    return -1;
  }
  free(msg);
  return 1;
}

int Send_DELE(SSL *ssl, char *msgNr)
{
  char *msg = ConstructMsg(DELE, msgNr);
  if (SSL_write(ssl, msg, strlen(msg)) <= 0)
  {
    ERR_print_errors_fp(stderr);
    return -1;
  }
  free(msg);
  return 1;
}

int Send_NOOP(SSL *ssl)
{
  char *msg = ConstructMsg(NOOP, NO_ARGS);
  
  if(SSL_write(ssl, msg, strlen(msg)) <= 0)
  {
    ERR_print_errors_fp(stderr);
    return -1;
  }
  free(msg);
  return 1;
}

int Send_RSET(SSL *ssl)
{
  char *msg = ConstructMsg(RSET, NO_ARGS);
  
  if(SSL_write(ssl, msg, strlen(msg)) <= 0)
  {
    ERR_print_errors_fp(stderr);
    return -1;
  }
  free(msg);
  return 1;
}

char *ConstructMsg(const char *command, char* args)
{
  char *msg = calloc(strlen(command) + strlen(args) + strlen(END), sizeof(char));

  strcat(msg, command);
  strcat(msg, args);
  strcat(msg, END);

  return msg;
}