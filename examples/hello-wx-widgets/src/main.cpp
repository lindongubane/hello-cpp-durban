#include <utility>
#include <wx/wx.h>

wxAppConsole* createApp()
{
    wxAppConsole::CheckBuildOptions(WX_BUILD_OPTIONS_SIGNATURE,
                                        "Hello wxWidgets");
    return new wxApp();
}

wxMenuBar* createMenuBar()
{
    auto *menuFile = new wxMenu();
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    auto *menuHelp = new wxMenu();
    menuHelp->Append(wxID_ABOUT);

    auto *menuBar = new wxMenuBar();
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    return menuBar;
}

template<typename Callback>
wxButton* bindEvent(wxButton* button, Callback&& callback)
{
    button->Bind(wxEVT_BUTTON, std::forward<Callback>(callback));
    return button;
}

int main(int argc, char *argv[])
{
    wxApp::SetInitializerFunction(createApp);
    wxEntryStart(argc, argv);
    auto* app = wxApp::GetInstance();
    app->CallOnInit();

    auto* frame = new wxFrame(nullptr, wxID_ANY, "Hello wxWidgets - C++ Durban");

    frame->SetMenuBar(createMenuBar());

    frame->CreateStatusBar();
    frame->SetStatusText("Welcome to C++ Durban!");

    frame->Bind(wxEVT_MENU, [](auto& event)
    {
        wxMessageBox("This is a wxWidgets Hello World example",
                     "About Hello wxWidgets", wxOK | wxICON_INFORMATION);
    }, wxID_ABOUT);

    frame->Bind(wxEVT_MENU, [frame](auto &event)
    {
        frame->Close(true);
    }, wxID_EXIT);

    // Add our buttons in a vertical sizer to give people some useful links.
    auto *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(bindEvent(new wxButton(frame, -1, "Click me!"), [](auto &event)
    {
        wxLaunchDefaultBrowser("https://www.destroyallsoftware.com/talks/wat");
    }), 1, wxEXPAND, 0);

    sizer->Add(bindEvent(new wxButton(frame, -1, "Don't Click me!"), [](auto &event)
    {
        wxLaunchDefaultBrowser("https://rickrolled.com/");
    }), 1, wxEXPAND, 0);

    sizer->SetSizeHints(frame);
    frame->SetSizer(sizer);

    frame->SetSize(640, 480);
    frame->Show(true);

    app->OnRun();
    return 0;
}