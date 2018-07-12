import javax.swing.JOptionPane;
import java.util.*;
import java.io.BufferedWriter;
import java.io.File;
import java.io.*;
public abstract class Accounts 
{
	private int accountNumber;
	private String lastName;
	private String firstName;
	private String mailingAddress;
	public Accounts()
	{
		//System.out.println("new account made");
		setAccountNumber(0);
	 	setLastName("");
	 	setFirstName("");
	 	setMailingAddress("");
	}
	public void setAccountNumber(int an)
	{
		accountNumber = an;
	}
	public int getAccountNumber()
	{
		return accountNumber;
	}

//first and last
	public void setFirstName(String fn)
	{
		firstName = fn;
	}
	public String getFirstName()
	{
		return firstName;
	}

	public void setLastName(String ln)
	{
		lastName = ln;
	}
	public String getLastName()
	{
		return lastName;
	}

//mailing address 
	public void setMailingAddress(String ma)
	{
		mailingAddress = ma;
	}
	public String getMailingAddress()
	{
		return mailingAddress;
	}
	
	public abstract double getBalance();

	public String toString()
	{
		return "<p><font size=\"4\">Account Number: " + getAccountNumber() + "<br></br>Name: " + getFirstName() + " " + getLastName() + "<br></br>Address: " + getMailingAddress() + "</font></p>";
	}

}