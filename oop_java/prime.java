import java.util.Scanner;

public class prime{

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: "); 
        int n = sc.nextInt();
        sc.close();

        boolean flag = true;
        for (int i=2; i<n; i++){
            if (n%i == 0){
                flag = false;
                break;
            }
        }

        if (n <= 1){
            System.out.println("Neighther prime nor composite");
        }

        else if (flag){
            System.out.println(n+" is prime");
        }
        else{
            System.out.println(n+" is a composite");
        }
    }
}