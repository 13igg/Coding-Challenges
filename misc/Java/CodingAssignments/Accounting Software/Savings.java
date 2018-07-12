import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.List;
import java.util.*;
import java.text.*;
public class Savings extends Accounts
{
	//balance
	 private double balance;
	//annual interest rate
	 private double interestRate; 
	 private Dates dateOfTransaction;
	 private Dates janFirst;
	 	//look at all withdraws and deposits and a jan first inbetween them. 
		 //special deposit

	//holds info on transactions
	private ArrayList<Transaction> transactionList;

	//sets initial balance and interestRate
	public Savings(double ir)
	{
		setInterestRate(ir);
		transactionList = new ArrayList<Transaction>();
	}
	public Savings()
	{
		setBalance(0.0);
		setInterestRate(0);
	}
	private void setInterestRate(double ir)
	{
		while(ir<0){
			System.out.println("Interest Rate must be greater than 0, setting it to default intrest Rate"); setInterestRate(.015);}
		interestRate = ir;
	}
	public double getInterestRate()
	{
		return interestRate;
	} 
	//keep track of all transactions within its own class
	//will keep track of the inital balance and the new balance
	public void deposit(double deposit,String date)
	{		
		if(setDateofTransaction(date))
		{	
			addInterest();
			Transaction t = new Transaction(deposit,balance,balance+=deposit,"Deposit",dateOfTransaction);
			transactionList.add(t);
		}
	}
	public void withdrawl(double withdrawl,String date)
	{
		if(withdrawl > getBalance())
			System.out.println("You cannot withdrawl more than you have!");
		else if(setDateofTransaction(date))
		{		
			addInterest();	
			Transaction t = new Transaction(withdrawl,balance,balance-=withdrawl,"Withdrawl",dateOfTransaction);
			transactionList.add(t);
		}
	}
	private boolean setDateofTransaction(String date)
	{ 		
		dateOfTransaction = new Dates(date);
		if(transactionList.size() != 0 && !dateOfTransaction.compareTo(dateOfTransaction,transactionList.get(transactionList.size()-1).getDate()))
		{
			System.out.println("You cannot make this transaction because that date has passed");
			return false;
		}
		return true;
	}
//fix this stuff under here
	public void addInterest()
	{
		janFirst = new Dates();//jan first 0000 year is set soon
		if(transactionList.size() != 0)
		{
			janFirst.setYear(transactionList.get(transactionList.size()-1).getDate().getYear()+1);
			if(dateOfTransaction.compareTo(janFirst,transactionList.get(transactionList.size()-1).getDate()) && dateOfTransaction.compareTo(dateOfTransaction,janFirst))
			{
				int years = dateOfTransaction.getYear() - janFirst.getYear();
				for(int i = 0; i <= years; i ++)
				{
					janFirst = new Dates(01,01,transactionList.get(transactionList.size()-1).getDate().getYear()+1);
					Transaction t = new Transaction(((getBalance()*(getInterestRate()/100))),balance,balance += ((getBalance()*(getInterestRate()/100))),"Interest Incurred",janFirst);
					transactionList.add(t);
				}
			}
		}
	}
	public double getBalance()
	{
		return balance;
	}
	public void setBalance(double b)
	{
		if(balance < 0){
			System.out.println("Balance cannot be negative! defaulting it to 0"); setBalance(0);}
		balance = b;
	}
//need to add balance after each compounding and the annual interest rate as well
	public String toString()
	{
		String toReturn = (super.toString() + "</p><font size=\"3\">Current Balance: " + NumberFormat.getCurrencyInstance().format(getBalance()) + " Interest Rate: " + getInterestRate() + "%<p></p>Transaction Data</font></p><table border=\"1\"><tr><th>Date</th><th>Type</th><th>Amount</th><th>Previous Balance</th><th>New Balance</th></tr>");
		for(int i = 0; i < transactionList.size(); i ++)
			toReturn += transactionList.get(i);
		return toReturn+"</table>";
	}

	public void printTransactions()
	{
		for(int i = 0; i < transactionList.size(); i ++)
			System.out.println(transactionList.get(i));
	}
}