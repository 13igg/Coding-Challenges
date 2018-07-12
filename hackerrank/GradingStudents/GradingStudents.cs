using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GradingStudents
{
    class GradingStudents
    {
        static int[] gradingStudents(int[] grades)
        {
            int[] outputGrades = new int[grades.Length];
            for(int i = 0; i < grades.Length; i++)
            {
                var grade = grades[i];
                if (grade < 38) { continue; }

                if (grade % 5 == 3)
                    grades[i] += 2; 
                else if (grade % 5 == 4)
                    grades[i] += 1;
            }
            return grades;
        }

        static void Main(string[] args)
        {
            int[] grades = {73,
                            67,
                            38,
                            33 };

            int[] result = gradingStudents(grades);

            Console.WriteLine(string.Join("\n", result));
            Console.ReadKey();
        }
    }
}