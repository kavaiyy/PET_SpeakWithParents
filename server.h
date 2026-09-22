#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>



class ServerManager
{
public:
    int server_id;
    int listen_port = 8080;
    sockaddr_in server_address;

    int client_id;
    sockaddr_in client_address;


    ServerManager()
    {
        // 1. Создание TCP-сокета
        server_id = socket(AF_INET, SOCK_STREAM, 0);
        if (server_id < 0) {
            std::cerr << "Ошибка создания сокета сервера!" << std::endl;
            // return 1;
        }

        // Опция сокета: позволяет повторно использовать порт сразу после перезапуска сервера
        int opt = 1;
        setsockopt(server_id, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        // 2. Привязка сокета к адресу и порту (bind)
        std::memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = INADDR_ANY; // Слушать все доступные сетевые интерфейсы
        server_address.sin_port = htons(listen_port);

        if (bind(server_id, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
            std::cerr << "Ошибка привязки сокета (bind к порту " << listen_port << ")!" << std::endl;
            close(server_id);
            // return 1;
        };

        // 3. Включение режима прослушивания (listen)
        // 5 — это размер очереди ожидания для входящих подключений
        if (listen(server_id, 5) < 0) {
            std::cerr << "Ошибка перехода в режим прослушивания!" << std::endl;
            close(server_id);
            // return 1;
        };
        std::cout << "Сервер запущен и слушает порт " << listen_port << "..." << server_id << std::endl;
        std::cout << "Ожидание подключения клиента..." << std::endl;

    };
    ~ServerManager()
    {
        close(server_id);
        close(client_id);
        std::cout << "Destructor: ServerManager object.\n";
    };


    int wait_for_client()
    {
        socklen_t addr_len = sizeof(client_address);
        client_id = accept(server_id, (struct sockaddr*)&client_address, &addr_len);
        
        if (client_id < 0) {
            std::cerr << "Ошибка принятия подключения (accept)!" << server_id << std::endl;

            std::cerr << "Ошибка принятия подключения (accept)! Код ошибки (errno): " << errno << " (" << std::strerror(errno) << ")" << std::endl;

            close(server_id);
            return 1;
        }
        return 0;
    };
 
    // Узнаем IP-адрес подключившегося клиента
    int WhatIsClientIP()
    {
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);
        std::cout << "Клиент подключился! IP: " << client_ip << std::endl;
        return 0;
    };
    
    int clients_msg()
    {
        // 5. Чтение данных от клиента
        char buffer[1024] = {0};
        int bytes_read = recv(client_id, buffer, sizeof(buffer) - 1, 0);
        if (bytes_read > 0) {
            std::cout << "Получено от клиента: " << buffer << std::endl;

            // 6. Отправка ответа клиенту
            const char* response = "Привет от C++ Сервера! I've got your msg. HaliHali";
            send(client_id, response, std::strlen(response), 0);
            std::cout << "Ответ отправлен клиенту." << std::endl;
        }
        return 0;
     };


private:


};
