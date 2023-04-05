#pragma once

#include "MyContentPage.g.h"

namespace winrt::LittleGame_SmartestMen::implementation
{
    struct MyContentPage : MyContentPageT<MyContentPage>
    {
        MyContentPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::LittleGame_SmartestMen::factory_implementation
{
    struct MyContentPage : MyContentPageT<MyContentPage, implementation::MyContentPage>
    {
    };
}
