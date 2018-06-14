import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ExecutorServiceDemo  {    
    static public void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(2);
        executor.execute(new SeqPrinter());
        executor.execute(new SeqPrinter());
        executor.execute(new SeqPrinter());
        executor.shutdown();
    }
}
