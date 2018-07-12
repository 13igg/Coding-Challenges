
public class StudentStaffImpl implements StudentStaff 
{
	//three pieces of a student staff 
	private CommunityMember comm;
	private Staff staff;
	private Student student;
	
	public StudentStaffImpl(String n, double g, String b)
	{
		comm = new CommunityMemberImpl(n);
		student = new StudentImpl(g);
		staff = new StaffImpl(b);
	}

	@Override
	public String getName() 
	{
		//delegate to the comm impl
		return comm.getName();
	}

	@Override
	public void setName(String n)
	{
		//delegate to the comm impl
		comm.setName(n);
	}

	@Override
	public double getGPA() 
	{
		//delegate to the student impl
		return student.getGPA();
	}

	@Override
	public void setGPA(double g)
	{
		//delegate to the student impl
		student.setGPA(g);	
	}

	@Override
	public String getBoss() 
	{
		//delegate to the staff impl
		return staff.getBoss();
	}

	@Override
	public void setBoss(String b)
	{
		//delegate to the staff impl
		staff.setBoss(b);
	}

	@Override
	public String toString()
	{
		return "Name: " + comm.getName() + 
			   "\nBoss: " + getBoss() + 
			   "\n GPA: " + getGPA();
	}

}
