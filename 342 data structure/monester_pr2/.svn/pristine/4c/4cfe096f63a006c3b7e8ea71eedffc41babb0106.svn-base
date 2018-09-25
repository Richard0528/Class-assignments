//package mylistpackage;

import java.util.Date;
import java.util.Random;

public class RunnerLinkedList {
	
	
		private static LinkedListUnsorted<Integer> mylist;
		private static Random myrandom;
		final private static int LOW = 25000;
		final private static int MED = 100000;
		final private static int HIMED = 250000;
		final private static int HI = 500000;
		
		public static void sortInsertionSorted(int capacity) {
			mylist = new LinkedListUnsorted<Integer>();
			for (int i = 1; i <= capacity; i++)
				mylist.insert( i );
					
			//System.out.println(mylist.toString());
			Date startDate = new Date();
			long startTime = startDate.getTime();
			mylist.myinsertion();
			//System.out.println(mylist.toString());
			Date finishDate = new Date();
	        long finishTime = finishDate.getTime();
	        long totmylistTime = (finishTime - startTime);   
	        System.out.println(capacity + "\t" + totmylistTime);      		
		}
		
		public static void sortInsertionOppositeSorted(int capacity) {
			mylist = new LinkedListUnsorted<Integer>();
			for (int i = capacity; i > 0; i--)
				mylist.insert(i);
			//System.out.println(mylist.toString());
			Date startDate = new Date();
			long startTime = startDate.getTime();
			mylist.myinsertion();
			Date finishDate = new Date();
	        long finishTime = finishDate.getTime();
	        long totmylistTime = (finishTime - startTime);    
	        System.out.println(capacity + "\t" + totmylistTime);    		
		}
		
		public static void sortInsertionRandom(int capacity) {
			mylist = new LinkedListUnsorted<Integer>();
			int r;
			myrandom = new Random();
			for (int i = 1; i <= capacity; i++) {
				r = myrandom.nextInt() % capacity;
				mylist.insert(r);
			}
			//System.out.println(mylist.toString());
			Date startDate = new Date();
			long startTime = startDate.getTime();
			mylist.myinsertion();
			Date finishDate = new Date();
	        long finishTime = finishDate.getTime();
	        long totmylistTime = (finishTime - startTime);   
	        System.out.println(capacity + "\t" + totmylistTime);      		
		}
		
		public static void sortOddEvenSorted(int capacity) {
			mylist = new LinkedListUnsorted<Integer>();
			for (int i = 1; i <= capacity; i++)
				mylist.insert(i);		
			//System.out.println(mylist.toString());
			Date startDate = new Date();
			long startTime = startDate.getTime();
			mylist.myOddEven();					
			//System.out.println(mylist.toString());
			Date finishDate = new Date();
	        long finishTime = finishDate.getTime();
	        long totmylistTime = (finishTime - startTime);   
	        System.out.println(capacity + "\t" + totmylistTime);      		
		}
		
		public static void sortOddEvenOppositeSorted(int capacity) {
			mylist = new LinkedListUnsorted<Integer>();
			for (int i = capacity; i > 0; i--)
				mylist.insert(i);
			//System.out.println(mylist.toString());
			Date startDate = new Date();
			long startTime = startDate.getTime();
			mylist.myOddEven();						
			//System.out.println(mylist.toString());
			Date finishDate = new Date();
	        long finishTime = finishDate.getTime();
	        long totmylistTime = (finishTime - startTime);    
	        System.out.println(capacity + "\t" + totmylistTime);    		
		}
		
		public static void sortOddEvenRandom(int capacity) {
			mylist = new LinkedListUnsorted<Integer>();
			int r;
			myrandom = new Random();
			for (int i = 1; i <= capacity; i++) {
				r = myrandom.nextInt() % capacity;
				mylist.insert(r);
			}
			//System.out.println(mylist.toString());
			Date startDate = new Date();
			long startTime = startDate.getTime();
			mylist.myOddEven();					// change call
			Date finishDate = new Date();
	        long finishTime = finishDate.getTime();
	        long totmylistTime = (finishTime - startTime);   
	        System.out.println(capacity + "\t" + totmylistTime);      		
		}
		
		public static void main(String[] args) {
			System.out.println("Number of elements:\tTime to sort (ms):");
			System.out.println("Label: insertion sort of sorted data");
			for (int i = 0; i < 3; i++) {
				sortInsertionSorted(LOW);
				sortInsertionSorted(MED);
				sortInsertionSorted(HIMED);
				//sortInsertionSorted(HI);
			}
			System.out.println("Label: insertion sort of data sorted in opposite order");
			for (int i = 0; i < 3; i++) {
				sortInsertionOppositeSorted(LOW);
				sortInsertionOppositeSorted(MED);
				sortInsertionOppositeSorted(HIMED);
				//sortInsertionOppositeSorted(HI);
			}
			System.out.println("Label: insertion sort of random data");
			for (int i = 0; i < 3; i++) {
				sortInsertionRandom(LOW);
				sortInsertionRandom(MED);
				sortInsertionRandom(HIMED);
				//sortInsertionRandom(HI);
			}
			System.out.println("Label: odd-even sort of sorted data");
			for (int i = 0; i < 3; i++) {
				sortOddEvenSorted(LOW);
				sortOddEvenSorted(MED);
				sortOddEvenSorted(HIMED);
				//sortOddEvenSorted(HI);
			}
			System.out.println("Label: odd-even sort of data sorted in opposite order");
			for (int i = 0; i < 3; i++) {
				sortOddEvenOppositeSorted(LOW);
				sortOddEvenOppositeSorted(MED);
				sortOddEvenOppositeSorted(HIMED);
				//sortOddEvenOppositeSorted(HI);
			}
			System.out.println("Label: odd-even sort of random data");
			for (int i = 0; i < 3; i++) {
				sortOddEvenRandom(LOW);
				sortOddEvenRandom(MED);
				sortOddEvenRandom(HIMED);
				//sortOddEvenRandom(HI);
			}
		}

}
