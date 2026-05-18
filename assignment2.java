//linear search algorithm using threading each thread 2L elements, 1 element gets the thread stop others using notify and display the index at which the element is stored at, also use timestamping

/*alogrithm
1. Generate 10L string elements using random function.
2. Create a separate class that implements Runnable to check for the particular element in a given segment of the array.
3. In the main method, create and start 5 threads, each processing a segment of 2 lakh string elements.
3. Check for the element to be searched from the user and also ask how many times does he want the occurence i.e. single or multiple.
4. Each thread will be given the element to search for.
5. If user requested multi occurence search, then the threads will continue searching for the next occurence of the element, if not then only the first occurence will be displayed.
6. Display the time taken to search for the elements.
7. Exit the program.
*/

import java.util.Random;
import java.time.Instant;
import java.time.Duration;
import java.util.Scanner;

class SearchTask implements Runnable {
    private String[] array;
    private String searchElement;
    private int startIdx;
    private int endIdx;
    private boolean multiple;

    public SearchTask(String[] array, String searchElement, int startIdx, int endIdx, boolean multiple) {
        this.array = array;
        this.searchElement = searchElement;
        this.startIdx = startIdx;
        this.endIdx = endIdx;
        this.multiple = multiple;
    }

    @Override
    public void run() {
        if (multiple) {
            for (int i = startIdx; i < endIdx; i++) {
                if (array[i].equals(searchElement)) {
                    System.out.println("Thread " + Thread.currentThread().getName() + " found element at index: " + i);
                }
            }
        } else {
            for (int i = startIdx; i < endIdx; i++) {
                if (array[i].equals(searchElement)) {
                    System.out.println("Thread " + Thread.currentThread().getName() + " found element at index: " + i);
                    return;
                }
            }
        }
    }
}

public class program2 {
    public static void main(String[] args) {
        Random random = new Random();
        String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        String[] names = new String[1000000];
        for (int i = 0; i < 1000000; i++) {
            StringBuilder name = new StringBuilder();
            for (int j = 0; j < 5; j++) {
                name.append(characters.charAt(random.nextInt(characters.length())));
            }
            names[i] = name.toString();
        }
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a name to search: ");
        String searchName = scanner.nextLine();
        System.out.print("Do you want to search for single or multiple occurrences? (s/m): ");
        String choice = scanner.nextLine();
        boolean multiple = choice.equalsIgnoreCase("m");

        //////////////////////////////////////////////////
        ///////starting the search with the timestamping ///////
        //////////////////////////////////////////////////
        
        Instant start = Instant.now();
        SearchTask[] tasks = new SearchTask[5];
        Thread[] threads = new Thread[5];
        int segmentSize = 200000;
        for (int i = 0; i < 5; i++) {
            int startIdx = i * segmentSize;
            int endIdx = (i + 1) * segmentSize;
            tasks[i] = new SearchTask(names, searchName, startIdx, endIdx, multiple);
            threads[i] = new Thread(tasks[i]);
            threads[i].start();
        }
        for (int i = 0; i < 5; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted: " + e.getMessage());
            }
        }
        Instant end = Instant.now();
        Duration timeElapsed = Duration.between(start, end);
        System.out.println("Time taken to search: " + timeElapsed.toMillis() + " milliseconds");
        scanner.close();
    }
}