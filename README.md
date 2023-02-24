# Computer Networks POP3 client

University assignment for computer networks course.

## LAB2 - POP3 Client

An implementation of client conforming to POP3 protocol.
The implementation is written in C and is done according to  https://www.ietf.org/rfc/rfc1939.txt. It is **written for Linux** OS only. 
Optional commands were not implemented. The client was tested using the gmail server `pop.gmail.com` connection port is `SSL 995`.  

As an additional requirement, the client program can read attachments (if there are any). Then they are decoded and printed out into separate files.

### Building the project

Open the `build` folder in terminal.
Then issue commands:
```
cmake ..
make all
```
### Running it

To test it out with gmail account you need to write in your gmail address and password in `ssl_connection.h` file.
The server IP address needs to be passed as a command line argument. 

For example running it in Linux environment:
```
./POP3Client pop.gmail.com

```

### NOTE

No longer possible to test the client using gmail account as Google announced that after the 30th of MAY 2022 it will not allow third party programs who allow authentication only with username and password.
>To help keep your account secure, starting May 30, 2022, ​​Google will no longer support the use of third-party apps or devices which ask you to sign in to your Google Account using only your username and password.
