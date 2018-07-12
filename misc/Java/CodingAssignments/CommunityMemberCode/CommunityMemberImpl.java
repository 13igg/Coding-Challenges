
public class CommunityMemberImpl implements CommunityMember 
{
	//the name of the community member
	private String name;
	
	public CommunityMemberImpl(String n)
	{
		setName(n);
	}

	//implementations of the name functionality
	@Override
	public String getName() 
	{
		return name;
	}

	@Override
	public void setName(String n)
	{
		name = n;
	}

	@Override
	public String toString()
	{
		return "Name: " + getName(); 
	}
}
