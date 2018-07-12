
public class Driver 
{
	public static void main(String[] args) throws Exception
	{
		//create the client and the server
		Server server = new Server();
		Client client = new Client(server);
		
		//ask the client to do something with the server
		client.performAdd();
	}
}
