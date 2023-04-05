#pragma once

#include "HomePage.g.h"

#include <windows.storage.h>
#include <microsoft.ui.xaml.window.h>
#include "Question.h"


namespace winrt::LittleGame_SmartestMen::implementation
{
    struct HomePage : HomePageT<HomePage>
    {
        HomePage() 
        {
            
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();

        int highestScore{ 0 };
        int currentScore{ 0 };
        Question question{ 9 };

        int HighestScore(int score);
        void Update();
        void endGame();
        void MyProperty(int32_t value);
        void OnTick(winrt::Windows::Foundation::IInspectable const& sender, Windows::Foundation::IInspectable const& e);
        void buttonYes_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void buttonNo_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void button_Click(bool answer);
    };
}

namespace winrt::LittleGame_SmartestMen::factory_implementation
{
    struct HomePage : HomePageT<HomePage, implementation::HomePage>
    {
    };
}
