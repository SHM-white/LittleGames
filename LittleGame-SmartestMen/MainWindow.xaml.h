// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"

#include <windows.storage.h>
#include <microsoft.ui.xaml.window.h>
#include "Question.h"

namespace winrt::LittleGame_SmartestMen::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        
        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::LittleGame_SmartestMen::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
