//program to generate 1000000 random numbers and find the maximum and minimum amongst them using threading concepts 5 threads each having 200000 random numbers and then display the 5 maximum and minimum numbers from each thread
/*algorithm :
1. Generate an array of 1000000 random integers.
2. Create a separate class that implements Runnable to find the minimum and maximum in a given segment of the array.
3. In the main method, create and start 5 threads, each processing a segment of 2 lakh integers.
4. Each thread will print its minimum and maximum values.
5. Now the threads will be combined to find the overall minimum and maximum values.
6. Exit the program.
*/
import java.util.Random;
import java.time.Instant;
import java.time.Duration;

public class program1 {

    private static final int[] ARR = new Random().ints(1000000, 0, Integer.MAX_VALUE).toArray();
    private final int THREAD_COUNT = 5;
    private final int CHUNK_SIZE = 200000;

    public static void main(String[] args) {
        program1 program = new program1();
        program.executeThreads();
    }

    public void executeThreads() {

        Instant start1 = Instant.now();
        System.out.println("Start time of the program: " + start1+ "\n");

        Thread[] threads = new Thread[THREAD_COUNT]; /////// array of threads to hold the thread references

        //creating 5 threads and starting them
        for (int i = 0; i < THREAD_COUNT; i++) { 
            int start = i * CHUNK_SIZE;
            int end = start + CHUNK_SIZE;

            //create a new minmaxthreads object for each thread
            minmaxthreads minmax = new minmaxthreads(ARR, start, end, i + 1);

            threads[i] = new Thread(minmax);
            threads[i].start();
        }

        //join all threads to wait for their completion
        for (int i = 0; i < THREAD_COUNT; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                System.out.println("Main thread was interrupted");
            }
        }
        System.out.println("\nAll threads completed execution.");

        //overall max and min calculation
        int overallMin = Integer.MAX_VALUE;
        int overallMax = Integer.MIN_VALUE;

        for (int i = 0; i < THREAD_COUNT; i++) {
            int start = i * CHUNK_SIZE;
            int end = start + CHUNK_SIZE;

            for (int j = start; j < end; j++) {
                if (ARR[j] < overallMin)
                    overallMin = ARR[j];
                if (ARR[j] > overallMax)
                    overallMax = ARR[j];
            }
        }
        System.out.println("Overall Min: " + overallMin + ", Overall Max: " + overallMax);

        Instant end1 = Instant.now();
        System.out.println("End time of the program: " + end1 + "\n");

        Duration timeElapsed = Duration.between(start1, end1);
        System.out.println("Time taken: " + timeElapsed.toMillis() + " milliseconds");
    }
}
