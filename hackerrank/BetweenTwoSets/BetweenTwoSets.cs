using System;
using System.Collections.Generic;
using System.Linq;
namespace BetweenTwoSets
{
    class BetweenTwoSets
    {
        static int getTotalX(int[] a, int[] b)
        {
            var c = new List<int>();
            var d = new List<int>();

            //find all the factors for each of the numbers in a then add them to a list
            for (var a_i = 0; a_i < a.Length; a_i++)
            {
                for (var i = a[a_i]; i <= b.Min(); i += a[a_i])
                {
                    if (i % a[a_i] == 0)
                        c.Add(i);
                }                             
            }
            //clean that list by taking only the ones that are factors for each of the values in a
            c = c.GroupBy(x => x).Where(g => g.Count() == a.Length).Select(g => g.Key).ToList();

            //IF c is divisible by b, add it
            for (var c_i = 0; c_i < c.Count; c_i++)
            {
                for (var b_i = 0; b_i < b.Length; b_i++)
                {
                    if (b[b_i] % c[c_i] == 0)
                        d.Add(c[c_i]);
                }
            }
            
            //Clean the list by grouping and seeing if D was divisible by all values of b
            d = d.GroupBy(x => x).Where(g => g.Count() == b.Length).Select(g => g.Key).ToList();
            return d.Count();
        }

        static void Main(string[] args)
        {            
            Console.Write(getTotalX(new int[] { 2, 4, 8}, new int[] { 16, 32, 96}));
            Console.ReadKey();
        }

        //clean java solution -- stolen from website
        //Arrays.sort(a);
        //Arrays.sort(b);

        //int lower_bound = a[n - 1];
        //        int upper_bound = b[0];

        //        int count_x = 0;
        //for(int i = lower_bound; i <= upper_bound; i++){
        //    int sum_mod = 0;
        //    for(int j = 0; j<n; j++){
        //        sum_mod += i % a[j];
        //    }
        //    for(int k = 0; k<m; k++){
        //        sum_mod += b[k] % i;
        //    }

        //    if(sum_mod == 0)
        //        ++count_x;
        //}

        //System.out.print(count_x);
    }
}