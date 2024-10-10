using System.Collections.ObjectModel;

namespace INF._04_02_23._01_SG_mobileapp
{
    public partial class MainPage : ContentPage
    {

        private ObservableCollection<string> notes;

        public MainPage()
        {
            InitializeComponent();


            notes = new ObservableCollection<string>
            {
                "Notatka 1",
                "Notatka 2",
                "Notatka 3"
            };


            NotesListView.ItemsSource = notes;
        }


        private void OnAddButtonClicked(object sender, EventArgs e)
        {

            notes.Add(NewItemEntry.Text);


            NewItemEntry.Text = string.Empty;
        }
    }

}
