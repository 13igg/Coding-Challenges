import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.List;
import java.net.*;
import java.io.*;
public class Driver
{
	public static void main(String[] args)
	{
		//Icon i = new Icon(200,200);//0 5 by 0 5		
		ArrayList<Accounts> accountList = new ArrayList<Accounts>();
		Savings s = new Savings(.275); //initial balance of 100$ with interest rate of 1.75
		
		s.setAccountNumber(313141);
		s.setLastName("Ciaglia");
		s.setFirstName("Matt");
		s.setMailingAddress("132 Siems Circle");

		accountList.add(s);
		s.deposit(400,"10 16 2000");
		s.withdrawl(300,"10 17 2000");
		s.deposit(0,"10 20 2001");
		//s.deposit(25,"02 13 2003");
		//s.withdrawl(25,"10 16 2003");

		Savings a = new Savings(1.75);
		
		a.setAccountNumber(1231221);
		a.setLastName("Ciaglia");
		a.setFirstName("Matt");
		a.setMailingAddress("132 Siems Circle");
		accountList.add(a);		
		a.deposit(25000,"10 16 2000");
		a.withdrawl(25,"10 17 2002");
		
		Equity e = new Equity();

		e.setAccountNumber(44343222);
		e.setLastName("Ciaglia");
		e.setFirstName("Matt");
		e.setMailingAddress("132 Siems Circle");

		accountList.add(e);
		e.purchaseStock("NKE", 10);
		e.purchaseStock("AAPL", 2);		
		e.purchaseStock("GOOG", 4);
		e.purchaseStock("TST", 1000);

		HTML print = new HTML(accountList);
		
	}

}