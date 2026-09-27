#include "ServerThread.h"


class ServerControl 
{
private:
    ServerThread* mThread = nullptr;
    wxEvtHandler* m_handler;
    int m_port;

public:

    void startServer();
    void stopServer();
    int isRunning();

    ServerControl(wxEvtHandler* handler, int port) : m_handler(handler), m_port(port) {};
    ~ServerControl()
    {
        if(this->isRunning())
        {
            // this->stopServer();
            this->mThread->Delete();
            delete this->mThread; // operator delete Automaticly calls deconstructor for this! (SocketManeger Destructor is inside)
            this->mThread = nullptr;
        };
        std::cout << "ServerControl Destructor: server thread Deleted" << std::endl;
    };
};

int ServerControl::isRunning() {
    if( this->mThread == nullptr ) {
        return 0; // false
    } else {
        return 1; // true
    };
};

void ServerControl::stopServer() {
    if( this->isRunning() ) 
    {
        this->~ServerControl();
        std::cout << "ServerControl. stopServer" << std::endl;
    };
};

void ServerControl::startServer() {
    if( this->mThread == nullptr ) 
    {
        this->mThread = new ServerThread(this->m_handler, this->m_port);
        if (this->mThread->Create() != wxTHREAD_NO_ERROR)
        {
            // wxLogError("Не удалось создать поток!");
            delete this->mThread; // operator delete Automaticly calls deconstructor for this!
            return;
        }
        this->mThread->Run();
        std::cout << "GetToggleServerThreadBtn. Server thread has run" << std::endl;
    };
};