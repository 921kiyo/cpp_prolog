public class SyncCounter {
    private int counter;
    SyncCounter(int i) { counter = i; }
    
    synchronized
    public int getAndIncrement() {
        int ret = counter;
        counter++;
        return ret;
    }
}

