#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#include "loggerLib.h"


void LogUsersChoice(FILE *outputLog, time_t commandTime, char cmd, char arg)
{
    char *time = calloc(1, sizeof(time_t));

    time = ctime(&commandTime);
    time[strlen(time)-1] = '\0';

    if(arg == '\n')
    {
        arg = 'n';
    }

    switch(cmd)
    {
        case 'U':
        {

            fprintf(outputLog, "%s Command: USER\n", time);
            break;
        }
        case 'P':
        {
            fprintf(outputLog, "%s Command: PASS\n", time);
            break;
        }
        case 'Q':
        {
            fprintf(outputLog, "%s Command: QUIT\n", time);
            break;
        }
        case 'S':
        {
            fprintf(outputLog, "%s Command: STAT\n", time);
            break;
        }
        case 'L':
        {
            fprintf(outputLog, "%s Command: LIST argument = %c\n", time, arg);
            break;
        }
        case 'R':
        {
            fprintf(outputLog, "%s Command: RETR argument = %c\n", time, arg);
            break;
        }
        case 'D':
        {
            fprintf(outputLog, "%s Command: DELE argument = %c\n", time, arg);
            break;
        }
        case 'N':
        {
            fprintf(outputLog, "%s Command: NOOP\n", time);
            break;
        }
        case 'r':
        {
            fprintf(outputLog, "%s Command: RSET\n", time);
            break;
        }
        case 'F':
        {
            fprintf(outputLog, "%s Command: Finish job.\n", time);
            break;
        }
        default:
        {
            break;
        }
    }
}

void LogRetrievedMessage(char *msg)
{
    time_t timeNow = time(0);
    char *fileName = calloc(2, sizeof(time_t));

    fileName = ctime(&timeNow);
    fileName[strlen(fileName)-1] = '\0';

    strcat(fileName, " msg.txt");

    FILE *outFile = fopen(fileName, "w");

    fprintf(outFile, "%s", msg);

    fclose(outFile);
}