#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main() {
    // Get the server IP address from the user
    std::cout << "Enter the server IP address: ";
    std::string serverIP;
    std::cin >> serverIP;
    std::cout << "You entered the following IP address "  << serverIP << std::endl;

    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket\n";
        return -1;
    }

    // Connect to the server
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);

    if (inet_pton(AF_INET, serverIP.c_str(), &serverAddress.sin_addr) <= 0) {
        std::cerr << "Invalid IP address\n";
        close(clientSocket);
        return -1;
    }

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error connecting to server\n";
        close(clientSocket);
        return -1;
    }

    std::cout << "Connected to server\n";

    while (true) {
        // Send a message to the server
        std::cout << "Client: ";
        std::string message;
        //std::getline(std::cin, message);
	std::cin >> message;

	//std::cout << "You enterd " << message << std::endl;

        if (message == "exit") {
            break;  // Exit the loop if the user types "exit"
        }

        send(clientSocket, message.c_str(), message.size(), 0);

        // Receive a response from the server
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);

        if (bytesRead <= 0) {
            std::cerr << "Connection closed by server\n";
            break;
        }

        // Display received message
        std::cout << "Server: " << buffer << std::endl;
    }

    // Close the socket
    close(clientSocket);

    return 0;
}

