import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.List;
import java.net.*;
import java.io.*;
import java.text.*;
public class Stock
{
	private String name;
	private String symbol;
	private double value;
	private int numShares;

	public Stock(String s, int nS)
	{
		symbol = s;		
		numShares = nS;
		setValueAndName(symbol);
	}
	public double getValue()
	{
		return value;
	}
	public void setValueAndName(String s)
	{
		try
		{
			String stocks = s;
		    URL yahoofinance = new URL("http://finance.yahoo.com/d/quotes.csv?s="+stocks+"&f=nl1");
		    URLConnection yc = yahoofinance.openConnection();
		    BufferedReader in = new BufferedReader(new InputStreamReader(yc.getInputStream()));
		    String inputLine;
		    while ((inputLine = in.readLine()) != null) 
       			{
	       			name = inputLine.substring(1,inputLine.indexOf("\","));
	       			value = Double.parseDouble(inputLine.substring(inputLine.indexOf("\",")+2));
		   		}
          	in.close();
      	}
      	catch(Exception e)
      	{
      		e.printStackTrace();
      	}
      	
	}

	public String toString()
	{
		return "<tr><td>" + name + "</td><td>" + symbol + "</td><td>" + NumberFormat.getCurrencyInstance().format(getValue()) + "</td><td>" + numShares + "</td></tr>";
	}
			 //stock name
			//ticker symbol
			//dollar value
			//number of shares held

}