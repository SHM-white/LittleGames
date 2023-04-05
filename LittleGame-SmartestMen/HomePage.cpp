#include "pch.h"
#include "HomePage.h"
#if __has_include("HomePage.g.cpp")
#include "HomePage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::LittleGame_SmartestMen::implementation
{
    int32_t HomePage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    int HomePage::HighestScore(int score)
    {
        static int highestInHistory;
        highestInHistory = max(highestInHistory, score);
        return highestInHistory;
    }

    void HomePage::Update()
    {
        timeCounter().Text(to_hstring(question.TickRun(0)));
        score().Text(to_hstring(currentScore));
        highestScoreInHistory().Text(to_hstring(HighestScore(currentScore)));

    }

    void HomePage::endGame()
    {
        questionBox().Text(to_hstring(L"游戏结束"));
        currentScore = 0;
        Update();

    }

    void HomePage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void HomePage::OnTick(winrt::Windows::Foundation::IInspectable const& sender, Windows::Foundation::IInspectable const& e)
    {
        if (!question.TickRun(50)) {
            endGame();
        }
        Update();

    }

    void HomePage::buttonYes_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        button_Click(true);
    }

    void HomePage::buttonNo_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        button_Click(false);
    }

    void HomePage::button_Click(bool answer)
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
