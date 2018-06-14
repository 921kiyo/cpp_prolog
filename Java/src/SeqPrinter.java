public class SeqPrinter implements Runnable {
    public void run() {
        for (int i = 1; i<=20; i++)
            System.out.println("Thread " +
                               Thread.currentThread().getId() +
                               ":" + i);
    }
}
