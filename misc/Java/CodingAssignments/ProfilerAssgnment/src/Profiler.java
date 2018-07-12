import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: Matt
 * Date: 4/7/13
 * Time: 7:18 PM
 * To change this template use File | Settings | File Templates.
 */
public class Profiler {
    private boolean isEnabled = true;
    private static Profiler instance = null;

    private ArrayList<ProfileTimer> times;
    private HashMap<String, ArrayList<ProfileTimer>> timerHashMap = new HashMap<String,ArrayList<ProfileTimer>>();

    private HashMap<String, Integer> countHashMap = new HashMap<String,Integer>();

    private String timeElapsed;
    private int hour,minute,second,millisecond,
            hourAverage,minuteAverage,secondAverage,millisecondAverage,
            longestHour,longestMinute,longestSecond,longestMillisecond,
            shortestHour,shortestMinute,shortestSecond,shortestMillisecond;

    /**
    * singleton ensure that a calls only has 1instance
    * this 1 instance holds all the difference timers
    * global point of access to it.
    * private constructor
    **/
    private Profiler() {
    }

    /**
     * Public constructor to return the profiler
     * returns the instance of the profiler
     *
     **/
    public static Profiler getInstance()
    {
        if(instance == null)
            instance = new Profiler();
        return instance;
    }

    /**start the timer
     *
     */
    public void start(String identifier)
    {
       if(isEnabled)
            if(!timerHashMap.containsKey(identifier))
            {
                times = new ArrayList<ProfileTimer>();
               // System.out.println(identifier + ": " + " Started");
                times.add(new ProfileTimer(identifier));
                timerHashMap.put(identifier, times);
            }

            else if(timerHashMap.containsKey(identifier) && timerHashMap.get(identifier).get(timerHashMap.get(identifier).size() - 1).getStop() != null )  //contains
            {
                times = timerHashMap.get(identifier);
               // System.out.println(identifier + ": " + " Started");
                times.add(new ProfileTimer(identifier));
            } //if it contains the key and a stop already exists then

            else if(timerHashMap.get(identifier).get(timerHashMap.get(identifier).size() - 1).getStart() != null) //if a start exists without a stop, prevent another start from occuring
            {
                times = new ArrayList<ProfileTimer>();
                System.out.println("ALREADY STARTED");
            }
    }
    public void start(String identifier, String message)
    {
        if(isEnabled)
            if(!timerHashMap.containsKey(identifier))  //if a start exists without a stop, prevent another start from occuring
            {
                times = new ArrayList<ProfileTimer>();
               // System.out.println(identifier + ": " + " Started" + " Message: " + message);
                times.add(new ProfileTimer(identifier, message));
                timerHashMap.put(identifier, times);
            }
            else if(timerHashMap.containsKey(identifier) && timerHashMap.get(identifier).get(timerHashMap.get(identifier).size() - 1).getStop() != null )  //contains
            {
                times = timerHashMap.get(identifier);
               // System.out.println(identifier + ": " + " Started" + " Message: " + message);
                times.add(new ProfileTimer(identifier,message));
            } //if it contains the key and a stop already exists then
            else if(timerHashMap.get(identifier).get(timerHashMap.get(identifier).size() - 1).getStart() != null) {
                times = new ArrayList<ProfileTimer>();
                System.out.println("ALREADY STARTED");   }
    }

    /**stop the timer
     *
     */
    public void stop(String identifier)
    {
        if(isEnabled)
            if(timerHashMap.containsKey(identifier) && (timerHashMap.get(identifier).get(timerHashMap.get(identifier).size() - 1).getStop()) == null)
            {
               // System.out.println(identifier + ": " + " Stopped");
                timerHashMap.get(identifier).get(timerHashMap.get(identifier).size() - 1).setStop(new GregorianCalendar());
            }
            else
                System.out.println("stopped timer does not exist, or has already been stopped");
    }
    public void stop(String identifier, String message )
    {
        if(isEnabled)
            if(timerHashMap.containsKey(identifier) && (timerHashMap.get(identifier).get(timerHashMap.get(identifier).size() - 1).getStop()) == null)
            {
               // System.out.println(identifier + ": " + " Stopped" + " Message: " + message);
                timerHashMap.get(identifier).get(timerHashMap.get(identifier).size() - 1).setStop(new GregorianCalendar());
                timerHashMap.get(identifier).get(timerHashMap.get(identifier).size() - 1).setMessage(message);
            }
            else
                System.out.println("stopped timer does not exist, or has already been stopped");
    }

