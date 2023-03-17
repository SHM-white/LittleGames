// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#include <winrt/Microsoft.UI.Xaml.h>

#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::LittleGame_SmartestMen::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        recoTimer = DispatcherTimer();
        recoTimer.Interval(std::chrono::milliseconds{ 500 });
        auto registrationtoken = recoTimer.Tick({ this, &MainWindow::OnTick });
        recoTimer.Start();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
    void MainWindow::OnTick(winrt::Windows::Foundation::IInspectable const& sender, Windows::Foundation::IInspectable const& e)
    {

    }

    
}


void winrt::LittleGame_SmartestMen::implementation::MainWindow::buttonYes_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{

}


void winrt::LittleGame_SmartestMen::implementation::MainWindow::buttonNo_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{

}
