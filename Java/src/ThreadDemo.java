public class ThreadDemo  {
    
    static public void main(String[] args) {
        Thread t = new Thread(new SeqPrinter());
        t.start();
        System.out.println("Thread " +
                           Thread.currentThread().getId() +
                           " shutting down" );
    }
}
