#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "user_UI.h"


void DisplayCommands()
{
  printf("\nPossible commands:\n1. USER\n2. PASS\n3. QUIT\n4. STAT\n5. LIST [msg nr]\n6. RETR msg nr\n7. DELE msg nr\n8. NOOP\n9. RSET\n10.Help\n11. Finish\n\n");
  printf("Select command - input [U/P/Q/S/L/R/D/N//r/H/F]\n");
  printf("NOTE: some commands may be inavailable in different connection states.\n\n");
}

char GetUsersChoice(int connectionState)
{
  char line[256];
  char *cmds = calloc(MAX_NUMB_OF_CMDS_CHARS, sizeof(char));
  printf("Client: ");

  switch (connectionState)
  {
  case 0:
    cmds = AUTH_STATE_CMDS;
    break;
  case 1:
    cmds = TRANS_STATE_CMDS;
    break;
  default:
    cmds = "F";
    break;
  }

  while(fgets(line, sizeof(line), stdin) == NULL || strchr(cmds, line[0]) == NULL)
  {
    printf("Possible commands: %s\n", cmds);
  }
  return line[0];
}

char GetMessageNrFromUser()
{
  char line[256];
  printf("msg nr = ");
  
  while(fgets(line, sizeof(line), stdin) == NULL || (isdigit(line[0]) == 0 && line[0] != '\n'))
  {
    printf("Please input an integer or press enter to leave the line empty.\n");
  }
  return line[0];
}