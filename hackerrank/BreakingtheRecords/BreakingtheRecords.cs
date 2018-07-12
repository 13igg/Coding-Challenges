using System;
using System.Linq;
namespace BreakingtheRecords
{
    class BreakingtheRecords
    {
        static int[] breakingRecords(int[] score)
        {
            /*
             * Write your code here.
             */
            int max = -1;
            int min = -1;
            int maxCount = -1;
            int minCount = -1;
            foreach(var scor in score)
            {
                if (scor > max)
                {
                    max = scor;
                    maxCount++;
                }
                else if (scor < min)
                {
                    min = scor;
                    minCount++;
                }
            }
            return new int[] { maxCount, minCount };
        }
        static void Main(string[] args)
        {
            Console.Write(string.Join("\n", breakingRecords(new int[] { 3, 4, 21, 36, 10, 28, 35, 5, 24, 42 })));
           // Console.Write(string.Join("\n", breakingRecords(new int[] { 10 ,5 ,20 ,20 ,4 ,5 ,2 ,25 ,1 })));
            
            Console.ReadLine();
        }
    }
}