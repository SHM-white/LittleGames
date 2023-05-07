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
using static SmartestMan_C_Test.Question;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace SmartestMan_C_Test
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        public int HighestScore(int score)
        {

            highestInHistory = highestInHistory > score ? highestInHistory:score ;
            return highestInHistory;
        }
        public void Update()
        {
            timeCounter.Text= question.TickRun(0);
            score().Text(to_hstring(currentScore));
            highestScoreInHistory().Text(to_hstring(HighestScore(currentScore)));

        }

        public int highestScore { get; set; }
        public int currentScore { get; set; }
        public Question question;
        private int highestInHistory { get;set; }

    }
}
