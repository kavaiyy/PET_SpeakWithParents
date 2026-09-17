// #include <wx/wx.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

// #include <iostream>
// #include <cstring>
// #include <unistd.h>
// #include <arpa/inet.h>
// #include <sys/socket.h>


#include "MySocket.h"

#include "server.h"

// ============================================================================
// 1. CHOOSE AN ID FOR THE BUTTON
// ============================================================================
const int ID_BUTTON_CLICKME = 101;
const int ID_BUTTON_GETIP   = 102;

// ============================================================================
// 2. THE MAIN WINDOW INTERFACE
// ============================================================================
class MyFrame : public wxFrame
{
private:
    SocketConnection* internet_connection;
    ServerManager* myServer;

    // FUNCTIONALITY 1:
    wxStaticText* m_label1;
    wxButton* m_button_show_label1;
    void OnMyButtonClicked(wxCommandEvent& event);

    // FUNCTIONALITY 2:
    wxButton* m_button_get_IP;
    wxStaticText* m_label_get_IP;
    void OnMyButtonGetIP(wxCommandEvent& event);

    // FUNCTIONALITY 3: input text field, with pressing on enter:
    wxTextCtrl* m_textInput;     // Указатели на элементы интерфейса (нужны для доступа к ним в обработчиках)
    wxStaticText* m_textDisplay;

    // Обработчики событий
    void OnSubmitPressed(wxCommandEvent& event);
    void OnEnterPressed(wxCommandEvent& event);

    // Единый метод для обработки введенного текста
    void ProcessSubmittedText();


    // Event Handler callbacks
    void OnHello(wxCommandEvent& event)
    {
        int buff_OnHello = 3;
        buff_OnHello = buff_OnHello + 1;
    };
    void OnExit(wxCommandEvent& event)
    {
        internet_connection->CloseConnection();
        internet_connection->~SocketConnection();
        myServer->~ServerManager();
        Close(true);
    };







public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Basic wxWidgets GUI App", wxPoint(50, 50), wxSize(400, 250))
    {
        // Layout manager to handle auto-positioning and resizing
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        wxPanel* panel = new wxPanel(this, wxID_ANY);



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


// -------------------------------------
        // FUNCTIONALITY 3

        // 1. Метка-подсказка
        wxBoxSizer* PanelSizer = new wxBoxSizer(wxVERTICAL);
        wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Введите текст:");
        PanelSizer->Add(label, 0, wxALL | wxALIGN_LEFT, 10);

        // 2. Поле ввода текста (wxTextCtrl)
        // Флаг wxTE_PROCESS_ENTER критически важен, чтобы работало нажатие Enter!
        m_textInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
        PanelSizer->Add(m_textInput, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

        // 3. Кнопка отправки
        wxButton* submitButton = new wxButton(panel, wxID_ANY, "Отправить");
        PanelSizer->Add(submitButton, 0, wxALL | wxALIGN_CENTER, 10);

        panel->SetSizer(PanelSizer);

        // ============================================================================
        // ДИНАМИЧЕСКОЕ СВЯЗЫВАНИЕ СОБЫТИЙ (BINDING)
        // ============================================================================
        
        // Привязка нажатия на кнопку
        submitButton->Bind(wxEVT_BUTTON, &MyFrame::OnSubmitPressed, this);
        
        // Привязка нажатия Enter внутри текстового поля
        m_textInput->Bind(wxEVT_TEXT_ENTER, &MyFrame::OnEnterPressed, this);
// -------------------------------------



        this->SetSizer(sizer);
        this->Layout();

        // Connect the button event to our custom logic handler
        Bind(wxEVT_BUTTON, &MyFrame::OnMyButtonClicked, this, ID_BUTTON_CLICKME);
        Bind(wxEVT_BUTTON, &MyFrame::OnMyButtonGetIP, this, ID_BUTTON_GETIP);


        internet_connection = new SocketConnection();
        myServer = new ServerManager();
    }
};














// ----------------------------------------------------------------
// FUNCTIONALITY 1:
// ----------------------------------------------------------------
void MyFrame::OnMyButtonClicked(wxCommandEvent& event)
{
    // Put whatever you want your app to do when the button is pressed
    // For example, change the text of our label:
    m_label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");

    internet_connection->SendData();


};

// ----------------------------------------------------------------
// FUNCTIONALITY 2:
// ----------------------------------------------------------------
void MyFrame::OnMyButtonGetIP(wxCommandEvent& event)
{
    // Put whatever you want your app to do when the button is pressed
    // For example, change the text of our label:
    // m_label1->SetLabel("Hello! Your custom wxWidgets code ran adfdfa.");

    internet_connection->Get_IP();
    // internet_connection->CloseConnection();

};

// ----------------------------------------------------------------
// FUNCTIONALITY 3: input text field, with pressing on enter
// ----------------------------------------------------------------
// Обработчики событий
void MyFrame::OnSubmitPressed(wxCommandEvent& event)
{
    int i;
    i = 1;
};
void MyFrame::OnEnterPressed(wxCommandEvent& event)
{
    int i;
    i = 1;
};
// Единый метод для обработки введенного текста
void MyFrame::ProcessSubmittedText() 
{
    int i;
    i = 1;
};


// // Вспомогательная бизнес-логика
// void MyFrame::ProcessSubmittedText() {
//     // Получаем текст из поля ввода
//     wxString userText = m_textInput->GetValue();

//     if (userText.IsEmpty()) {
//         wxMessageBox("Пожалуйста, введите хоть какой-нибудь текст!", "Предупреждение", wxOK | wxICON_WARNING);
//         return;
//     }

//     // Выводим текст в интерфейс приложения
//     m_textDisplay->SetLabel("Вы ввели: " + userText);

//     // Очищаем поле ввода и возвращаем на него фокус для следующего ввода
//     m_textInput->Clear();
//     m_textInput->SetFocus();
// }

// // Обработчик для кнопки
// void MyFrame::OnSubmitPressed(wxCommandEvent& event) {
//     ProcessSubmittedText();
// }

// // Обработчик для клавиши Enter
// void MyFrame::OnEnterPressed(wxCommandEvent& event) {
//     ProcessSubmittedText();
// }







// [wxFrame (Главное окно)]
//    └── [wxPanel (Главная подложка)]
//           ├── [wxStaticText (Подсказка)]
//           ├── [wxTextCtrl (Поле ввода)]
//           ├── [wxButton (Кнопка)]
//           └── [wxStaticText (Вывод результата)]









// ============================================================================
// 1. THE APPLICATION INTERFACE
// =======================================================================
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