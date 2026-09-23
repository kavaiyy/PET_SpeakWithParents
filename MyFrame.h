#include "UI.h"


#include "MySocket.h"
#include "server.h"

#include "ServerThread.h"


// ============================================================================
// 2. THE MAIN WINDOW INTERFACE
// ============================================================================
class MyFrame : public wxFrame
{
private:
    // UI:
    Panel_1* m_panel1;
    Panel_2* m_panel2;
    Panel_3* m_panel3;

    // Logic:
    SocketConnection* OutputConnection;
    ServerManager* myServer;
    ServerThread* mThread = nullptr;



    void OnMyButtonClicked(wxCommandEvent& event);
    void OnMyButtonSendMSG(wxCommandEvent& event);

    // ---------- ---------------- ----------
    // ---------- FUNCTIONALITY 3: ----------
    // Обработчики событий
    void OnSubmitPressed(wxCommandEvent& event);
    void OnEnterPressed(wxCommandEvent& event);
    // Единый метод для обработки введенного текста
    void ProcessSubmittedText();
    void OnTogglePressed(wxCommandEvent& event);
    // ---------- ---------------- ----------
    // ---------- ---------------- ----------

    // Обычные методы класса (не нужно никаких специальных макросов)
    void OnToggleServer(wxCommandEvent& event);     // on/off server
    void OnClientConnected(wxThreadEvent& event);   // ClientConnected


    // Defualt events:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    // void OnClose(wxCommandEvent& event);

public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Write to Your Parents", wxPoint(50, 50), wxSize(1200, 750)) // wxSize(400, 250)
    {
        // Main container for window
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL); // wxHORIZONTAL

        // Functionality 1
        m_panel1 = new Panel_1(this);
        mainSizer->Add(m_panel1, 1, wxEXPAND | wxRIGHT, 10);
        m_panel1->GetEventButton()->Bind(wxEVT_BUTTON, &MyFrame::OnMyButtonClicked, this);
        m_panel1->SetBackgroundColour(*wxRED); // Для наглядности
        
        // Functionality 2
        m_panel2 = new Panel_2(this);
        mainSizer->Add(m_panel2, 1, wxEXPAND);
        m_panel2->GetEventButton()->Bind(wxEVT_BUTTON, &MyFrame::OnMyButtonSendMSG,      this);

        // Functionality 3
        m_panel3 = new Panel_3(this);
        mainSizer->Add(m_panel3, 1, wxEXPAND);
        m_panel3->GetEventButton()->Bind(wxEVT_BUTTON,           &MyFrame::OnSubmitPressed,      this);
        m_panel3->GetEventTextInput()->Bind(wxEVT_TEXT_ENTER,    &MyFrame::OnEnterPressed,       this);
        m_panel3->GetToggleServerThreadBtn()->Bind(wxEVT_BUTTON, &MyFrame::OnTogglePressed,      this);
        m_panel3->SetBackgroundColour(*wxBLUE); // Для наглядности

        SetSizer(mainSizer);
        // mainSizer->Fit(this);
        Layout();

        // App logic:
        OutputConnection = new SocketConnection();
        myServer = new ServerManager();
        // mThread = new ServerThread(this, 77);
    }

    ~MyFrame() 
    {
        OutputConnection->~SocketConnection();
        myServer->~ServerManager();
        if (mThread != nullptr) {
            mThread->~ServerThread();
        };
    };
};



// // ----------------------------------------------
// // Panel_1 Functionality
// // ----------------------------------------------
void MyFrame::OnMyButtonClicked(wxCommandEvent& event)
{
    // std::string result2 = "Server is ON in main thread and waiting for client to send a message.";
    // m_panel1->ShowText(wxString(result2));
    myServer->wait_for_client();
    myServer->WhatIsClientIP();
    myServer->clients_msg();
    std::string result = "Accept function has worked. Message from client is recieved.";
    m_panel1->ShowText(wxString(result));
};

// // ----------------------------------------------
// // Panel_2 Functionality
// // ----------------------------------------------
void MyFrame::OnMyButtonSendMSG(wxCommandEvent& event)
{
    OutputConnection->SendData();
    std::cout << "Hello message is sent to the server 8.8.8.8." << std::endl;
};

// // ----------------------------------------------
// 3. Panel_2 Functionality
// // ----------------------------------------------
void MyFrame::OnSubmitPressed(wxCommandEvent& event)
{
    int i;
    i = 1;
    std::cout << "OnSubmitPressed." << std::endl;
    MyFrame::ProcessSubmittedText();
};
void MyFrame::OnEnterPressed(wxCommandEvent& event)
{
    int i;
    i = 1;
    std::cout << "OnEnterPressed." << std::endl;
    MyFrame::ProcessSubmittedText();
};
// Единый метод для обработки введенного текста
void MyFrame::ProcessSubmittedText()
{
    int i;
    i = 1;
    // mThread->Delete();
    std::cout << "ProcessSubmittedText." << std::endl;
};

void MyFrame::OnTogglePressed(wxCommandEvent& event)
{
    if( mThread == nullptr ) {
        mThread = new ServerThread(this, 77);
        mThread->Run();
        std::cout << "GetToggleServerThreadBtn. Runned" << std::endl;
    } else {
        mThread->Delete();
        mThread = nullptr;
        std::cout << "GetToggleServerThreadBtn. Deleted" << std::endl;
    }

};




























// Event Handler callbacks
void MyFrame::OnHello(wxCommandEvent& event)
{
    int buff_OnHello = 3;
    buff_OnHello = buff_OnHello + 1;
};
void MyFrame::OnExit(wxCommandEvent& event)
{
    OutputConnection->~SocketConnection();
    Close(true);
    std::cout << "OnExit." << std::endl;
    // internet_connection->CloseConnection();
    // myServer->~ServerManager();
};