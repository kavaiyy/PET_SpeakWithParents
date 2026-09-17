#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <netdb.h>


// 1. Параметры сервера для подключения
const char* server_ip = "8.8.8.8";   // Замените на IP вашего сервера
int server_port = 53;                // Замените на порт вашего сервера

const char* LOCAL_IP  = "127.0.0.1";
int LOCAL_PORT = 8080;

const char* hostname = "google.com"; // Замените на URL вашего сервера


// 2. DEFINE THE MAIN WINDOW (FRAME)
class SocketConnection
{
public:
    int sock;

    SocketConnection()
    {
        // 2. Создание TCP-сокета
        // AF_INET - протокол IPv4, SOCK_STREAM - потоковый сокет (TCP)
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            std::cerr << "Ошибка создания сокета!" << std::endl;
            // return 1;
        }
        std::cout << "Сокет успешно создан." << std::endl;


        // 3. Настройка структуры с адресом сервера
        sockaddr_in server_address;
        std::memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(server_port); // Перевод порта в сетевой порядок байт


        // Преобразование IP-адреса из текста в бинарный формат
        if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
            std::cerr << "Неверный IP-адрес или адрес не поддерживается!" << std::endl;
            close(sock);
            // return 1;
        }

        // 4. Установка соединения с сервером
        std::cout << "Подключение к " << server_ip << ":" << server_port << "..." << std::endl;
        if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
            std::cerr << "Ошибка подключения! Сервер недоступен." << std::endl;
            close(sock);
            // return 1;
        }
        std::cout << "Успешно подключено к серверу!" << std::endl;

    };
    ~SocketConnection()
    {
        std::cout << "Destructor: SocketConnection object.\n";
        close(sock);
    }

    int SendData()
    {
        // 5. Отправка данных (опционально)
        const char* message = "Hello from C++ client!";
        int bytes_sent = send(sock, message, std::strlen(message), 0);

        if (bytes_sent < 0) {
            std::cerr << "Ошибка отправки данных!" << std::endl;
        } else {
            std::cout << "Отправлено байт: " << bytes_sent << std::endl;
        }
        return 0;
    }
    int CloseConnection()
    {
        // 6. Закрытие сокета
        close(sock);
        std::cout << "Соединение закрыто." << std::endl;

        return 0;
    }

    int Get_IP()
    {
        struct addrinfo hints, *res, *p;
        std::memset(&hints, 0, sizeof(hints));

        // Вызываем функцию ОС для работы с DNS
        int status = getaddrinfo(hostname, nullptr, &hints, &res);
        if (status != 0) {
            // Если ошибка, выводим её текстовое описание с помощью gai_strerror
            std::cerr << "Ошибка DNS для " << hostname << ": " << gai_strerror(status) << std::endl;
            return 1;
        }
        // std::cout << "IP-адреса для хоста [" << hostname << "]:" << std::endl;

        // Циклом проходим по связному списку результатов (res -> res->ai_next -> ...)
        for (p = res; p != nullptr; p = p->ai_next) {
            char ip_str[INET6_ADDRSTRLEN]; // Буфер для хранения готовой строки IP-адреса

            // Проверяем, какой тип адреса нам вернулся
            if (p->ai_family == AF_INET) { // IPv4 адрес
                struct sockaddr_in* ipv4 = (struct sockaddr_in*)p->ai_addr;
                
                // Преобразуем бинарный адрес в текст
                inet_ntop(AF_INET, &(ipv4->sin_addr), ip_str, sizeof(ip_str));
                std::cout << "  IPv4: " << ip_str << std::endl;
                
            } else if (p->ai_family == AF_INET6) { // IPv6 адрес
                struct sockaddr_in6* ipv6 = (struct sockaddr_in6*)p->ai_addr;
                
                // Преобразуем бинарный адрес в текст
                inet_ntop(AF_INET6, &(ipv6->sin6_addr), ip_str, sizeof(ip_str));
                std::cout << "  IPv6: " << ip_str << std::endl;
            }
        }

        freeaddrinfo(res);
        return 0;
    }





private:


};







// ------------- IN ONE GO --------------------- 

        // // 1. Параметры сервера для подключения
        // const char* server_ip = "8.8.8.8"; // Замените на IP вашего сервера
        // int server_port = 53;              // Замените на порт вашего сервера

        // // 2. Создание TCP-сокета
        // // AF_INET - протокол IPv4, SOCK_STREAM - потоковый сокет (TCP)
        // int sock = socket(AF_INET, SOCK_STREAM, 0);
        // if (sock < 0) {
        //     std::cerr << "Ошибка создания сокета!" << std::endl;
        //     // return 1;
        // }
        // std::cout << "Сокет успешно создан." << std::endl;

        // // 3. Настройка структуры с адресом сервера
        // sockaddr_in server_address;
        // std::memset(&server_address, 0, sizeof(server_address));
        // server_address.sin_family = AF_INET;
        // server_address.sin_port = htons(server_port); // Перевод порта в сетевой порядок байт

        // // Преобразование IP-адреса из текста в бинарный формат
        // if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        //     std::cerr << "Неверный IP-адрес или адрес не поддерживается!" << std::endl;
        //     close(sock);
        //     // return 1;
        // }

        // // 4. Установка соединения с сервером
        // std::cout << "Подключение к " << server_ip << ":" << server_port << "..." << std::endl;
        // if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        //     std::cerr << "Ошибка подключения! Сервер недоступен." << std::endl;
        //     close(sock);
        //     // return 1;
        // }
        // std::cout << "Успешно подключено к серверу!" << std::endl;

        // // 5. Отправка данных (опционально)
        // const char* message = "Hello from C++ client!";
        // int bytes_sent = send(sock, message, std::strlen(message), 0);
        // if (bytes_sent < 0) {
        //     std::cerr << "Ошибка отправки данных!" << std::endl;
        // } else {
        //     std::cout << "Отправлено байт: " << bytes_sent << std::endl;
        // }

        // // 6. Закрытие сокета
        // close(sock);
        // std::cout << "Соединение закрыто." << std::endl;
