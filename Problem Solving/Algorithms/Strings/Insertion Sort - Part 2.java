import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static void insertionSort1(int n, int[] array) {
        // Complete this function
        int i = array.length - 1;
        int value = array[i];
        while (i >= 1 && array[i-1] > value) {
            array[i] = array[i-1];
            i--;
            printArray(array);
        }
        array[i] = value;
        printArray(array);
    }
    
    private static void printArray(int[] array) {
        for (int num: array) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for(int arr_i = 0; arr_i < n; arr_i++){
            arr[arr_i] = in.nextInt();
        }
        insertionSort1(n, arr);
        in.close();
    }
}
