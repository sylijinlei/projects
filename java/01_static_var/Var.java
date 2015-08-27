public class Var
{
	public static  void main(String args[])
	{
		Child chd1 = new Child(12,"小明");
		chd1.joinGame();
		Child chd2 = new Child(13,"小华");
		chd2.joinGame();
		System.out.println("child1 name = "+chd1.name);
		System.out.println("total child count:"+Child.count);
	}
}
class Child
{
	int age;
	String name;
	 static int count = 0;
	public Child(int age, String name)
	{
		count ++;
		this.age = age;
		this.name = name;
	}
	public void joinGame()
	{
		count++;
		System.out.println("有一个小孩加入了游戏!");
	}
}
