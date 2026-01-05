import java.util.Scanner;

public class HelloJNI {  
   static {
      System.loadLibrary("hello"); // Load native library libhello.so 
                                   //  at runtime
                                   // This library contains a native method called sayHello()
   }
 
   // Declare an instance native method sayHello() which receives no parameter and returns void
   private native void sayHello(int num);
 
   // Test Driver
   public static void main(String[] args) {
      Scanner input = new Scanner(System.in);

      System.out.print("Send To C : ");
      int num = input.nextInt();
      new HelloJNI().sayHello(num);  // Create an instance and invoke the native method

      input.close();
   }
}
