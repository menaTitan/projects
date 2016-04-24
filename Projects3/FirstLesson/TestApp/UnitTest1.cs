using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace TestApp
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            FirstLesson.MathOperataions.Double(10);
        }
        [TestMethod]
        public void TestMethod2()
        {

            Assert.AreEqual(20, FirstLesson.MathOperataions.Double(10));
        }
       
    }
}
