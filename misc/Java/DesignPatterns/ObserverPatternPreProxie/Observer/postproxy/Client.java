
public class Client 
{
	ServerInterface server;
	
	public Client(ServerInterface s)
	{
		server = s;
	}
	
	public void performAdd() throws Exception
	{
		int result = server.add(10, 20);
		System.out.println("The sum of 10 and 20 is " + result);	
	}
}
