using System;
using Android.App;
using Android.Content;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using Android.OS;
using System.Collections.Generic;

namespace App1
{
    [Activity(Label = "App1", MainLauncher = true, Icon = "@drawable/icon")]
    public class MainActivity : Activity
    {
        int count = 1;
        private List<string> mItems;
       // private ListView myListView;
        protected override void OnCreate(Bundle bundle)
        {
            base.OnCreate(bundle);

            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.Main);
            var view = FindViewById<ListView>(Resource.Id.myListView);
            mItems = new List<string>();
            mItems.Add("Bob");
            mItems.Add("Tom");
            mItems.Add("Tim");

            myListViewAdapter adapter = new myListViewAdapter(this, mItems);
            view.Adapter = adapter;
           
            // Get our button from the layout resource,
            // and attach an event to it
           // Button button = FindViewById<Button>(Resource.Id.MyButton);


            //button.Click += delegate { button.Text = string.Format("{0} clicks!", count++); };

        }
    }
}

