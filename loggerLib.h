#ifndef LOGGERLIB_H
#define LOGGERLIB_H

void LogUsersChoice(FILE *outputLog, time_t commandTime, char cmd, char arg);
void LogRetrievedMessage(char *msg);

#endif 