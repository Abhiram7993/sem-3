public class Varargs{

    public static int add(int... numbers){

        // Here numbers is the varargs, all argument passed during calling
        // add() will be save in an array named numbers
        int sum = 0;
        
        for (int i : numbers){
            sum += i;
        }
        return sum;
    }

    public static void main(String[] args){
        System.out.println(add(1, 2, 3, 4, 5));
        System.out.println(add(7, 8, 9));
        System.out.println(add(1));
    }
}