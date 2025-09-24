public class Private{
    public static void main(String[] args){
        myclass c = new myclass();
        c.showSecrete();
    }
}


class myclass{
    private int secrete = 123;

    void showSecrete(){
        System.out.println(this.secrete);
    }


}