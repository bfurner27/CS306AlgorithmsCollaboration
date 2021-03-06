import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class InsertSort {

    private static int total;

    public static void main(final String[] args)
    {
	ArrayList<Integer> ar = new ArrayList<>();
	File inFile = null;
	if (0 < args.length) {
	    inFile = new File(args[0]);
	} else {
	    System.err.println("Invalid arguments count:" + args.length);
	    return;
	}
	try {
	    Scanner scanner = new Scanner(inFile);
	    while(scanner.hasNextInt())
		ar.add(scanner.nextInt());
	}
	catch (FileNotFoundException ex){
	    System.out.println(ex);
	}

	
	Integer[] arr = ar.toArray(new Integer[ar.size()]);
	long startTime = System.currentTimeMillis();
	insertSort(arr);
	long endTime   = System.currentTimeMillis();
	long totalTime = endTime - startTime;
	System.out.println((float)totalTime/1000);
    }

    // Code retrieved from rosetta code
    public static void insertSort(Integer array[]){
	for(int i = 1; i < array.length; i++){
	    int value = array[i];
	    int j = i - 1;
	    while(j >= 0 && array[j] > value){
		array[j + 1] = array[j];
		j = j - 1;
	    }
	    array[j + 1] = value;
	}
    }
}
    
