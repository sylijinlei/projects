import javax.swing.*;

public class Test extends JFrame{

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PupilStu p1 = new PupilStu();
		p1.printName();
		//Test test1 = new Test();
		System.out.println("middle static = "+MiddleStu.middle);
		p1.cry();
		Stu stu1 = new Stu();
		p1 = (PupilStu)stu1;
		//p1.cry();   //不可以，因为p1指向的是Stu类，Stu类中没有这个方法
		
	}
	public Test()
	{
		this.setVisible(true);
		this.setSize(100,200);
	}
}

class Stu {
	public String name;
	public int age;
	public float fee;
	
	public void printName() {
		System.out.println("我的名字是：" + this.name);
	}
}

class PupilStu extends Stu {
	public void pay(float fee) {
		this.fee = fee;
	}
	public void cry()
	{
		System.out.println("i am a pupil, 呜呜");
	}
}

class MiddleStu extends Stu {
	public static int middle = 30;
	public void pay(float fee) {
		this.fee = fee * 0.8f;
	}
}

class ColStu extends Stu {
	public void pay(float fee) {
		this.fee = fee * 0.2f;
	}
}
