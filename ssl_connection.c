#include <string.h>
#include"ssl_connection.h"

//Create connection socket
int OpenConnection(char *serverIP)
{
  int status;
  struct addrinfo hints;
  struct addrinfo *servinfo, *p;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if ((status = getaddrinfo(serverIP, PORT_SSL, &hints, &servinfo)) != 0)
  {
    fprintf(stdout, "getaddrinfo error: %s\n", gai_strerror(status));
    exit(2);
  }

  int socket_fd, yes = 1;

  for (p = servinfo; p != NULL; p->ai_next)
  {
    if ((socket_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
    {
      perror("socket failed");
      continue;
    }

    if (connect(socket_fd, p->ai_addr, p->ai_addrlen) == -1)
        {
            close(socket_fd);
            perror("connect failed");
            continue;
        }
    break;
  }
  freeaddrinfo(servinfo);

  if (p == NULL)
  {
    fprintf(stdout, "C: Unable to open socet.\n");
    exit(3);
  }
  else
  {
    return socket_fd;
  }
}

//Initialize SSL connection with the server
int InitializeSSL(int socket_fd, SSL_CTX **ctx, SSL **ssl)
{
  SSL_library_init();
  SSL_load_error_strings();
  OpenSSL_add_ssl_algorithms();

  const SSL_METHOD *method = TLS_client_method();

  //Initialize new context:
  if ((*ctx = SSL_CTX_new(method)) == NULL)
  {
    return -1;
  }

  //Initialize new connection object:
  if ((*ssl = SSL_new(*ctx)) == NULL)
  {
    return -1;
  }

  /// Automatically creates socket BIO
  if (SSL_set_fd(*ssl, socket_fd) == 0) 
  {
    return -1;
  }

  // TLS handshake with server
  if (SSL_connect(*ssl) <= 0)
  {
    return -1;
  }
}

void CloseConnection(int connection_fd, SSL_CTX **ctx, SSL **ssl_con)
{
  close(connection_fd);
  SSL_shutdown(*ssl_con);
  SSL_free(*ssl_con);
  SSL_CTX_free(*ctx);
  EVP_cleanup();

  ERR_free_strings();
}