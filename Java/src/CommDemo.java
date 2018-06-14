public class CommDemo  {
    
    static public void main(String[] args) {
        final int MAX = 20;
        Counter c = new Counter(0);
        Thread t1 = new Thread(new CommPrinter(c, MAX));
        Thread t2 = new Thread(new CommPrinter(c, MAX));
        t1.start(); t2.start();
    }
}
