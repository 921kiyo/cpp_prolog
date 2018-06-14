import java.util.stream.IntStream;

public class ThreadDemo2  {
    
    static public void main(String[] args) {
        Thread t1 = new Thread(new SeqPrinter());
        Thread t2 = new Thread(new SeqPrinter());
        t1.start(); t2.start();
        System.out.println("Thread main shutting down" );
    }
}

