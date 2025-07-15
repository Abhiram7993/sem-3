import java.util.Scanner;


public class fibonacci{

    public static int fib(int n){
        // here n denotes number of term
        if (n == 1){
            return 0;
        } 
        else if (n == 2){
            return 1;
        }
        else{
            return fib(n-1) + fib(n-2);
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        sc.close();

        // finding sequence of n
        for (int i=1; i<=n; i++){
            System.out.print(fib(i)+ " ");
        }
        // printing new line
        System.out.println();
    }
}