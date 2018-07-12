import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.List;
import java.text.*;
public class Equity extends Accounts
{
	//list of stock purchaces
	private ArrayList<Stock> stockList;
	private double balance;

	public Equity()
	{
		balance = 0;
		stockList = new ArrayList<Stock>();
	}
	public void purchaseStock(String symbol, int numShares)
	{
		Stock s = new Stock(symbol,numShares);
		balance += s.getValue()*numShares; //total value of stock portfolio
		stockList.add(s);
	}
	public double getBalance()
	{
		return balance;
	}
	public String toString()
	{
		String toReturn = (super.toString() + "<font size=\"3\">Total portfolio value: "+ NumberFormat.getCurrencyInstance().format(this.balance) +"</font><table border=\"1\"><tr><th>Stock</th><th>Ticker</th><th>Value</th><th>Number of Shares</th></tr>");
		for(int i = 0; i < stockList.size(); i ++)
			toReturn += (stockList.get(i));
		return toReturn + "</table>";
	}
	public void printStock()
	{
		for(int i = 0; i < stockList.size(); i ++)
			System.out.println(stockList.get(i));
	}

}