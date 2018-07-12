package StringsArrays;

public class StringRotation {
	public boolean Rotate(String s1, String s2)
	{
		if(s1.length() != s2.length() && s1.length() > 0)
			return false;
		s1 = s1.concat(s1);
		return true;//s2.isSubstring(s1);
	}
}
