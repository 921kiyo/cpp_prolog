
public class SyncPrinter implements Runnable {
    private SyncCounter next;
    int maxNum;
    
    SyncPrinter(SyncCounter i, int max) {
        next = i; maxNum = max;
    }
    
    public void run() {
        int v = next.getAndIncrement();
        while (v<= maxNum ) {
            System.out.println("Thread "
                               + Thread.currentThread().getId()
                               + ":" + v);
            v = next.getAndIncrement();
        }
    }
}

