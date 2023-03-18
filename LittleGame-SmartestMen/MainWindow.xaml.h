// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"

#include <microsoft.ui.xaml.window.h>
#include "Question.h"

namespace winrt::LittleGame_SmartestMen::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        
        int highestScore{ 0 };
        int currentScore{ 0 };
        Question question{ 9 };

        int32_t MyProperty();
        int HighestScore(int score);
        void Update();
        void endGame();
        void MyProperty(int32_t value);
        void OnTick(winrt::Windows::Foundation::IInspectable const& sender, Windows::Foundation::IInspectable const& e);
        void buttonYes_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void buttonNo_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::LittleGame_SmartestMen::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
