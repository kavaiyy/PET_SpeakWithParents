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



MyFrame::MyFrame() 
    : wxFrame(nullptr, wxID_ANY, "Модульное приложение", wxDefaultPosition, wxSize(800, 600)) 
{
    // Главный контейнер всего окна
    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);

    // Просто создаем наши кастомные компоненты, передавая 'this' как родителя
    m_panel1 = new Panel_1(this);
    m_panel2 = new Panel_2(this);

    // Компонуем их: сайдбар фиксированный (0), холст растягивается на весь экран (1)
    mainSizer->Add(m_panel1, 0, wxEXPAND | wxRIGHT, 2);
    mainSizer->Add(m_panel2, 1, wxEXPAND);

    SetSizer(mainSizer);
}


// Panel_1.h
class Panel_1 : public wxPanel {
public:
    Panel_1(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        
        m_Label1  = new wxStaticText(this, wxID_ANY, "Waiting for action...", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
        m_button_ShowLabel1 = new wxButton(this, ID_BUTTON_CLICKME, "Click Me", wxDefaultPosition, wxSize(200, 40));
        
        sizer->Add(m_button_show_label1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        sizer->Add(m_label1, 0, wxALL | wxEXPAND, 20);
        
        SetSizer(sizer);
        
        // Привязываем события внутри этого же класса
        // m_btnOpen->Bind(wxEVT_BUTTON, &SidebarPanel::OnOpenPressed, this);
        m_button_ShowLabel1->Bind(wxEVT_BUTTON, &Panel_1::OnMyButtonClicked, this, ID_BUTTON_CLICKME);

    }

private:
    wxStaticText* m_Label1;
    wxButton*     m_button_ShowLabel1;

    // ----------------------------------------------------------------
    // FUNCTIONALITY 1:
    // ----------------------------------------------------------------
    void Panel_1::OnMyButtonClicked(wxCommandEvent& event)
    {
        // Put whatever you want your app to do when the button is pressed
        // For example, change the text of our label:
        m_label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");

        // internet_connection->SendData();

    };
};


// Panel_2.h
class Panel_2 : public wxPanel {
public:
    Panel_2(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        // FUNCTIONALITY 2
        m_label_get_IP  = new wxStaticText(this, wxID_ANY, "Result: (IP of server)", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
        m_button_get_IP = new wxButton(this, ID_BUTTON_GETIP, "Get IP", wxDefaultPosition, wxSize(200, 40));

        sizer->Add(m_button_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        sizer->Add(m_label_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        
        SetSizer(sizer);
  
        // Привязываем события внутри этого же класса
        // m_btnOpen->Bind(wxEVT_BUTTON, &SidebarPanel::OnOpenPressed, this);
        m_button_get_IP->Bind(wxEVT_BUTTON, &Panel_2::OnMyButtonClicked, this, ID_BUTTON_CLICKME);
    }

private:
    wxStaticText* m_label_get_IP;
    wxButton*     m_button_get_IP;

    // ----------------------------------------------------------------
    // FUNCTIONALITY 2:
    // ----------------------------------------------------------------
    void Panel_2::OnMyButtonGetIP(wxCommandEvent& event)
    {
        // Put whatever you want your app to do when the button is pressed
        // For example, change the text of our label:
        // m_label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");

        // internet_connection->Get_IP();
        // internet_connection->CloseConnection();

        std::cout << "OnMyButtonGetIP." << std::endl;

    };

};


















// SidebarPanel.h
class SidebarPanel : public wxPanel {
public:
    SidebarPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        
        m_btnOpen = new wxButton(this, wxID_ANY, "Открыть");
        m_btnSave = new wxButton(this, wxID_ANY, "Сохранить");
        
        sizer->Add(m_btnOpen, 0, wxALL | wxEXPAND, 5);
        sizer->Add(m_btnSave, 0, wxALL | wxEXPAND, 5);
        
        SetSizer(sizer);
        
        // Привязываем события внутри этого же класса
        m_btnOpen->Bind(wxEVT_BUTTON, &SidebarPanel::OnOpenPressed, this);
    }

private:
    wxButton* m_btnOpen;
    wxButton* m_btnSave;

    void OnOpenPressed(wxCommandEvent& event) {
        // Логика кнопки "Открыть" инкапсулирована здесь
    }
};





// RenderCanvas.h
class RenderCanvas : public wxPanel {
public:
    RenderCanvas(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        SetBackgroundColour(*wxBLACK);
        Bind(wxEVT_PAINT, &RenderCanvas::OnPaint, this);
    }
private:
    void OnPaint(wxPaintEvent& event) {
        wxPaintDC dc(this);
        // Тут логика рисования
    }
};