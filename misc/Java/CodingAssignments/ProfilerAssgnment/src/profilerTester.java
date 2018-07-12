import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 * Created with IntelliJ IDEA.
 * User: Matt
 * Date: 4/7/13
 * Time: 7:34 PM
 * To change this template use File | Settings | File Templates.
 */
public class profilerTester {
    public static void main(String[] args) {

    //start the Profiler
            //Profiler.getInstance().start("test timer");

    //do something interesting here

    //start another Profiler
        //Profiler.getInstance().start("test timer2");

       // Profiler.getInstance().start("test timer2");
    //count the code timer
        Profiler.getInstance().start("Timer2");

        Profiler.getInstance().count("test");
        Profiler.getInstance().stop("Timer2");
        for(int i = 0;i < 10;i++)
        {
            Profiler.getInstance().start("Timer1", "Iteration: "+ i);
            //do something interesting here
            Profiler.getInstance().count("inside the foo() method");
            Profiler.getInstance().count("test");

            for(int j = 0; j < 1000; j ++)
            {
                System.out.print("");
                if(j%2 == 0)
                    for(int k = 0; k < j*i; k ++)
                      System.out.print("");

            }
            Profiler.getInstance().stop("Timer1" , "Iteration: "+i );
        }


        Profiler.getInstance().generateReport();
    }
}
