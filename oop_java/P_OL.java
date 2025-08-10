public class P_OL{
    public static void main(String[] args){
        Calculator c1 = new Calculator();
        c1.add(10, 12);
        c1.add(23.2, 1.1);
    }
}


class Calculator{
    void add(int x, int y){
        System.err.println("Integer sum: "+ (x+y) );
    }
    // when we type 2 floatting point value, by default they save as double
    void add(double x, double y){
        System.out.println("Float sum: "+ (x+y));
    }
}