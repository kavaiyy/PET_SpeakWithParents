#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int port = 8080;

    // 1. Создание TCP-сокета
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Ошибка создания сокета сервера!" << std::endl;
        return 1;
    }

    // Опция сокета: позволяет повторно использовать порт сразу после перезапуска сервера
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 2. Привязка сокета к адресу и порту (bind)
    sockaddr_in address;
    std::memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Слушать все доступные сетевые интерфейсы
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Ошибка привязки сокета (bind к порту " << port << ")!" << std::endl;
        close(server_fd);
        return 1;
    }

    // 3. Включение режима прослушивания (listen)
    // 5 — это размер очереди ожидания для входящих подключений
    if (listen(server_fd, 5) < 0) {
        std::cerr << "Ошибка перехода в режим прослушивания!" << std::endl;
        close(server_fd);
        return 1;
    }

    std::cout << "Сервер запущен и слушает порт " << port << "..." << std::endl;
    std::cout << "Ожидание подключения клиента..." << std::endl;

    // 4. Принятие входящего подключения (accept)
    // Эта функция "блокирует" выполнение программы, пока клиент не подключится
    sockaddr_in client_address;
    socklen_t addr_len = sizeof(client_address);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_address, &addr_len);
    
    if (client_fd < 0) {
        std::cerr << "Ошибка принятия подключения (accept)!" << std::endl;
        close(server_fd);
        return 1;
    }

    // Узнаем IP-адрес подключившегося клиента
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);
    std::cout << "Клиент подключился! IP: " << client_ip << std::endl;

    // 5. Чтение данных от клиента
    char buffer[1024] = {0};
    int bytes_read = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read > 0) {
        std::cout << "Получено от клиента: " << buffer << std::endl;

        // 6. Отправка ответа клиенту
        const char* response = "Привет от C++ Сервера! Твое сообщение получено.";
        send(client_fd, response, std::strlen(response), 0);
        std::cout << "Ответ отправлен клиенту." << std::endl;
    }

    // 7. Закрытие сокетов
    close(client_fd); // Закрываем соединение с конкретным клиентом
    close(server_fd); // Выключаем сам сервер
    std::cout << "Сервер завершил работу." << std::endl;

    return 0;
}