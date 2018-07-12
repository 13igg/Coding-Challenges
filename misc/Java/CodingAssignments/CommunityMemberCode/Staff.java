/**
 * A staff member has a boss
 */
public interface Staff extends CommunityMember
{
	public String getBoss();
	public void setBoss(String b);
}
