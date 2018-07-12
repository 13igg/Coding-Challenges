
public class StudentImpl implements Student 
{
	private CommunityMember comm;
	private double gpa;
	
	public StudentImpl(String n, double g)
	{
		comm = new CommunityMemberImpl(n);
		setGPA(g);
	}

	public StudentImpl(double g)
	{
		setGPA(g);
	}
	
	@Override
	public String getName() 
	{
		//delegate this responsibility to the comm impl
		return comm.getName();
	}

	@Override
	public void setName(String n) 
	{
		//delegate this responsibility to the comm impl
		comm.setName(n);
	}

	@Override
	public double getGPA() 
	{
		return gpa;
	}

	@Override
	public void setGPA(double g)
	{
		gpa = g;	
	}

	@Override
	public String toString()
	{
		return comm.toString() + " \nGPA: " + getGPA();
	}

}
