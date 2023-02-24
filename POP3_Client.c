#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "ssl_connection.h"
#include "user_UI.h"
#include "pop3_clientLib.h"

#include "loggerLib.h"

#define FILE_NAME_LENGTH 25 

int main(int argc, char *argv[])
{
    int connection_fd;
    if(argc != 2)
    {
        printf("Please provide POP3 server IP address.\n");
        exit(1);
    }

    connection_fd =  OpenConnection(argv[1]);
    SSL_CTX *ctx;
    SSL *ssl_con;

    if(InitializeSSL(connection_fd, &ctx, &ssl_con) == -1)
    {
      ERR_print_errors_fp(stderr); 
      CloseConnection(connection_fd, &ctx, &ssl_con);
      exit(4);
    }
    printf("\nConnection initialized.\n");

    char *buff = NULL;

    GetServerResponse(ssl_con);


    DisplayCommands();
    char cmd, session = 1, responseTaken = 0;


    time_t timeNow = time(0);
    char  argToLog[1] = " ";

    char *fileName = calloc(FILE_NAME_LENGTH, sizeof(char));
    fileName = ctime(&timeNow);
    fileName[strlen(fileName)-1] = '\0';

    strcat(fileName, " CommandsLog.txt");
    FILE *outputLog = fopen(fileName, "w");
    ///TODO: could do a structure and init it in library instead of this clutter in main.

    /// connectionState:
    /// 0 - AUTH, 1 - TRANS, 2 - UPDATE
    int connectionState = 0;

    do
    {
      cmd = GetUsersChoice(connectionState);
      argToLog[0] = '0';


      switch(cmd)
      {
        case 'H':
        {
          DisplayCommands();
          responseTaken = 1;
          break;
        }
        case 'U':
        {
          Send_USER(ssl_con, USERNAME); 
          break;
        }
        case 'P':
        {
          Send_PASS(ssl_con);
          int resp = 0;
          if(resp = GetServerResponse(ssl_con)  != 0)
          {
            connectionState = 1; //Succsessfully went to TRANS state
          }
          else
          {
            connectionState = 2; //Error occured. Server ends communication here
          }
          responseTaken = 1;
          break;
        }
        case 'Q':
        {
          Send_QUIT(ssl_con);
          connectionState = 2;
          break;
        }
        case 'S':
        {
          Send_STAT(ssl_con); 
          break;
        }
        case 'L':
        {
          char  *arg = calloc(1, sizeof(char));
          *arg = GetMessageNrFromUser();
          argToLog[0] = *arg;
          
          if(*arg == '\n')
          {
            Send_LIST(ssl_con, NO_ARGS);
            READ_MultiLineResponse(ssl_con);
            responseTaken = 1; //Trying to read more than there is messes up the SSL_Connection and further interations with the server.
          }
          else
          {
            Send_LIST(ssl_con, arg);
          }
          free(arg);
          break;
        }
        case 'R':
        {
          char  *arg = calloc(1, sizeof(char));
          *arg = GetMessageNrFromUser();
          argToLog[0] = *arg;
          
          if(*arg != '\n')
          {
            Send_RETR(ssl_con, arg);
            READ_MultiLineResponse(ssl_con);
          }
          else
          {
            printf("ERROR: Must provide message nr for RETR command.\n");
          }
          responseTaken = 1;
          free(arg);
          break;

        }
        case 'D':
        {
          char  *arg = calloc(1, sizeof(char));
          *arg = GetMessageNrFromUser();
          argToLog[0] = *arg;
          
          if(*arg != '\n')
          {
            Send_DELE(ssl_con, arg);
            GetServerResponse(ssl_con);
          }
          else
          {
            printf("ERROR: Must provide message nr for DELE command.\n");
          }
          responseTaken = 1;
          free(arg);

          break;
        }
        case 'N':
        {
          Send_NOOP(ssl_con);
          break;
        }
        case 'r':
        {
          Send_RSET(ssl_con);
          break;
        }
        case 'F':
        {
          session = 0;
          break;
        }
        default:
        {
          session = 0;
          break;
        }
      }

      if (session == 1 && responseTaken == 0)
      {
        GetServerResponse(ssl_con);
      }
      responseTaken = 0;

      LogUsersChoice(outputLog, timeNow, cmd, argToLog[0]);
      argToLog[0] = '0';

    }while(session == 1);

    fclose(outputLog);
    CloseConnection(connection_fd, &ctx, &ssl_con);
    printf("Connection closed.\n");
    return 0;
}