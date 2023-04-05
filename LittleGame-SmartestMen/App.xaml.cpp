// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"

#include "App.xaml.h"
#include "Home.xaml.h"
#include "MainWindow.xaml.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace LittleGame_SmartestMen;
using namespace LittleGame_SmartestMen::implementation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App()
{
    InitializeComponent();

   /* DispatcherTimer recoTimer;

    recoTimer = DispatcherTimer();
    recoTimer.Interval(std::chrono::milliseconds{ 50 });
    auto registrationtoken = recoTimer.Tick({ this, &Home::OnTick });
    recoTimer.Start();*/
    window.Activate();
#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
    {
        if (IsDebuggerPresent())
        {
            auto errorMessage = e.Message();
            __debugbreak();
        }
    });
#endif
}

Microsoft::UI::Xaml::Controls::Frame winrt::LittleGame_SmartestMen::implementation::App::CreateRootFrame()
{
    Frame rootFrame{ nullptr };
    auto content = window.Content();
    if (content)
    {
        rootFrame = content.try_as<Frame>();
    }

    // Don't repeat app initialization when the Window already has content,
    // just ensure that the window is active
    if (!rootFrame)
    {
        // Create a Frame to act as the navigation context
        rootFrame = Frame();

        rootFrame.NavigationFailed({ this, &App::OnNavigationFailed });

        // Place the frame in the current Window
        window.Content(rootFrame);
    }

    return rootFrame;

    //return Microsoft::UI::Xaml::Controls::Frame();
}

/// <summary>
/// Invoked when the application is launched.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(LaunchActivatedEventArgs const&)
{
    window = make<MainWindow>();
    Frame rootFrame = CreateRootFrame();

    if (!rootFrame.Content())
    {
        rootFrame.Navigate(xaml_typename<LittleGame_SmartestMen::Home>());
    }
    
}

void winrt::LittleGame_SmartestMen::implementation::App::OnNavigationFailed(IInspectable const&, Microsoft::UI::Xaml::Navigation::NavigationFailedEventArgs const& e)
{
    throw hresult_error(E_FAIL, hstring(L"Failed to load Page ") + e.SourcePageType().Name);
}
