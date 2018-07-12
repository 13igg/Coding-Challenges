using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class PlusMinus
{

    static void plusMinus(int[] arr)
    {
        // Complete this function
        var positiveCount = 0M;
        var negativeCount = 0M;
        var zeroCount = 0M;
        foreach (var num in arr)
        {
            if (num == 0) zeroCount += 1;
            else if (num > 0) positiveCount += 1;
            else negativeCount += 1;
        }
        Console.WriteLine(positiveCount / arr.Length);
        Console.WriteLine(negativeCount / arr.Length);
        Console.WriteLine(zeroCount / arr.Length);
    }

    static void Main(String[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] arr_temp = Console.ReadLine().Split(' ');
        var arr = arr_temp.Select(Int32.Parse).ToArray();
        plusMinus(arr);
    }
}
