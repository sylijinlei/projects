public class Child
{
	static void playDog(Dog dog)
	{
		dog.cry();
	}
	public static void main(String args[])
	{
		Dog dog = new Dog();
		playDog(Dog.this);		
	
	}
}
class Dog
{
	void cry()
	{
		System.out.println("我是一只狗，旺旺！");
	}
}
