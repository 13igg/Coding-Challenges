//will keep track of the inital balance and the new balance
import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.List;
import java.util.Calendar;
import java.text.*;
public class Transaction
{
	private double previousBalance;
	private double newBalance;
	private String type;
	private Dates dateOfTransaction;
	private double amount;
	public Transaction(double a, double pb, double nb, String t, Dates date)
	{
		amount = a;
		dateOfTransaction = date;
		previousBalance = pb;
		newBalance = nb;
		type = t;		
	}
	public Dates getDate()
	{
		return dateOfTransaction;
	}
	public String toString()
	{
		return "<tr><td>"+ getDate() +"</td><td>"+ type +"</td><td>"+ NumberFormat.getCurrencyInstance().format(amount) +"</td><td>"+ NumberFormat.getCurrencyInstance().format(previousBalance) +"</td><td>"+ NumberFormat.getCurrencyInstance().format(newBalance) +"</td></tr>";
	}
}
