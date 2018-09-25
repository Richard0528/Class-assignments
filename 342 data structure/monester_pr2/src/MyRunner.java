//package mylistpackage;


public class MyRunner {
	
	
		private static ArrayListUnsorted<Integer> mylist;//array list
		private static LinkedListUnsorted<Integer> mylist2;// linked list

		final private static int LOW = 25;  // test on this value and on even-numbered list
		
			
		public static void sortInsertionOppositeSorted(String result) {
			mylist = new ArrayListUnsorted<Integer>(LOW);
			for (int i = LOW; i > 0; i--)
				mylist.insert( i );
			
			System.out.println("Before: " + mylist);	
			mylist.myinsertion();		
			System.out.println("After: " + mylist);	
			
			if (result.equals(mylist.toString()))
				System.out.println("PASSED");
			else
				System.out.println("FAILED");
		}
		
		public static void sortInsertionOppositeSorted2(String result) {
			mylist2 = new LinkedListUnsorted<Integer>();
			for (int i = LOW; i > 0; i--)
				mylist2.insert(i);
			
			System.out.println("Before: " + mylist2);	
			mylist2.myinsertion();
			System.out.println("After: " + mylist2);	
			
			if (result.equals(mylist2.toString()))
				System.out.println("PASSED");
			else
				System.out.println("FAILED");
			  		
		}
		
		public static void sortOddEvenOppositeSorted(String result) {
			mylist = new ArrayListUnsorted<Integer>(LOW);
			for (int i = LOW; i > 0; i--)
				mylist.insert(i);
			
			System.out.println("Before: " + mylist);	
			mylist.myOddEven();	
			System.out.println("After: " + mylist);			
								
			if (result.equals(mylist.toString()))
				System.out.println("PASSED");
			else
				System.out.println("FAILED");  		
		}
			
		
		public static void sortOddEvenOppositeSorted2(String result) {
			mylist2 = new LinkedListUnsorted<Integer>();
			for (int i = LOW; i > 0; i--)
				mylist2.insert(i);
			
			System.out.println("Before: " + mylist2);	
			mylist2.myOddEven();	
			System.out.println("After: " + mylist2);							
			
			if (result.equals(mylist2.toString()))
				System.out.println("PASSED");
			else
				System.out.println("FAILED");
					
		}
		
		public static void sortCountSortOppositeSorted(String result) {
			mylist = new ArrayListUnsorted<Integer>(LOW);
			for (int i = LOW; i > 0; i--)
				mylist.insert(i);
			
			System.out.println("Before: " + mylist);	
			mylist.myCountingSort();	
			System.out.println("After: " + mylist);			
								
			if (result.equals(mylist.toString()))
				System.out.println("PASSED");
			else
				System.out.println("FAILED");  		
		}
		
					
		public static void sortQuickOppositeSorted(String result) {
			mylist = new ArrayListUnsorted<Integer>(LOW);
			for (int i = LOW; i > 0; i--)
				mylist.insert(i);

			System.out.println("Before: " + mylist);	
			mylist.myquick();;	
			System.out.println("After: " + mylist);	
			
			if (result.equals(mylist.toString()))
				System.out.println("PASSED");
			else
				System.out.println("FAILED");   		
		}
			
		public static void sortMergeOppositeSorted(String result) {
			mylist = new ArrayListUnsorted<Integer>(LOW);
			for (int i = LOW; i > 0; i--)
				mylist.insert(i);

			System.out.println("Before: " + mylist);	
			mylist.mymerge();	
			System.out.println("After: " + mylist);	
					
			if (result.equals(mylist.toString()))
				System.out.println("PASSED");
			else
				System.out.println("FAILED");  		
		}
		
		
		
		public static void main(String[] args) {
			String result = "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]";	
//			String result = "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24]";  // uncomment for even test
			
			System.out.println("Tests:");
			System.out.println("Label: insertion sort of array");
			sortInsertionOppositeSorted(result);
			
			System.out.println("Label: insertion sort of linked");
			sortInsertionOppositeSorted2(result);
			
			System.out.println("Label: odd-even sort of array");
			sortOddEvenOppositeSorted(result);
			
			System.out.println("Label: odd-even sort of linked");
			sortOddEvenOppositeSorted2(result);
			
			System.out.println("Label: count sort of data sorted in opposite order");			
			sortCountSortOppositeSorted(result);
						
			System.out.println("Label: quick sort of data sorted in opposite order");			
			sortQuickOppositeSorted(result);
						
			System.out.println("Label: merge sort of data sorted in opposite order");
			sortMergeOppositeSorted(result);
			
		}

}
