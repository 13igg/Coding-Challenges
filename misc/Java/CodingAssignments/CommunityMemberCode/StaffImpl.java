
public class StaffImpl implements Staff 
{
	//a community member
	private CommunityMember comm;
	//data for the staff
	private String boss;

	public StaffImpl(String n, String b)
	{
		//creat an impl
		comm = new CommunityMemberImpl(n);
		//set the staff data
		setBoss(b);
	}	

	public StaffImpl(String b)
	{
		//set the staff data
		setBoss(b);
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
	public String getBoss() 
	{
		return boss;
	}

	@Override
	public void setBoss(String b)
	{
		boss = b;
	}

	@Override
	public String toString()
	{
		return comm.toString() + " \nBoss: " + getBoss();
	}
}
