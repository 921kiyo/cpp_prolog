public class CommPrinter implements Runnable {
    int maxNum;
    Counter next;
    
    
    CommPrinter(Counter i, int max) {
        next = i;
        maxNum = max;
    }
    
    public void run() {
        while (next.getValue()<= maxNum ) {
            System.out.println("Thread "
                               + Thread.currentThread().getId()
                               + ":" + next.getValue());
            //                try{Thread.sleep(1000);} catch(Exception e) {}
            next.increment();
        }
    }
}

