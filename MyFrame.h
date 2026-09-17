#include "UI.h"


#include "MySocket.h"
// #include "server.h"







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
    // ServerManager* myServer;

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
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Basic wxWidgets GUI App", wxPoint(50, 50), wxSize(400, 250))
    {
        // Main container for window
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL); // wxHORIZONTAL

        // Functionality 1
        m_panel1 = new Panel_1(this);
        mainSizer->Add(m_panel1, 0, wxEXPAND | wxRIGHT, 2);
        m_panel1->GetEventButton()->Bind(wxEVT_BUTTON, &MyFrame::OnMyButtonClicked, this);
        
        // Functionality 2
        m_panel2 = new Panel_2(this);
        mainSizer->Add(m_panel2, 1, wxEXPAND);
        m_panel2->GetEventButton()->Bind(wxEVT_BUTTON, &MyFrame::OnMyBtnGetIP,      this);

        // Functionality 3
        m_panel3 = new Panel_3(this);
        mainSizer->Add(m_panel3, 1, wxEXPAND);


        SetSizer(mainSizer);
        Layout();

        OutputConnection = new SocketConnection();

    }

    ~MyFrame() 
    {

    };



    void OnMyBtnGetIP(wxCommandEvent& event)
    {
        OutputConnection->SendData();
        std::cout << "MyFrame." << std::endl;
    };
    void OnMyButtonClicked(wxCommandEvent& event)
    {
        // Put whatever you want your app to do when the button is pressed
        // For example, change the text of our label:
        std::string result = "Hello123! Your custom wxWidgets code ran.";
        // m_panel1->m_Label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");
        // wxString(result);
        m_panel1->ShowText(wxString(result));

        OutputConnection->Get_IP();

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
    MyFrame::ProcessSubmittedText();
};
void MyFrame::OnEnterPressed(wxCommandEvent& event)
{
    int i;
    i = 1;
    MyFrame::ProcessSubmittedText();
};
// Единый метод для обработки введенного текста
void MyFrame::ProcessSubmittedText()
{
    int i;
    i = 1;
};
