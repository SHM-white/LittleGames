// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace SmartestMan_C_Test
{
    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();
            // Get the window handle (HWND) of the current window
            var windowHandle = WinRT.Interop.WindowNative.GetWindowHandle(this);

            // Set the window location and size
            var dpi = PInvoke.User32.GetDpiForWindow(windowHandle);
            var scale = dpi / 96.0;
            var x = (int)(100 * scale);
            var y = (int)(100 * scale);
            var width = (int)(800 * scale);
            var height = (int)(600 * scale);
            PInvoke.User32.SetWindowPos(windowHandle, IntPtr.Zero, x, y, width, height, PInvoke.User32.SetWindowPosFlags.SWP_NOZORDER);

            // Disable the window minimize and maximize buttons
            var style = PInvoke.User32.GetWindowLong(windowHandle, PInvoke.User32.WindowLongIndexFlags.GWL_STYLE);
            style &= ~(PInvoke.User32.WindowStyles.WS_MINIMIZEBOX | PInvoke.User32.WindowStyles.WS_MAXIMIZEBOX);
            PInvoke.User32.SetWindowLong(windowHandle, PInvoke.User32.WindowLongIndexFlags.GWL_STYLE, style);
        }

        private void myButton_Click(object sender, RoutedEventArgs e)
        {
            myButton.Content = "Clicked";
        }
    }
}
