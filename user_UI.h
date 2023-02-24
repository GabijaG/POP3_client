#ifndef USER_UI_H
#define USER_UI_H


#define MAX_NUMB_OF_CMDS_CHARS 20
#define AUTH_STATE_CMDS "UPQHF"
#define TRANS_STATE_CMDS "SLRDNrQHF"


void DisplayCommands();
char GetUsersChoice(int connectionState);
char GetMessageNrFromUser();


#endif //USER_UI_H
