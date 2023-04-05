// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "Home.xaml.h"
#if __has_include("Home.g.cpp")
#include "Home.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::LittleGame_SmartestMen::implementation
{
    Home::Home()
    {
        InitializeComponent();
    }

    int32_t Home::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Home::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
    int Home::HighestScore(int score)
    {
        static int highestInHistory;
        highestInHistory = max(highestInHistory, score);
        return highestInHistory;
    }

    void Home::Update()
    {
        timeCounter().Text(to_hstring(question.TickRun(0)));
        score().Text(to_hstring(currentScore));
        highestScoreInHistory().Text(to_hstring(HighestScore(currentScore)));

    }

    void Home::endGame()
    {
        questionBox().Text(to_hstring(L"游戏结束"));
        currentScore = 0;
        Update();

    }
    void Home::OnTick(winrt::Windows::Foundation::IInspectable const& sender, Windows::Foundation::IInspectable const& e)
    {
        if (!question.TickRun(50)) {
            endGame();
        }
        Update();

    }

    void Home::buttonYes_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        button_Click(true);
    }

    void Home::buttonNo_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        button_Click(false);
    }

    void Home::button_Click(bool answer)
    {
        if (question.TickRun(0) && question.isCorrect(answer)) {
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

}
