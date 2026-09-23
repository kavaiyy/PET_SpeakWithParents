// #pragma once
#include <wx/thread.h>
#include <wx/event.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>

// Объявляем уникальный ID для события "Клиент подключился"
// wxDECLARE_EVENT(wxEVT_SERVER_CLIENT_CONNECTED, wxThreadEvent);

class ServerThread : public wxThread {
public:
    // Передаем указатель на окно-обработчик (например, главное окно приложения)
    ServerThread(wxEvtHandler* handler, int port);
    virtual ~ServerThread();

    // int isRunning();

protected:
    virtual ExitCode Entry() override;

private:
    wxEvtHandler* m_handler;
    int m_port;
    int m_server_id;
};




// wxDEFINE_EVENT(wxEVT_SERVER_CLIENT_CONNECTED, wxThreadEvent);

ServerThread::ServerThread(wxEvtHandler* handler, int port)
    : wxThread(wxTHREAD_DETACHED), m_handler(handler), m_port(port), m_server_id(-1) {}

ServerThread::~ServerThread() {
    // if (m_server_id != -1) {
    //     close(m_server_id);
    // }
}

wxThread::ExitCode ServerThread::Entry() {

    std::cout << "Thread is luanched." << std::endl;
    while (!TestDestroy()) {
        
    }
    std::cout << "Thread is closed." << std::endl;

    return (ExitCode)0;
}
















// wxThread::ExitCode ServerThread::Entry() {
//     m_server_fd = socket(AF_INET, SOCK_STREAM, 0);
//     if (m_server_fd < 0) return (ExitCode)0;

//     int opt = 1;
//     setsockopt(m_server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

//     // СВЕРХВАЖНО: Делаем сокет неблокирующим для мягкой остановки потока
//     int flags = fcntl(m_server_fd, F_GETFL, 0);
//     fcntl(m_server_fd, F_SETFL, flags | O_NONBLOCK);

//     sockaddr_in address{};
//     address.sin_family = AF_INET;
//     address.sin_addr.s_addr = INADDR_ANY;
//     address.sin_port = htons(m_port);

//     if (bind(m_server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
//         return (ExitCode)0;
//     }

//     if (listen(m_server_fd, 5) < 0) {
//         return (ExitCode)0;
//     }

//     // Цикл ожидания подключений
//     while (!TestDestroy()) {
//         sockaddr_in client_address;
//         socklen_t addr_len = sizeof(client_address);
        
//         int client_fd = accept(m_server_fd, (struct sockaddr*)&client_address, &addr_len);
        
//         if (client_fd >= 0) {
//             // Клиент успешно подключился!
//             char client_ip[INET_ADDRSTRLEN];
//             inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);

//             // Безопасно отправляем уведомление в GUI-поток
//             wxThreadEvent* event = new wxThreadEvent(wxEVT_SERVER_CLIENT_CONNECTED);
//             event->SetString(wxString::FromUTF8(client_ip));
//             event->SetInt(client_fd); // Передаем дескриптор клиента для дальнейшей работы
//             wxQueueEvent(m_handler, event);
//         } 
//         else {
//             // Если клиентов нет (EAGAIN/EWOULDBLOCK), просто спим 100 мс и проверяем TestDestroy()
//             if (errno == EAGAIN || errno == EWOULDBLOCK) {
//                 wxMilliSleep(100); 
//             } else {
//                 // Произошла реальная ошибка сокета
//                 break;
//             }
//         }
//     }

//     return (ExitCode)0;
// }