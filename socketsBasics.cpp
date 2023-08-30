#include <bits/stdc++.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;

#define PORT 40000
#define IP_ADDR "127.0.0.1"
struct sockaddr_in srv;

int main() {
  // create the socket
  int nSocket = socket(AF_INET, SOCK_DGRAM, 0);

  if (nSocket < 0) {
    cout << "Failed to create the socket\n";
  } else {
    cout << "Socket created with socket id: " << nSocket << endl;
  }

  // sockaddr_in details
  srv.sin_family = AF_INET;
  srv.sin_port = htons(PORT);
  srv.sin_addr.s_addr = INADDR_ANY;

  /*
  memset is a function in C and C++ that is used to set a block of memory to a
  specific value. It stands for "memory set" and is often used to initialize
  arrays or structures with a specific value, such as zero or a particular
  character.
  */

  memset(&srv, 0, sizeof(srv));

  /*
   Bind the socket to the local port
    In socket programming, "binding" refers to the process of associating a
   socket with a specific network address and port number. Binding is an
   essential step that a server-side socket needs to perform before it can start
   listening for incoming connections.

    When a socket is bound, it means that the operating system has reserved the
    specified network address and port number for that socket to use. This
   allows other sockets to connect to or communicate with the bound socket using
   that address and port.*/
   
  int nRet = 0;
  nRet = bind(nSocket, (struct sockaddr *)&srv, sizeof(srv));
  if (nRet < 0) {
    std::cerr << "Failed to bind receiver socket" << std::endl;
  } else {
    cout << "Socket successfully binded\n";
  }

  nRet = listen(nSocket, 0);
  if (nRet < 0) {
    cout << "Failed to listen";
  } else {
    cout << "Listening to the local port\n";
  }

  return 0;
}