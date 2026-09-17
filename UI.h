// #include <wx/wx.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <iostream>
#include <cstring>
#include <unistd.h>

// ============================================================================
// 1. CHOOSE AN ID FOR THE BUTTON
// ============================================================================
const int ID_BUTTON_CLICKME = 101;
const int ID_BUTTON_GETIP   = 102;

// #include "MySocket.h"
// #include "server.h"




// Panel_1.h
class Panel_1 : public wxPanel {
public:
    Panel_1(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        
        m_Label1  = new wxStaticText(this, wxID_ANY, "Waiting for action...", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
        m_button_ShowLabel1 = new wxButton(this, ID_BUTTON_CLICKME, "Click Me", wxDefaultPosition, wxSize(200, 40));
        
        sizer->Add(m_button_ShowLabel1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        sizer->Add(m_Label1, 0, wxALL | wxEXPAND, 20);
        
        SetSizer(sizer);
        
        // Привязываем события внутри этого же класса
        // m_btnOpen->Bind(wxEVT_BUTTON, &SidebarPanel::OnOpenPressed, this);
        // m_button_ShowLabel1->Bind(wxEVT_BUTTON, &Panel_1::OnMyButtonClicked, this, ID_BUTTON_CLICKME);

    }
    wxButton* GetEventButton() const { return m_button_ShowLabel1; };
    int RenderState(const wxString& message);
    int ShowText(const wxString& message);

private:
    wxStaticText* m_Label1;
    wxButton*     m_button_ShowLabel1;

    // void Panel_1::OnMyButtonClicked(wxCommandEvent& event)
    void OnMyButtonClicked(wxCommandEvent& event)
    {
        // Put whatever you want your app to do when the button is pressed
        // For example, change the text of our label:
        m_Label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");

        // internet_connection->SendData();

    };
};
int Panel_1::RenderState(const wxString& message) 
{
    this->ShowText(message);
    this->Layout();
    return 0;
};
int Panel_1::ShowText(const wxString& message) 
{
    // this.m_Label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");
    this->m_Label1->SetLabel(message);
    this->Layout();
    return 0;
};


// Panel_2.h
class Panel_2 : public wxPanel {
public:
    Panel_2(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        // FUNCTIONALITY 2
        m_label_get_IP  = new wxStaticText(this, wxID_ANY, "Result: (IP of server)", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
        m_button_get_IP = new wxButton(this, ID_BUTTON_GETIP, "Get IP", wxDefaultPosition, wxSize(200, 40));

        sizer->Add(m_label_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        sizer->Add(m_button_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

        
        SetSizer(sizer);
  
        // Привязываем события внутри этого же класса
        // m_btnOpen->Bind(wxEVT_BUTTON, &SidebarPanel::OnOpenPressed, this);
        // m_button_get_IP->Bind(wxEVT_BUTTON, &Panel_2::OnMyButtonGetIP, this, ID_BUTTON_GETIP);
    };

    wxButton* GetEventButton() const { return m_button_get_IP; };

private:
    wxStaticText* m_label_get_IP;
    wxButton*     m_button_get_IP;

    void OnMyButtonGetIP(wxCommandEvent& event)
    {
        // Put whatever you want your app to do when the button is pressed
        // For example, change the text of our label:
        // m_label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");

        // internet_connection->Get_IP();
        // internet_connection->CloseConnection();

        std::cout << "OnMyButtonGetIP." << std::endl;

    };
};


// Panel_3.h
class Panel_3 : public wxPanel {
public:
    Panel_3(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        // FUNCTIONALITY 2
        m_label_get_IP  = new wxStaticText(this, wxID_ANY, "Result: (IP of server)", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
        m_button_get_IP = new wxButton(this, ID_BUTTON_GETIP, "Get IP", wxDefaultPosition, wxSize(200, 40));

        sizer->Add(m_button_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        sizer->Add(m_label_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        
        SetSizer(sizer);
  
        // Привязываем события внутри этого же класса
        // m_btnOpen->Bind(wxEVT_BUTTON, &SidebarPanel::OnOpenPressed, this);
        m_button_get_IP->Bind(wxEVT_BUTTON, &Panel_3::OnMyButtonGetIP, this, ID_BUTTON_GETIP);
    }

private:
    wxStaticText* m_label_get_IP;
    wxButton*     m_button_get_IP;

    void OnMyButtonGetIP(wxCommandEvent& event)
    {
        // Put whatever you want your app to do when the button is pressed
        // For example, change the text of our label:
        // m_label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");

        // internet_connection->Get_IP();
        // internet_connection->CloseConnection();

        std::cout << "OnMyButtonGetIP." << std::endl;

    };
};
















































// // SidebarPanel.h
// class SidebarPanel : public wxPanel {
// public:
//     SidebarPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
//         wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        
//         m_btnOpen = new wxButton(this, wxID_ANY, "Открыть");
//         m_btnSave = new wxButton(this, wxID_ANY, "Сохранить");
        
//         sizer->Add(m_btnOpen, 0, wxALL | wxEXPAND, 5);
//         sizer->Add(m_btnSave, 0, wxALL | wxEXPAND, 5);
        
//         SetSizer(sizer);
        
//         // Привязываем события внутри этого же класса
//         m_btnOpen->Bind(wxEVT_BUTTON, &SidebarPanel::OnOpenPressed, this);
//     }

// private:
//     wxButton* m_btnOpen;
//     wxButton* m_btnSave;

//     void OnOpenPressed(wxCommandEvent& event) {
//         // Логика кнопки "Открыть" инкапсулирована здесь
//     }
// };





// // RenderCanvas.h
// class RenderCanvas : public wxPanel {
// public:
//     RenderCanvas(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
//         SetBackgroundColour(*wxBLACK);
//         Bind(wxEVT_PAINT, &RenderCanvas::OnPaint, this);
//     }
// private:
//     void OnPaint(wxPaintEvent& event) {
//         wxPaintDC dc(this);
//         // Тут логика рисования
//     }
// };