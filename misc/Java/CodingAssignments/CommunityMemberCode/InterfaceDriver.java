
public class InterfaceDriver 
{
	public static void main(String[] args) 
	{
		Student stud1 = new StudentImpl("Buddy", 3.0);
		Staff staff1 = new StaffImpl("Mark", "Laura");
		StudentStaff studentStaff = new StudentStaffImpl("Patrick", 3.6, "Mark");
		
		System.out.println("==============");
		System.out.println("Student");
		System.out.println(stud1.toString());
		System.out.println("==============");
		System.out.println("Staff member");
		System.out.println(staff1.toString());
		System.out.println("==============");
		System.out.println("Student and Staff member");
		System.out.println(studentStaff.toString());
	}
}
