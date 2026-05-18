import java.util.Random;
import java.util.Scanner;
// QuickSortTask class implements Runnable to perform quicksort in a separate thread
class QuickSortTask implements Runnable {
    private int[] arr;
    private int low;
    private int high;
    // Constructor to initialize the array and the low and high indices for sorting
    public QuickSortTask(int[] arr, int low, int high) {
        this.arr = arr;
        this.low = low;
        this.high = high;
    }

    @Override
    public void run() {
        // Call the quickSort method to sort the array segment defined by low and high
        quickSort(arr, low, high);
    }
    private void quickSort(int[] arr, int low, int high) {

        if (low < high) {
            // If the segment size is less than 10,000, use normal quicksort to avoid overhead of threading
            if (high - low < 10000) {
                normalQuickSort(arr, low, high);
                return;
            }
            int pivotIndex = partition(arr, low, high);
            Thread leftThread = new Thread(new QuickSortTask(arr, low, pivotIndex - 1));
            Thread rightThread = new Thread(new QuickSortTask(arr, pivotIndex + 1, high));

            leftThread.start();
            rightThread.start();

            try {
                leftThread.join();
                rightThread.join();
            } // Catching InterruptedException in case the threads are interrupted while waiting
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    // Normal quicksort implementation for small segments to avoid threading overhead
    private void normalQuickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            normalQuickSort(arr, low, pivotIndex - 1);
            normalQuickSort(arr, pivotIndex + 1, high);
        }
    }

    private int partition(int[] arr, int low, int high) {

        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
}

public class a4 {

    public static void main(String[] args) {
        int size = 1_000_000;
        int[] arr = new int[size];
        Random rand = new Random(1);
        // Fill the array with random integers between 0 and 1,000,000 with seed for reproducibility
        for (int i = 0; i < size; i++) {

            arr[i] = rand.nextInt(1_000_000);
        }
        long start = System.currentTimeMillis();
        // Create a QuickSortTask to sort the entire array and run it
        QuickSortTask task = new QuickSortTask(arr, 0, size - 1);
        task.run();
        long end = System.currentTimeMillis();
        System.out.println("Sorting completed in: " + (end - start) + " ms");
        //check if the array is sorted or not 
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[i - 1]) {
                System.out.println("Array is not sorted!");
                return;
            }
            else{
                System.out.println("Array is sorted!");
                break;
            }
        }
        System.out.println(arr[500]);
        // Create a Scanner to read user input for the target number to search
        Scanner sc = new Scanner(System.in);
        boolean valid = false;
        int target = 0;
        while (!valid) {
            System.out.print("Enter a number to search: ");
            if (sc.hasNextInt()) {
                target = sc.nextInt();
                if (target >= 0 && target <= 1_000_000) {
                    valid = true;
                } else {
                    System.out.println("Please enter a number between 0 and 1,000,000.");
                }
            } else {
                System.out.println("Invalid input. Please enter an integer.");
                sc.next();
            }
        }
        sc.close();
        binarysearch(arr, target);
    }

    public static void binarysearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                System.out.println("Element found at index: " + mid);
                return;
            }
            else if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        System.out.println("Element not found");
    }
}