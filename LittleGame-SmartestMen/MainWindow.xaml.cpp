// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#include <winrt/Microsoft.UI.Xaml.h>
#include <fstream>

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
        DispatcherTimer recoTimer;

        recoTimer = DispatcherTimer();
        recoTimer.Interval(std::chrono::milliseconds{ 50 });
        auto registrationtoken = recoTimer.Tick({ this, &MainWindow::OnTick });
        recoTimer.Start();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    int MainWindow::HighestScore(int score)
    {
        //Windows::Storage::ApplicationDataContainer localSettings{ Windows::Storage::ApplicationData::Current().LocalSettings()};
        //auto values{ localSettings.Values()};
        static int highestInHistory;

        //
        //// Read data from a simple setting.
        //winrt::hstring value{ winrt::unbox_value<winrt::hstring>(values.Lookup(L"exampleSetting")) };
        //highestInHistory = max(atoi((char*)value.c_str()), highestInHistory);

        //Windows::Storage::ApplicationDataContainer container{
        //    localSettings.CreateContainer(L"highestScore", Windows::Storage::ApplicationDataCreateDisposition::Always) 
        //};
        //bool hasContainer{ localSettings.Containers().HasKey(L"highestScore") };
        //bool hasSetting{ false };

        //if (hasContainer)
        //{
        //    auto values{ localSettings.Containers().Lookup(L"highestScore").Values() };
        //    hasSetting = values.HasKey(L"score");

        //}
        highestInHistory = max(highestInHistory, score);
        //values.Insert(L"score", Windows::Foundation::PropertyValue::CreateString(to_hstring(highestInHistory)));

        return highestInHistory;
    }

    void MainWindow::Update()
    {
        timeCounter().Text(to_hstring(question.TickRun(0)));
        score().Text(to_hstring(currentScore));
        highestScoreInHistory().Text(to_hstring(HighestScore(currentScore)));
    }

    void MainWindow::endGame()
    {
        questionBox().Text(to_hstring("游戏结束"));
        currentScore = 0;
        Update();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
    void MainWindow::OnTick(winrt::Windows::Foundation::IInspectable const& sender, Windows::Foundation::IInspectable const& e)
    {
        if (!question.TickRun(50)) {
            endGame();
        }
        Update();
    }

    
}


void winrt::LittleGame_SmartestMen::implementation::MainWindow::buttonYes_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (question.TickRun(0)&&question.isCorrect(true)) {
        currentScore += question.m_score;
        question.newQuestion();
        questionBox().Text(to_hstring(question.getQuestion()));
        Update();
    }
    else if (!question.TickRun(0)){
        question.newQuestion();
        questionBox().Text(to_hstring(question.getQuestion()));
        Update();
    }
    else {
        question.TickRun(100000);
        endGame();
    }
}


void winrt::LittleGame_SmartestMen::implementation::MainWindow::buttonNo_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (question.TickRun(0) && question.isCorrect(false)) {
        currentScore += question.m_score;
        question.newQuestion();
        questionBox().Text(to_hstring(question.getQuestion()));
        Update();
    }
    else if (!question.TickRun(0)) {
        question.newQuestion();
        questionBox().Text(to_hstring(question.getQuestion()));
        Update();
    }
    else {
        question.TickRun(100000);
        endGame();
    }

}
