// #include <wx/wx.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <iostream>
#include <cstring>
#include <unistd.h>



// #include "MySocket.h"
// #include "server.h"


// ============================================================================
// 1. CHOOSE AN ID FOR THE BUTTON
// ============================================================================
const int ID_BUTTON_CLICKME = 101;
const int ID_BUTTON_GETIP   = 102;






// Panel_1.h
class Panel_1 : public wxPanel {
public:
    Panel_1(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        m_Label1  = new wxStaticText(this, wxID_ANY, "Waiting for action...", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
        sizer->Add(m_Label1, 0, wxALL | wxEXPAND, 20);

        m_button_ShowLabel1 = new wxButton(this, ID_BUTTON_CLICKME, "Click Me", wxDefaultPosition, wxSize(200, 40));
        sizer->Add(m_button_ShowLabel1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

        SetSizer(sizer);
        
        // Привязываем события внутри этого же класса
        // m_btnOpen->Bind(wxEVT_BUTTON, &SidebarPanel::OnOpenPressed, this);
        // m_button_ShowLabel1->Bind(wxEVT_BUTTON, &Panel_1::OnMyButtonClicked, this, ID_BUTTON_CLICKME);

    };
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
        sizer->Add(m_label_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        
        m_button_get_IP = new wxButton(this, ID_BUTTON_GETIP, "Get IP", wxDefaultPosition, wxSize(200, 40));
        sizer->Add(m_button_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

        SetSizer(sizer);

    };

    wxButton* GetEventButton() const { return m_button_get_IP; };

private:
    wxStaticText* m_label_get_IP;
    wxButton*     m_button_get_IP;

    void OnMyButtonGetIP(wxCommandEvent& event)
    {
        std::cout << "OnMyButtonGetIP." << std::endl;
    };
};

// Panel_3.h
class Panel_3 : public wxPanel {
public:
    Panel_3(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        wxBoxSizer* PanelSizer = new wxBoxSizer(wxVERTICAL);

        // FUNCTIONALITY 3
        // 1. Метка-подсказка
        // m_label_1 = new wxStaticText(this, wxID_ANY, "Enter text:");
        // m_label_1 = new wxStaticText(this, wxID_ANY, _("Введите текст:"));
        m_label_1 = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("Введите текст:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
        PanelSizer->Add(m_label_1, 0, wxALL | wxALIGN_LEFT, 10);

        // 2. Поле ввода текста (wxTextCtrl)
        // Флаг wxTE_PROCESS_ENTER критически важен, чтобы работало нажатие Enter! 
        m_textInput = new wxTextCtrl(this, wxID_ANY, wxString::FromUTF8("some text"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
        PanelSizer->Add(m_textInput, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
        // m_textInput->Bind(wxEVT_TEXT_ENTER, &MyFrame::OnEnterPressed, this);

        // 3. Кнопка отправки
        m_submitButton = new wxButton(this, wxID_ANY, wxString::FromUTF8("Ввести"),wxDefaultPosition, wxSize(200, 40) );
        PanelSizer->Add(m_submitButton, 0, wxALL | wxALIGN_CENTER, 10);
        // m_submitButton->Bind(wxEVT_BUTTON, &MyFrame::OnSubmitPressed, this);

        SetSizer(PanelSizer);
        this->Layout();
    };

    wxButton*   GetEventButton()    const { return m_submitButton; };
    wxTextCtrl* GetEventTextInput() const { return m_textInput;    };

private:
    wxStaticText* m_label_1;
    wxTextCtrl*   m_textInput;
    wxButton*     m_submitButton;

    void OnMyButtonSubmit(wxCommandEvent& event)
    {
        std::cout << "OnMyButtonSubmit." << std::endl;
    };
};


// // Для кнопок и статического текста
// myButton->SetLabel(wxString::FromUTF8("Новый текст на кириллице"));
// // Для текстовых полей (wxTextCtrl)
// myTextCtrl->SetValue(wxString::FromUTF8("Введенный текст"));

















// public:
//     MyFrame() : wxFrame(nullptr, wxID_ANY, "Basic wxWidgets GUI App", wxPoint(50, 50), wxSize(400, 250))
//     {
//         // Layout manager to handle auto-positioning and resizing
//         wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
//         wxPanel* panel = new wxPanel(this, wxID_ANY);



//         // FUNCTIONALITY 1
//         m_label1             = new wxStaticText(this, wxID_ANY, "Waiting for action...", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
//         m_button_show_label1 = new wxButton(this, ID_BUTTON_CLICKME, "Click Me", wxDefaultPosition, wxSize(200, 40));
//         sizer->Add(m_button_show_label1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
//         sizer->Add(m_label1, 0, wxALL | wxEXPAND, 20);
        
//         // FUNCTIONALITY 2
//         m_button_get_IP = new wxButton(this, ID_BUTTON_GETIP, "Get IP", wxDefaultPosition, wxSize(200, 40));
//         m_label_get_IP  = new wxStaticText(this, wxID_ANY, "Result: (IP of server)", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
//         sizer->Add(m_button_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
//         sizer->Add(m_label_get_IP, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);


// // -------------------------------------
//         // FUNCTIONALITY 3

//         // 1. Метка-подсказка
//         wxBoxSizer* PanelSizer = new wxBoxSizer(wxVERTICAL);
//         wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Введите текст:");
//         PanelSizer->Add(label, 0, wxALL | wxALIGN_LEFT, 10);

//         // 2. Поле ввода текста (wxTextCtrl)
//         // Флаг wxTE_PROCESS_ENTER критически важен, чтобы работало нажатие Enter!
//         m_textInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
//         PanelSizer->Add(m_textInput, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

//         // 3. Кнопка отправки
//         wxButton* submitButton = new wxButton(panel, wxID_ANY, "Отправить");
//         PanelSizer->Add(submitButton, 0, wxALL | wxALIGN_CENTER, 10);

//         panel->SetSizer(PanelSizer);

//         // ============================================================================
//         // ДИНАМИЧЕСКОЕ СВЯЗЫВАНИЕ СОБЫТИЙ (BINDING)
//         // ============================================================================
        
//         // Привязка нажатия на кнопку
//         submitButton->Bind(wxEVT_BUTTON, &MyFrame::OnSubmitPressed, this);
        
//         // Привязка нажатия Enter внутри текстового поля
//         m_textInput->Bind(wxEVT_TEXT_ENTER, &MyFrame::OnEnterPressed, this);
// // -------------------------------------



//         this->SetSizer(sizer);
//         this->Layout();

//         // Connect the button event to our custom logic handler
//         Bind(wxEVT_BUTTON, &MyFrame::OnMyButtonClicked, this, ID_BUTTON_CLICKME);
//         Bind(wxEVT_BUTTON, &MyFrame::OnMyButtonGetIP, this, ID_BUTTON_GETIP);



//     }
// };







































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