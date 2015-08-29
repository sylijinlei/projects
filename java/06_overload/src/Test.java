public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		float a = 3.3f;
		float b = 5.2f;
		System.out.println("较大的数是：" + Abc.getMax(a, b));
	}

}

class Abc {
	public static int getMax(int a, int b) {
		return a >= b ? a : b;
	}

	public static float getMax(float a, float b) {
		return a >= b ? a : b;
	}
}