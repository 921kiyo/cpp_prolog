public class StopDemo  {
    
    static public void main(String[] args) {
        new StopDemo().demo();
    }
    
    public void demo() {
        SyncCounter c = new SyncCounter(0);
        InfWorker w1 = new InfWorker(c);
        InfWorker w2 = new InfWorker(c);
        
        Thread t1 = new Thread(w1);
        Thread t2 = new Thread(w2);
        t1.start(); t2.start();
        try{Thread.sleep(5);} catch(Exception e) {}
        w1.stop();
        w2.stop();
    }
    
    
    
    private class SyncCounter {
        private int counter;
        SyncCounter(int i) { counter = i; }
        
        synchronized
        public int getAndIncrement() {
            int ret = counter;
            counter++;
            return ret;
        }
    }
    
    
    
    private class InfWorker implements Runnable {
        SyncCounter next;
        
        InfWorker(SyncCounter i) { next = i; }
        
        public void stop() {next = null;}
        
        public void run() {
            while (true) {
                if (next == null){
                    System.out.println("Shutting down thread "
                                       + Thread.currentThread().getId());
                    return;
                }
                System.out.println("Thread "
                                   + Thread.currentThread().getId()
                                   + ":" + next.getAndIncrement());
            }
        }
    }
}
