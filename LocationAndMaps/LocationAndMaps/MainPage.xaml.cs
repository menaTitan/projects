/*
 Name:Mena Sergyous
 * Date:4/30/2015
 * lab 12
 
 
 
 
 */




using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Devices.Geolocation;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=391641

namespace LocationAndMaps
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();

            this.NavigationCacheMode = NavigationCacheMode.Required;
        }

        /// <summary>
        /// Invoked when this page is about to be displayed in a Frame.
        /// </summary>
        /// <param name="e">Event data that describes how this page was reached.
        /// This parameter is typically used to configure the page.</param>
        protected async override void OnNavigatedTo(NavigationEventArgs e)
        {
            MyMap.Style = Windows.UI.Xaml.Controls.Maps.MapStyle.Aerial;
            var golfCourse = new Windows.Devices.Geolocation.BasicGeoposition();
            golfCourse.Latitude = 35.851182;
            golfCourse.Longitude = -86.413273;

            var mypos = new Windows.Devices.Geolocation.Geopoint(golfCourse);
            if (await MyMap.TrySetViewAsync(mypos, 15D)) { ;}
            mySlider.Value = MyMap.ZoomLevel;

        }

        private void getPositionButton_Click(object sender, RoutedEventArgs e)
        {
          positionTextBlock.Text = String.Format("{0}, {1}",
              MyMap.Center.Position.Latitude,
              MyMap.Center.Position.Longitude);
        }

        private async void setPositionButton_Click(object sender, RoutedEventArgs e)
        {


           
            //var myPosition = new Windows.Devices.Geolocation.BasicGeoposition();

            //double lati;
            //double longi;
            ////if (double.TryParse(latitude.Text, out lati))
            ////{
            ////    myPosition.Latitude = lati;
            ////};

            ////if (double.TryParse(longitude.Text, out longi))
            ////{
            ////    myPosition.Longitude = longi;
            ////}

            //MyMap.Style = MapStyle.Aerial;
            //MyMap.Heading = 180.0;


            //myPosition.Latitude = 35.852585;
            //myPosition.Longitude = -86.414831;
            //var myPoint = new Windows.Devices.Geolocation.Geopoint(myPosition);

            //await MyMap.TrySetViewAsync(myPoint, 18D);


        }
        private async void Hole1_Click(object sender, RoutedEventArgs e)
        {
            var hole_1 = new Windows.Devices.Geolocation.BasicGeoposition();
            hole_1.Latitude = 35.851949;
            hole_1.Longitude = -86.414097;
            MyMap.Heading = 144;
            var mypos = new Windows.Devices.Geolocation.Geopoint(hole_1);
            if (await MyMap.TrySetViewAsync(mypos, 17.5D)) { ;}
            mySlider.Value = MyMap.ZoomLevel;
            var location = new Geolocator();
            location.DesiredAccuracyInMeters = 1;
            var position = await location.GetGeopositionAsync();
            double lat = (position.Coordinate.Latitude) * Math.PI / 180;
            double longi = (position.Coordinate.Longitude) * Math.PI / 180;
            double latB = (hole_1.Latitude) * Math.PI / 180;
            double LongiB = (hole_1.Longitude) * Math.PI / 180;
            double latEND = (lat - latB);
            double longiEND = (longi - LongiB);
            double x = Math.Cos(lat) * Math.Sin(latB) - Math.Sin(lat) * Math.Cos(latB) * Math.Cos(longiEND);
            double y = Math.Sin(longiEND) * Math.Cos(latB);
            double hdg = 0;
            if (y > 0)
            {
                if (x > 0) { hdg = Math.Atan(y / x); }
                if (x < 0) { hdg = 180 - Math.Atan(-y / x); }
                if (x == 0) { hdg = 90; }
            }
            if (y < 0)
            {
                if (x > 0) { hdg = -Math.Atan(-y / x); }
                if (x < 0) { hdg = Math.Atan(y / x); }
                if (x == 0) { hdg = 270; }
            }
            if (y == 0)
            {
                if (x > 0) { hdg = 0; }
                if (x < 0) { hdg = 180; }
            }
            hdg = Convert.ToInt32(hdg * 180 / Math.PI) % 360;
            positionTextBlock.Text = String.Format("{0}, {1}",
                MyMap.Center.Position.Latitude,
                MyMap.Center.Position.Longitude);
            double dest = 0;
            dest = (Math.Sin((latB - lat) / 2) * Math.Sin((latB - lat) / 2)) + (Math.Cos(lat) * Math.Cos(latB) * Math.Sin((LongiB - longi) / 2) * Math.Sin((LongiB - longi) / 2));
            dest = 2 * Math.Atan2(Math.Sqrt(dest), Math.Sqrt(1 - dest));
            dest = dest * 63710000;
            dest = Convert.ToInt32(dest * 1.09361);
            positionTextBlock.Text = "Current place: " + position.Coordinate.Latitude.ToString() + " " + position.Coordinate.Longitude.ToString() + "\nTo hole: " +
                hdg.ToString() + " degrees, " + dest.ToString() + " yards.";
        }




        private async void Hole2_Click(object sender, RoutedEventArgs e)
        {
            var hole_3 = new Windows.Devices.Geolocation.BasicGeoposition();
            hole_3.Latitude = 35.847709;
            hole_3.Longitude = -86.414191;
            MyMap.Heading = 358;
            var mypos = new Windows.Devices.Geolocation.Geopoint(hole_3);
            if (await MyMap.TrySetViewAsync(mypos, 17.5D)) { ;}
            mySlider.Value = MyMap.ZoomLevel;
            var location = new Geolocator();
            location.DesiredAccuracyInMeters = 1;
            var position = await location.GetGeopositionAsync();
            double lat = (position.Coordinate.Latitude) * Math.PI / 180;
            double longi = (position.Coordinate.Longitude) * Math.PI / 180;
            double latB = (hole_3.Latitude) * Math.PI / 180;
            double LongiB = (hole_3.Longitude) * Math.PI / 180;
            double latEND = (lat - latB);
            double longiEND = (longi - LongiB);
            double x = Math.Cos(lat) * Math.Sin(latB) - Math.Sin(lat) * Math.Cos(latB) * Math.Cos(longiEND);
            double y = Math.Sin(longiEND) * Math.Cos(latB);
            double hdg = 0;
            if (y > 0)
            {
                if (x > 0) { hdg = Math.Atan(y / x); }
                if (x < 0) { hdg = 180 - Math.Atan(-y / x); }
                if (x == 0) { hdg = 90; }
            }
            if (y < 0)
            {
                if (x > 0) { hdg = -Math.Atan(-y / x); }
                if (x < 0) { hdg = Math.Atan(y / x) - 180; }
                if (x == 0) { hdg = 270; }
            }
            if (y == 0)
            {
                if (x > 0) { hdg = 0; }
                if (x < 0) { hdg = 180; }
            }
            hdg = Convert.ToInt32(hdg * 180 / Math.PI) % 360;
            positionTextBlock.Text = String.Format("{0}, {1}",
                MyMap.Center.Position.Latitude,
                MyMap.Center.Position.Longitude);
            double dest = 0;
            dest = (Math.Sin((latB - lat) / 2) * Math.Sin((latB - lat) / 2)) + (Math.Cos(lat) * Math.Cos(latB) * Math.Sin((LongiB - longi) / 2) * Math.Sin((LongiB - longi) / 2));
            dest = 2 * Math.Atan2(Math.Sqrt(dest), Math.Sqrt(1 - dest));
            dest = dest * 63710000;
            dest = Convert.ToInt32(dest * 1.09361);
            positionTextBlock.Text = "Current place: " + position.Coordinate.Latitude.ToString() + " " + position.Coordinate.Longitude.ToString() + "\nTo hole: " +
                hdg.ToString() + " degrees, " + dest.ToString() + " yards.";

        }

        private void Slider_ValueChanged(object sender, RangeBaseValueChangedEventArgs e)
        {
          if (MyMap != null)
            MyMap.ZoomLevel = e.NewValue;
        }
    }
}
