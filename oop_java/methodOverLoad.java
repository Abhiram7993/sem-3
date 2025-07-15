
public class methodOverLoad{
    // This greet() is called when we call greet fn without any parameters.
    public static void greet(){
        System.out.println("Hello, welcome to java");
    }
    // This greet() is called when we call greet fn with one parameter.
    public static void greet(String name){
        System.out.println("Hello, " + name);
    }

    public static void main(String[] args){
        // calling without parameter, first function
        greet();
        // calling with parameter.
        greet("Abhiram");
    }
}   