public class Encapsulation{
    public static void main(String[] args){
        Finance f = new Finance(45000);
        f.deposit(3400);
        f.getBalance();
    }
}


class Finance{
    private double balance;

    Finance(int InitialBalance){
        this.balance = InitialBalance;
    }

    // getter for accessing balance
    void getBalance(){
        System.out.println(this.balance);
    }

    // setter for updating balance
    void deposit(int cash){
        this.balance = this.balance + cash;
    }
}