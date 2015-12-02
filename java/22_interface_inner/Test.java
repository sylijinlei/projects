public class Test{
	public static void main(String args[])
	{
		LedService ls = new LedService();
		ls.printInfo();
	}
}
interface ILedService{
	public class Stub implements ILedService
	{
		Stub()
		{
			System.out.println("Construct Stub-->");
		}
		public void printInfo()
		{
			System.out.println("Stub-->");
		}
	}
	public void printInfo();
} 
class LedService extends ILedService.Stub{
	LedService()
	{
		super();
		System.out.println("Construct LedService-->");
	}
	public void printInfo()
	{
		System.out.println("ILedService-->");
		super.printInfo();
	}

}
