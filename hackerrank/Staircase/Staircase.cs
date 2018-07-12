using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

class Staircase
{
    static void staircase(int n)
    {
        //for(int r = 0; r < n; r ++)
        //{
        //    for (int c = 1; c <= n; c ++)
        //    {
        //        if (n - c <= r) Console.Write('#');
        //        else Console.Write(' ');
        //    }
        //    Console.WriteLine();
        //}

        //Optimized
        for (int i = 1; i <= n; i++)
        {
            Console.WriteLine(new String(' ', n - i) + new String('#', i));
        }
    }

    static void Main(String[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        staircase(n);
    }
}