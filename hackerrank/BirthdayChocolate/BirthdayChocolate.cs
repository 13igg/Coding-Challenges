using System;

namespace BirthdayChocolate
{
    class BirthdayChocolate
    {
        static int solve(int n, int[] s, int d, int m)
        {
            int count = 0;
            if (n == 1 && m == 1)
                if (s[0] != d)
                    return 0;
                else
                    return 1;
            
            //m squares summing to d
            for(int i = 0; i < n-m; i ++)
            {
                int sum = 0;
                for(int j = i; j < i+m; j++)
                {
                    sum += s[j];

                    if (sum > d)
                        continue;
                    else if(sum == d)
                        count++;
                }

                
            }
            return count;
            // Complete this function
        }
        static void Main(string[] args)
        {
            // int result = solve(6, new int[] { 1, 1, 1, 1, 1, 1 }, 3, 2);
            // int result = solve(5, new int[] { 1, 2, 1, 3, 2}, 3, 2);
            // int result = solve(1, new int[] { 4 }, 4, 1);
             int result = solve(2, new int[] { 2, 2 }, 4, 2);

            Console.WriteLine(result);
            Console.ReadKey();
        }
    }
}