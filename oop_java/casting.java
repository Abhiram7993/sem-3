public class casting{

    public static void main(String[] args){

        // widening will automatically done by java
        int n = 65;
        double number = n;
        System.out.println("number: "+number);

        // narrowing; we need to explicitly perform conversion
        int m = (int) number;
        System.out.println("m: "+m);

        // Type casting in characters, 
        // Converting char to int is widening hence its automatically done
        char c = 'A';
        int ascii = c;
        System.out.println("ascii: "+ascii);

        // converting int to char is narrowing, which is need to be done explicitly
        char character = (char) ascii;
        System.out.println("character: "+character);
    }
}