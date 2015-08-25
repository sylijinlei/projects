public class Var
{
	public static  void main(String args[])
	{
		Child chd1 = new Child(12,"小明");
		chd1.joinGame();
	}
}
class Child
{
	int age;
	String name;
	static int count = 0;
	public Child(int age, String name)
	{
		this.age = age;
		this.name = name;
	}
	public void joinGame()
	{
		count++;
		System.out.println("有一个小孩加入了游戏!");
	}
}
