// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "Home.g.h"
#include "Question.h"

namespace winrt::LittleGame_SmartestMen::implementation
{
    struct Home : HomeT<Home>
    {
        Home();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        int highestScore{ 0 };
        int currentScore{ 0 };
        Question question{ 9 };

        int HighestScore(int score);
        void Update();
        void endGame();
        void OnTick(winrt::Windows::Foundation::IInspectable const& sender, Windows::Foundation::IInspectable const& e);
        void buttonYes_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void buttonNo_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void button_Click(bool answer);
    };
}

namespace winrt::LittleGame_SmartestMen::factory_implementation
{
    struct Home : HomeT<Home, implementation::Home>
    {
    };
}
