// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MyContent.xaml.h"
#if __has_include("MyContent.g.cpp")
#include "MyContent.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::LittleGame_SmartestMen::implementation
{
    MyContent::MyContent()
    {
        InitializeComponent();
    }

    int32_t MyContent::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MyContent::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MyContent::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
