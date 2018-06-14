public class CommDemo2  {
    static public void main(String[] args) {
        final int MAX = 20;
        SyncCounter c = new SyncCounter(0);
        Thread t1 = new Thread(new SyncPrinter(c,MAX));
        Thread t2 = new Thread(new SyncPrinter(c,MAX));
        t1.start(); t2.start();
    }
}