    public void setInfo(String s, int j)
    {
                                  //current - start time
                hour        = timerHashMap.get(s).get(j).getStop().get(Calendar.HOUR)        - timerHashMap.get(s).get(j).getStart().get(Calendar.HOUR);
                minute      = timerHashMap.get(s).get(j).getStop().get(Calendar.MINUTE)      - timerHashMap.get(s).get(j).getStart().get(Calendar.MINUTE);
                second      = timerHashMap.get(s).get(j).getStop().get(Calendar.SECOND)      - timerHashMap.get(s).get(j).getStart().get(Calendar.SECOND);
                millisecond = timerHashMap.get(s).get(j).getStop().get(Calendar.MILLISECOND) - timerHashMap.get(s).get(j).getStart().get(Calendar.MILLISECOND);
                //System.out.println(millisecond);
                timeElapsed = "";
                //WILL GET NEGATIVE NUMBERS IF
                if(millisecond<0)
                {
                    millisecond = 1000+millisecond;
                    second --;
                }
                if(second<0)
                {
                    second=60+second;
                    minute--;
                }
                if(minute<0)
                {
                    minute=60+minute;
                    hour--;
                }
                if(hour<10)
                    timeElapsed+="0";
                timeElapsed += hour+":";
                if(minute<10)
                    timeElapsed+="0";
                timeElapsed += +minute+":";
                if(second<10)
                    timeElapsed+="0";
                timeElapsed += second+":";
                if(millisecond<10)
                    timeElapsed+="0";
                timeElapsed += millisecond;

    }

    /**count the num of times the selection of code has been run
     *
     */
    public void count(String identifier)
    {
        if(!countHashMap.containsKey(identifier))  //if a count is calles that hasnt been created yet
        {                         //put it back in and remove the previous one
            // counter starts at 0 for this identifer)
            countHashMap.put(identifier, 1);  //adds the calendar
        }
        else//if the counter already exists, add 1 to it
            countHashMap.put(identifier, countHashMap.get(identifier)+1);  //adds the counter
    }

    /**controlls wether or not the timer is enabled
     *
     */
    public void setEnabled(boolean isEnabled)
    {
        this.isEnabled = isEnabled;
    }


