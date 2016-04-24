using System;
using Android.App;
using Android.Content;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using Android.OS;

namespace intent
{
    [Activity(Label = "intent", MainLauncher = true, Icon = "@drawable/icon")]
    public class MainActivity : Activity
    {
        int count = 1;

        protected override void OnCreate(Bundle bundle)
        {
            base.OnCreate(bundle);

            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.Main);

            // Get our button from the layout resource,
            // and attach an event to it
            Button button = FindViewById<Button>(Resource.Id.MyButton);

           

            button.Click += (sender, args) =>
            {
                var uri = Android.Net.Uri.Parse("http://cs.mtsu.edu/~mks4q");
                var intent = new Intent(Intent.ActionView, uri);
                StartActivity(intent);
            };
        }
    }
}

