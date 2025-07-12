import java.util.Scanner;

public class multiplication{

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int n = sc.nextInt();
        sc.close();

        for (int i=1; i<=10; i++){
            // in println we can add multiple string and integers via +.
            System.out.println("n * "+i+" = "+(n*i));
        }
    }

}