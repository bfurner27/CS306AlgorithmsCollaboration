import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class SwapSort {

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
	sort(ar);
	long endTime   = System.currentTimeMillis();
	long totalTime = endTime - startTime;
	System.out.println((float)totalTime/1000);
    }
    
    /*************
     * This will actually sort the list to what it should be
     * array - this is the array value that needs to be sorted
     * return: This will return the assorted array so that it can be verified
     * that it was sorted correctly
     **********/
    public static List<Integer> sort(List<Integer> array) {
    	
	// create the array that will be sorted
	List<Integer> sortedList = new ArrayList<>();

	// This will loop through the array and will search through and find the
	//smallest value and will
	// switch the smallest value with the first item.
	int smallestItemIndex = 0;
	int j = 0;
	for (int i = 0; i < array.size(); i++) {
	    // This will reset the variables while taking into account that i
	    //numbers of values is already
	    // sorted
	    j = i;
	    smallestItemIndex = i;

	    // This will run through the array values to find the smallest index
	    for ( ; j < array.size(); j++) {
    			
		// check if the value that j is on is smaller than the current
		//smallest value
		if (array.get(smallestItemIndex) > array.get(j)) {
		    smallestItemIndex = j;
		}
	    }

	    // these will swap the i'th element with the smallest item in the
	    //remaider of the list
	    int temp = array.get(i);
	    array.set(i, array.get(smallestItemIndex));
	    array.set(smallestItemIndex, temp);

	}

	return array;
    }
}
