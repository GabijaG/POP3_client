#ifndef SSL_CONNECTION_H
#define SSL_CONNECTION_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/evp.h>


#define PORT_SSL "995"
#define USERNAME "myaddress@gmailservice.com"
#define PASSWORD "aScretSoDoNotTell"

int OpenConnection(char *serverIP);
int InitializeSSL(int socket_fd, SSL_CTX **ctx, SSL **ssl);
void CloseConnection(int connection_fd, SSL_CTX **ctx, SSL **ssl_con);

#endif //SSL_CONNECTION_H