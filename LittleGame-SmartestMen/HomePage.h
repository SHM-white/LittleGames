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

        
    };
}

namespace winrt::LittleGame_SmartestMen::factory_implementation
{
    struct HomePage : HomePageT<HomePage, implementation::HomePage>
    {
    };
}
