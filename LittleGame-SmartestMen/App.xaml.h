// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "App.xaml.g.h"

namespace winrt::LittleGame_SmartestMen::implementation
{
    struct App : AppT<App>
    {
        App();

        Microsoft::UI::Xaml::Controls::Frame CreateRootFrame();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);
        void OnNavigationFailed(IInspectable const&, Microsoft::UI::Xaml::Navigation::NavigationFailedEventArgs const&);

        winrt::Microsoft::UI::Xaml::Window Window() { return window; };

    private:
        winrt::Microsoft::UI::Xaml::Window window;
    };
}
