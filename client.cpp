#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    const char* server_ip = "127.0.0.1"; // Локальный адрес (IP самого себя)
    int server_port = 8080;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Ошибка создания сокета клиента!" << std::endl;
        return 1;
    }

    sockaddr_in server_address;
    std::memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        std::cerr << "Неверный IP-адрес!" << std::endl;
        close(sock);
        return 1;
    }

    std::cout << "Подключение к серверу..." << std::endl;
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Ошибка подключения! Сервер запущен?" << std::endl;
        close(sock);
        return 1;
    }
    std::cout << "Успешно подключено к серверу!" << std::endl;

    // Отправляем сообщение серверу
    const char* message = "Привет, Сервер! Я твой клиент. Hali Hali Hali uya";
    send(sock, message, std::strlen(message), 0);
    std::cout << "Сообщение отправлено." << std::endl;

    // Ждем ответ от сервера
    char buffer[1024] = {0};
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        std::cout << "Ответ от сервера: " << buffer << std::endl;
    }

    close(sock);
    return 0;
}