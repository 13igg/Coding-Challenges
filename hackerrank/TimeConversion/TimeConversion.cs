using System;
using System.Linq;
namespace TimeConversion
{
    class TimeConversion
    {
        static string timeConversion(string s)
        {
            // Complete this function
            var timeArr = s.Split(':');
            var hh = int.Parse(timeArr[0]);

            if (s.Substring(8, 2) == "AM")
            {
                return (hh == 12 ? "00" : hh.ToString()) + ":" +
                    (String.Join(":", timeArr.Skip(1))
                     .Substring(0, 5));
            }
            else
            {
                if (hh == 12) hh = 0;
                return (hh + 12 + 
                        ":" + 
                        String.Join(":", timeArr.Skip(1))
                        .Substring(0, 5));
            }
        }

        static void Main(String[] args)
        {
            string s = Console.ReadLine();
            string result = timeConversion(s);
            Console.WriteLine(result);
            Console.ReadKey();
        }
    }
}