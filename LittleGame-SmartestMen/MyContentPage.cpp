#include "pch.h"
#include "MyContentPage.h"
#if __has_include("MyContentPage.g.cpp")
#include "MyContentPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::LittleGame_SmartestMen::implementation
{
    int32_t MyContentPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MyContentPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MyContentPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
