using System;
using System.Drawing;
using AForge.Imaging;
using AForge;
namespace aforge_client
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.WriteLine ("Hello World!");
			Bitmap image = AForge.Imaging.Image.FromFile("test.png");
		}
	}
}
