using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime;

class DiagonalDifference
{
    static int diagonalDifference(int[][] a)
    {
        // Complete this function
        var primaryDiaganol = 0;
        var secondayDiagonal = 0;

        for(int r = 0; r < a.Length; r ++)
        {
            secondayDiagonal += a[r][a.Length - 1 - r];
            primaryDiaganol += a[r][r];
        }
        return Math.Abs(primaryDiaganol-secondayDiagonal);
    }

    static void Main(String[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        int[][] a = new int[n][];
        for (int a_i = 0; a_i < n; a_i++)
        {
            string[] a_temp = Console.ReadLine().Split(' ');
            a[a_i] = a_temp.Select(Int32.Parse).ToArray();
        }
        int result = diagonalDifference(a);
        Console.WriteLine(result);
        Console.ReadKey();
    }
}
