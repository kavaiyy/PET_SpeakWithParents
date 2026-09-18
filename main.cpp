#include "MyFrame.h"

// #include <iostream>
// #include <cstring>
// #include <unistd.h>
// #include <arpa/inet.h>
// #include <sys/socket.h>


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



// [wxFrame (Главное окно)]
//    └── [wxPanel (Главная подложка)]
//           ├── [wxStaticText (Подсказка)]
//           ├── [wxTextCtrl (Поле ввода)]
//           ├── [wxButton (Кнопка)]
//           └── [wxStaticText (Вывод результата)]


// g++ -Wall -Wextra -Wshadow main.cpp -o server : сокрытием имён (name shadowing)