    private String htmlHeadder;
    private String htmlText;
    private String htmlCloser;
    public void generateReport()
    {
        htmlHeadder = "<html><head><title>Timer Report</title></head><body>";
        htmlCloser = "</body></html>";
        htmlText = htmlHeadder;

        for (String s : timerHashMap.keySet())
        {
            setInfo(s,0);
            //sets the shortest - to the first 1 which will be changed further down and resets the others
            shortestHour = hour;
            shortestMinute = minute;
            shortestSecond  = second;
            shortestMillisecond  = millisecond;

            hourAverage = 0;
            minuteAverage = 0;
            secondAverage  = 0;
            millisecondAverage  = 0;

            longestHour = 0;
            longestMinute = 0;
            longestSecond  = 0;
            longestMillisecond  = 0;

            for(int j = 0; j < timerHashMap.get(s).size() && timerHashMap.get(s).get(j).getStop() != null ; j +=1)
            {
                setInfo(s,j);
                if(hour>longestHour || minute>longestMinute || second>longestSecond || millisecond>longestMillisecond)
                {
                    longestHour = hour;
                    longestMinute = minute;
                    longestSecond  = second;
                    longestMillisecond  = millisecond;
                }
                if(shortestHour>hour || shortestMinute>minute || shortestSecond>second || shortestMillisecond>millisecond)
                {
                    shortestHour = hour;
                    shortestMinute = minute;
                    shortestSecond  = second;
                    shortestMillisecond  = millisecond;
                }
                hourAverage += hour;
                minuteAverage += minute;
                secondAverage += second;
                millisecondAverage += millisecond;
            }
            hourAverage /= timerHashMap.get(s).size();
            minuteAverage /= timerHashMap.get(s).size();
            secondAverage /= timerHashMap.get(s).size();
            millisecondAverage /= timerHashMap.get(s).size();


            //adds the title
            htmlText+="<p>" +
                        "<font size=\"7\">"
                            + s + " Stats " +
                        "</font>" +
                      "</p>";
            //adds the headders for the table
            htmlText+="<table border=\"1\">\n" +
                        "<tr>\n" +
                            "<th></th>\n" +
                            "<th>Hour</th>\n" +
                            "<th>Minutes</th>\n" +
                            "<th>Seconds</th>\n" +
                            "<th>Milliseconds</th>\n" +
                         "</tr>";
            htmlText += "<tr>\n" +
                             "<td>Average</td>\n" +
                             "<td>"+hourAverage+"</td>\n" +
                             "<td>"+minuteAverage+"</td>\n" +
                             "<td>"+secondAverage+"</td>\n" +
                             "<td>"+millisecondAverage+"</td>\n" +
                        "</tr>" +
                        "<tr>\n" +
                             "<td>Longest</td>\n" +
                             "<td>"+longestHour+"</td>\n" +
                             "<td>"+longestMinute+"</td>\n" +
                             "<td>"+longestSecond+"</td>\n" +
                             "<td>"+longestMillisecond+"</td>\n" +
                        "</tr>" +
                        "<tr>\n" +
                             "<td>Shortest</td>\n" +
                             "<td>"+shortestHour+"</td>\n" +
                             "<td>"+shortestMinute+"</td>\n" +
                             "<td>"+shortestSecond+"</td>\n" +
                             "<td>"+shortestMillisecond+"</td>\n" +
                        "</tr>";
            for(int j = 0; j < timerHashMap.get(s).size() && timerHashMap.get(s).get(j).getStop() != null ; j +=1)
            {
                setInfo(s,j);
                String message;
                if(timerHashMap.get(s).get(j).getMessage() == "")
                    message = "Run: "+(j+1);
                else
                    message = timerHashMap.get(s).get(j).getMessage();
                htmlText +=  "<tr>\n" +
                                "<td>"+message+"</td>\n" +
                                "<td>"+hour+"</td>\n" +
                                "<td>"+minute+"</td>\n" +
                                "<td>"+second+"</td>\n" +
                                "<td>"+millisecond+"</td>\n" +
                             "</tr>";

            }
            htmlText+="</table><br></br>";
        }


        //title for counters
        htmlText+="<p>" +
                "<font size=\"7\">"
                + "Counters" + " Stats " +
                "</font>" +
                "</p>";
        //table for Counters
        htmlText+="<table border=\"1\">\n" +
                "<tr>\n" +
                "<th>Label</th>\n" +
                "<th>Count</th>\n" +
                "</tr>";
        for (String s : countHashMap.keySet())
        {
            htmlText +="<tr>\n" +
                            "<td>"+s+"</td>\n" +
                            "<td>"+countHashMap.get(s)+"</td>\n" +
                       "</tr>";//number of time run
        }

        htmlText+="</table><br></br>";//closes counte table

        htmlText += htmlCloser;
        writeToFile(1,htmlText);
    }
    public void writeToFile(int fileNum, String pT)
    {
        try
        {
            String num = Integer.toString(fileNum);
            String link = "C:\\Users\\Matt\\Desktop\\TimerInfo";
            File file = new File(link + fileNum + ".HTML");
            // if file doesnt exists, then create it
            if (!file.exists())
                file.createNewFile();
            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            BufferedWriter bw = new BufferedWriter(fw);

            bw.write(pT);
            bw.close();
            System.out.println("File written to .HTML file");
        }
        catch (IOException e){
            e.printStackTrace();}
    }

    class ProfileTimer {
        private Calendar start,stop;
        private String identifier,message;
        public ProfileTimer(String identifier)
        {
            this.start = new GregorianCalendar();
            this.stop = null;
            this.identifier = identifier;
            this.message = "";
        }
        public ProfileTimer(String identifier, String message)
        {
            this.start = new GregorianCalendar();
            this.stop = null;
            this.identifier = identifier;
            this.message = message;
        }

        String getIdentifier() {
            return identifier;
        }

        void setIdentifier(String identifier) {
            this.identifier = identifier;
        }

        String getMessage() {
            return message;
        }

        void setMessage(String message) {
            this.message = message;
        }

        Calendar getStart() {
            return start;
        }

        void setStart(Calendar start) {
            this.start = start;
        }

        Calendar getStop() {
            return stop;
        }

        void setStop(Calendar stop) {
            this.stop = stop;
        }
    }

}
