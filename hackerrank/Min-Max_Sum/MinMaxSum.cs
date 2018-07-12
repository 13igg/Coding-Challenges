using System;
using System.Linq;

class MMinMaxSum
{
    static void miniMaxSum(int[] arr)
    {
        //// Complete this function
        //long min = 0;
        //long max = 0;
        //for(int i = 0; i < arr.Length; i ++)
        //{
        //    long runningCount = 0;
        //    for (int j = 0; j < arr.Length; j ++)
        //    {
        //        //we will skip I each time
        //        if(j != i)
        //        {
        //            runningCount += arr[j];
        //        }                
        //    }
        //    if (runningCount > max)
        //        max = runningCount;
        //    if (runningCount < min || min == 0)
        //        min = runningCount;
        //}
        //Console.Write(min + " " + max);

        //Optimized
        long sum = 0;
        for (int i = 0; i < arr.Length; i++)
        {
            sum += arr[i];
        }
        Console.WriteLine("{0} {1}", sum - arr.Max(), sum - arr.Min());
    }

    static void Main(String[] args)
    {
        string[] arr_temp = Console.ReadLine().Split(' ');
        int[] arr = arr_temp.Select(Int32.Parse).ToArray();
        miniMaxSum(arr);
    }
}