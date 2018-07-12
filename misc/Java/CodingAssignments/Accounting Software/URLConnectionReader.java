import java.net.*;
import java.io.*;

public class URLConnectionReader {
public static void main(String[] args) throws Exception {
String stocks = "GOOG"; //
    URL yahoofinance = new URL("http://finance.yahoo.com/d/quotes.csv?s="+stocks+"&f=l1");
    URLConnection yc = yahoofinance.openConnection();
    BufferedReader in = new BufferedReader(new InputStreamReader(yc.getInputStream()));
    String inputLine;
    while ((inputLine = in.readLine()) != null) 
        System.out.println(inputLine);
          in.close();
}
}