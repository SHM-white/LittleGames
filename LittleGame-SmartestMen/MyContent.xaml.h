// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MyContent.g.h"

namespace winrt::LittleGame_SmartestMen::implementation
{
    struct MyContent : MyContentT<MyContent>
    {
        MyContent();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::LittleGame_SmartestMen::factory_implementation
{
    struct MyContent : MyContentT<MyContent, implementation::MyContent>
    {
    };
}
