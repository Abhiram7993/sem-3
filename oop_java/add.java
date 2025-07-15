import java.util.Scanner;


public class add{
    // In methods, parameter also required declaration.
    public static int addition(int x, int y){
        return x + y;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number 1: ");
        int n = sc.nextInt();
        System.out.println("Enter number 2: ");
        int m = sc.nextInt();
        sc.close();

        int sum = addition(n, m);

        System.out.println("Sum: " + sum);
    }
}