// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"

#include <windows.storage.h>
#include <microsoft.ui.xaml.window.h>
#include "Question.h"
namespace muxc
{
    using namespace winrt::Microsoft::UI::Xaml::Controls;
};

namespace wuxc
{
    using namespace winrt::Windows::UI::Xaml::Controls;
};

namespace winrt::LittleGame_SmartestMen::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        
        int32_t MyProperty();
        void MyProperty(int32_t value);

        double NavViewCompactModeThresholdWidth();
        void ContentFrame_NavigationFailed(
            Windows::Foundation::IInspectable const& /* sender */,
            Microsoft::UI::Xaml::Navigation::NavigationFailedEventArgs const& args);
        void NavView_Loaded(
            Windows::Foundation::IInspectable const& /* sender */, Microsoft::UI::Xaml::RoutedEventArgs const &  /* args */);
        void NavView_ItemInvoked(
            Windows::Foundation::IInspectable const& /* sender */, muxc::NavigationViewItemInvokedEventArgs const & args);

        // NavView_SelectionChanged is not used in this example, but is shown for completeness.
        // You'll typically handle either ItemInvoked or SelectionChanged to perform navigation,
        // but not both.
        void NavView_SelectionChanged(
            muxc::NavigationView const& /* sender */, muxc::NavigationViewSelectionChangedEventArgs const & args);
        void NavView_Navigate(
            std::wstring navItemTag, Microsoft::UI::Xaml::Media::Animation::NavigationTransitionInfo const & transitionInfo);
        void NavView_BackRequested(
            muxc::NavigationView const& /* sender */,
            muxc::NavigationViewBackRequestedEventArgs const& /* args */);
        void On_Navigated(
            Windows::Foundation::IInspectable const& /* sender */, Microsoft::UI::Xaml::Navigation::NavigationEventArgs const & args);
        void CoreDispatcher_AcceleratorKeyActivated(
            Windows::UI::Core::CoreDispatcher const& /* sender */,
            Windows::UI::Core::AcceleratorKeyEventArgs const& args);
        void CoreWindow_PointerPressed(
            Windows::UI::Core::CoreWindow const& /* sender */,
            Windows::UI::Core::PointerEventArgs const& args);
        void System_BackRequested(
            Windows::Foundation::IInspectable const& /* sender */,
            Windows::UI::Core::BackRequestedEventArgs const& args);
        bool TryGoBack();
private:
        // Vector of std::pair holding the Navigation Tag and the relative Navigation Page.
        std::vector<std::pair<std::wstring, Windows::UI::Xaml::Interop::TypeName>> m_pages;
    };
}

namespace winrt::LittleGame_SmartestMen::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
