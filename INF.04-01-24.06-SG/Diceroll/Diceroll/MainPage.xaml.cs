using System;
using Microsoft.Maui.Controls;

namespace Diceroll
{
    public partial class MainPage : ContentPage
    {
        private int gameResult = 0;
        private Random random = new Random();

        public MainPage()
        {
            InitializeComponent();
        }

        private void OnRollDiceClicked(object sender, EventArgs e)
        {
            int[] diceValues = new int[5];
            int rollResult = 0;

            for (int i = 0; i < 5; i++)
            {
                diceValues[i] = random.Next(1, 7);
                rollResult += diceValues[i];
            }

            Dice1.Source = $"dice{diceValues[0]}.png";
            Dice2.Source = $"dice{diceValues[1]}.png";
            Dice3.Source = $"dice{diceValues[2]}.png";
            Dice4.Source = $"dice{diceValues[3]}.png";
            Dice5.Source = $"dice{diceValues[4]}.png";

            RollResultLabel.Text = $"Wynik tego losowania: {rollResult}";
            gameResult += rollResult;
            GameResultLabel.Text = $"Wynik gry: {gameResult}";
        }

        private void OnResetClicked(object sender, EventArgs e)
        {
            Dice1.Source = "question.jpg";
            Dice2.Source = "question.jpg";
            Dice3.Source = "question.jpg";
            Dice4.Source = "question.jpg";
            Dice5.Source = "question.jpg";

            RollResultLabel.Text = "Wynik tego losowania: 0";
            GameResultLabel.Text = "Wynik gry: 0";
            gameResult = 0;
        }
    }
}
