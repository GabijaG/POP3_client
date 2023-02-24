cmake_minimum_required(VERSION 3.16.3)

project(POP3Client C)

set(CMALE_C_STANDART 11)

link_libraries(ssl crypto)

add_executable(POP3Client POP3_Client.c ssl_connection.h ssl_connection.c user_UI.h user_UI.c pop3_clientLib.h pop3_clientLib.c loggerLib.h loggerLib.c)