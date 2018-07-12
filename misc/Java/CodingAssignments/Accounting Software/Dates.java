public class Dates
{
	public int day;
	public int month;
	public int year;
	public Dates()
	{
		//automatically makes jan 1 1999
		setYear(0000);
		day = 01;
		month = 01;
	}
	public Dates(int m,int d, int y)
	{
		//automatically makes jan 1 1999
		setYear(y);
		setDay(d);
		setMonth(m);
	}
	public Dates(String date)
	{
		setYear(Integer.parseInt(date.substring(6)));
		setMonth(Integer.parseInt(date.substring(0,2))); 
		setDay(Integer.parseInt(date.substring(3,5)));
	}
	public int getMonth()
	{return month;}
	public int getYear()
	{return year;}
	public void setYear(int y)
	{year = y;}
	public void setMonth(int m)
	{month = m;
		if ((month < 1 || month > 12))
			System.out.println("Invalid Month, Transaction canceled");}
	public void setDay(int d)
	{day = d;
		if((day < 1 || day > 31))
			System.out.println("Invalid Day, Transaction canceled");
		else if(month == 9 || month == 4 || month == 6 || month == 11)
			if(day > 30)
				System.out.println("Invalid Date, Transaction canceled");
		else if(month == 2){
			if(checkLeapYear(year)){
				if(day > 29)
					System.out.println("Invalid Date, Transaction canceled");
				else if(day > 28)
					System.out.println("Invalid Date, Transaction canceled");}}
		else
			if(day>31)
				System.out.println("Invalid Date, Transaction canceled");}
	public int getDay()
	{return day;}
	public boolean compareTo(Dates d1, Dates d2)
	{
		//if it is greater than return true
		if(d1.getYear() < d2.getYear())
			return false;//1 comes before 2
		else if(d1.getYear() > d2.getYear())
			return true;//1 comes after 2
		else //if year is =
			if(d1.getMonth() < d2.getMonth())
				return false; //1 comes before 2
			else if(d1.getMonth() > d2.getMonth())
				return true; //1 comes after 2
			else //months are =
				if(d1.getDay() < d2.getDay())
					return false; //1 comes before 2
				else 
					return true; //1 comes after 2
	}
	private boolean checkLeapYear(int year)
	{
		if ( year % 4 == 0 && (month == 1 || month == 2))
			if (year % 100 == 0)
				if (year % 400 == 0)
					return true;
				else 
					return false;
			else 
				return true;
		else
			return false;
	}
	public String toString()
	{
		return getMonth() + "/" + getDay() + "/" + getYear();
	}
}