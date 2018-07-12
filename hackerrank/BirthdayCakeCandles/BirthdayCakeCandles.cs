using System;
using System.Linq;
namespace BirthdayCakeCandles
{
    class BirthdayCakeCandles
    {
        static int birthdayCakeCandles(int n, int[] ar)
        {
            // Complete this function
            var max = ar.Max();
            return ar.Count(x => x == max);
        }

        static void Main(String[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            string[] ar_temp = Console.ReadLine().Split(' ');
            int[] ar = arr_temp.Select(Int32.Parse).ToArray();
            int result = birthdayCakeCandles(n, ar);
            Console.WriteLine(result);
        }
    }
}