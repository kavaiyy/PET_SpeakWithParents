#include <wx/wx.h>


// #include <iostream>
// #include <cstring>
// #include <unistd.h>
// #include <arpa/inet.h>
// #include <sys/socket.h>


#include "MySocket.h"

// 1. CHOOSE AN ID FOR THE BUTTON
const int ID_BUTTON_CLICKME = 101;
const int ID_BUTTON_GETIP   = 102;

// 2. DEFINE THE MAIN WINDOW (FRAME)
class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Basic wxWidgets GUI App", wxPoint(50, 50), wxSize(400, 250))
    {
        // Layout manager to handle auto-positioning and resizing
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);




        // FUNCTIONALITY 1
        m_label1             = new wxStaticText(this, wxID_ANY, "Waiting for action...", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
        m_button_show_label1 = new wxButton(this, ID_BUTTON_CLICKME, "Click Me", wxDefaultPosition, wxSize(200, 40));
        sizer->Add(m_button_show_label1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        sizer->Add(m_label1, 0, wxALL | wxEXPAND, 20);
        
        // FUNCTIONALITY 2
        m_button_get_IP = new wxButton(this, ID_BUTTON_GETIP, "Get IP", wxDefaultPosition, wxSize(200, 40));
        m_label_get_IP  = new wxStaticText(this, wxID_ANY, "Result: (IP of server)", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
        sizer->Add(m_button_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        sizer->Add(m_label_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

        // FUNCTIONALITY 3



        this->SetSizer(sizer);
        this->Layout();

        // Connect the button event to our custom logic handler
        Bind(wxEVT_BUTTON, &MyFrame::OnMyButtonClicked, this, ID_BUTTON_CLICKME);
        Bind(wxEVT_BUTTON, &MyFrame::OnMyButtonGetIP, this, ID_BUTTON_GETIP);


        internet_connection = new SocketConnection();
    }

private:
    wxStaticText* m_label1;
    wxButton* m_button_show_label1;

    wxButton* m_button_get_IP;
    wxStaticText* m_label_get_IP;

    SocketConnection* internet_connection;

    // ==========================================
    // 3. WRITE YOUR CUSTOM FUNCTIONALITY HERE
    // ==========================================
    void OnMyButtonClicked(wxCommandEvent& event)
    {





        // Put whatever you want your app to do when the button is pressed
        // For example, change the text of our label:
        m_label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");


        internet_connection->SendData();
        internet_connection->CloseConnection();


    }

    void OnMyButtonGetIP(wxCommandEvent& event)
    {
        // Put whatever you want your app to do when the button is pressed
        // For example, change the text of our label:
        // m_label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");

        internet_connection->Get_IP();
        // internet_connection->CloseConnection();

    }

};




// 4. DEFINE THE APPLICATION CLASS
class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

// 5. APPLICATION ENTRY POINT (Replaces main / WinMain)
wxIMPLEMENT_APP(MyApp);