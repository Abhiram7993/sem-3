import java.util.Scanner;

public class rec_factorial{
    public static int factorial(int n){
        if (n == 0){
            return 1;
        }
        else{
            return n*factorial(n-1);
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // print() will not add newline char, but println() will add this character.
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        sc.close();
        
        // catching false input
        if (n < 0){
            System.out.println("Invalid integer.");
            return;
        }
        System.out.println("Factorial of " + n + " is " + factorial(n));
    }
}