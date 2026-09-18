#include "UI.h"


#include "MySocket.h"
#include "server.h"




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

    // ---------- ---------------- ----------
    // ---------- FUNCTIONALITY 3: ----------
    // Обработчики событий
    void OnSubmitPressed(wxCommandEvent& event);
    void OnEnterPressed(wxCommandEvent& event);
    // Единый метод для обработки введенного текста
    void ProcessSubmittedText();
    // ---------- ---------------- ----------
    // ---------- ---------------- ----------

    // Defualt events:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);

public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Write to Your Parents", wxPoint(50, 50), wxSize(600, 650)) // wxSize(400, 250)
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
        m_panel2->GetEventButton()->Bind(wxEVT_BUTTON, &MyFrame::OnMyBtnGetIP,      this);

        // Functionality 3
        m_panel3 = new Panel_3(this);
        mainSizer->Add(m_panel3, 1, wxEXPAND);
        m_panel3->GetEventButton()->Bind(wxEVT_BUTTON,         &MyFrame::OnSubmitPressed,      this);
        m_panel3->GetEventTextInput()->Bind(wxEVT_TEXT_ENTER,  &MyFrame::OnEnterPressed,       this);
        m_panel3->SetBackgroundColour(*wxBLUE); // Для наглядности



        // Привязка нажатия на кнопку
        // submitButton->Bind(wxEVT_BUTTON, &MyFrame::OnSubmitPressed, this);
        
        // Привязка нажатия Enter внутри текстового поля
        // m_textInput->Bind(wxEVT_TEXT_ENTER, &MyFrame::OnEnterPressed, this);


        SetSizer(mainSizer);
        mainSizer->Fit(this);
        Layout();
        OutputConnection = new SocketConnection();
        myServer = new ServerManager();

    }

    ~MyFrame() 
    {
        OutputConnection->~SocketConnection();
        myServer->~ServerManager();
    };


    // ----------------------------------------------
    // Functionality 1
    void OnMyButtonClicked2(wxCommandEvent& event)
    {
        std::string result = "Hello123! Your custom wxWidgets code ran.";
        m_panel1->ShowText(wxString(result));
        OutputConnection->Get_IP();
    };
    void OnMyButtonClicked(wxCommandEvent& event)
    {
        myServer->wait_for_client();
        myServer->WhatIsClientIP();
        myServer->clients_msg();
        std::string result = "After accept function.";
        m_panel1->ShowText(wxString(result));
    };
    // ----------------------------------------------
    // Functionality 2
    void OnMyBtnGetIP(wxCommandEvent& event)
    {
        OutputConnection->SendData();
        std::cout << "MyFrame." << std::endl;
    };
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


// ============================================================================
// 3. FOR 3 FUNCTIONALITY
// ============================================================================
// Обработчики событий
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
    std::cout << "ProcessSubmittedText." << std::endl;
};
