//package mylistpackage;

import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Represents basic unsorted node-based list.
 * 
 * @author modified from Building Java Programs 3rd ed.
 * @version Sep 2016
 * @param <E> is of any object type
 */
public class LinkedListUnsorted<E extends Comparable<? super E>> {

    /**
     * Reference to the first node in the list.
     */
    private ListNode<E> front; 
    
    /**
     * Reference to the last node in the list.
     */
    private ListNode<E> back; 

    /**
     * index of the last list element
     */
    private int size;  

    /**
     * Constructs an empty list.
     */
    public LinkedListUnsorted() {
        front = null;
        back = null;
        size = -1;
    }

    /**
     * @see mylistpackage.MyList#getSize()
     */
    public int getSize() {
        return size + 1;
    }

    /**
     * @see mylistpackage.MyList#isEmpty()
     */
    public boolean isEmpty() {
        return size == -1;
    }

    /**
     * @see mylistpackage.MyList#contains(java.lang.Object)
     */
    public boolean contains(E value) {
        return getIndex(value) >= 0;
    }

    /**
     * @see mylistpackage.MyList#insert(java.lang.Object)
     */
    public void insert(E value) {
    	ListNode<E> valueNode = new ListNode<E>(value);
        if (size == -1) {
        	front = valueNode;
        	back = valueNode;
        } else {
        	back.next = valueNode;
        	back = valueNode;
        }
        size++;
    }  

    /**
     * @see mylistpackage.MyList#clear()
     */
    public void clear() {
        front = null;
        back = null;
        size = -1;
    }


    /**
     * Creates a comma-separated, bracketed version of the list.
     * 
     * @see java.lang.Object#toString()
     */
    public String toString() {
        if (size == -1) {
            return "[]";
        } else {
            String result = "[" + front.data;
            ListNode<E> current = front.next;
            while (current != null) {
                result += ", " + current.data;
                current = current.next;
            }
            result += "]";
            return result;
        }
    }
    
    /**
     * @see mylistpackage.MyList#remove(java.lang.Object)
     */
    public void remove(E value) {
    	if (size > -1) {					 // if the list is not empty
    		if (value.equals(front.data)) {  // if value in the first node
    			front = front.next;
    			if (size == 0)				 // if it was the only node
    				back = null;
    			size--;
    		}
    		else {							  // value not in the first node
    			ListNode<E> prior = front;	  // set up a trailing reference
    	        while (prior.next != null) {   // look ahead one node
    	            if (prior.next.data.equals(value)) { // found it
    	            	prior.next = prior.next.next;
    	            	if (prior.next == null)    // if deleting the last node
    	            		back = prior;
    	            	size--;
    	            	break;
    	            } //endif
    	            prior = prior.next;
    	        } //endwhile
    		} // endelse
    	}
        
    }

    /*********************************************
     * Index list methods follow
     *********************************************/

    /**
     * Returns the index of value.
     * 
     * @param value assigned.
     * @return index of value if in the list, -1 otherwise.
     */
    public int getIndex(E value) {
        int index = 0;
        ListNode<E> current = front;
        while (current != null) {
            if (current.data.equals(value)) {
                return index;
            }
            index++;
            current = current.next;
        }
        return -1;
    }
    
    /**
     * Removes value at the given index, shifting subsequent values up.
     * 
     * @param index <= size and index >= 0
     * @throws IndexOutOfBoundsException if index < 0 or index > size
     */
    public void removeAtIndex(int index) {
        checkIndex(index);
        if (index == 0) {
            front = front.next;
            if (size == 0)
                back = null;
        }
        else {
            ListNode<E> current = nodeAt(index - 1);
            current.next = current.next.next;
            if (current.next == null)
                back = current;
        }
        
        size--;
    }
    
    /**
     * Replaces the value at the given index with the given value.
     * 
     * @param 0 <= index <=size
     * @param value is assigned
     * @throws IndexOutOfBoundsException if index < 0 or index > size
     */
    public void set(int index, E value) {
        checkIndex(index);
        ListNode<E> current = nodeAt(index);
        current.data = value;
    }
    
    /**
     * Returns the value at the given index in the list.
     * 
     * @param 0 <= index <=size
     * @throws IndexOutOfBoundsException if index < 0 or index > size
     * @return the value at the given index in the list.
     */
    public E get(int index) {
        checkIndex(index);
        ListNode<E> current = nodeAt(index);
        return current.data;
    } 

    /**
     * Returns the node at a specific index.
     * @param index where 0 <= index <= size
     * @return reference to the node at a specific index
     */
    private ListNode<E> nodeAt(int index) {
        ListNode<E> current = front;
        for (int i = 1; i <= index; i++) {
                current = current.next;
        }
        return current;
    }

    
    /**
     * Checks if the index is a legal index of the current list.
     * @param index
     * @throws IndexOutOfBoundsException if the given index is not a legal index of the current list
     */
    private void checkIndex(int index) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("index: " + index);
        }
    }
    
    /*********************************************
     * Index list methods end
     *********************************************/
    
    // 5 sorting methods
    
	public void myinsertion() {
		
		// initialize sorted linked list
		ListNode<E> sorted = null;
		ListNode<E> current = front;
		
		// loop through whole linked list
		while (current != null) {
			
			ListNode<E> next = current.next;
			
			// if it's the first node or the order is correct, just append to the current list
			if (sorted == null || sorted.data.compareTo(current.data) >= 0) {
				current.next = sorted;
				sorted = current;
			} else {
				ListNode<E> prior = sorted;
				
				while (prior.next != null && prior.next.data.compareTo(current.data) < 0) {
					prior = prior.next;
				}
				
				current.next = prior.next;
				prior.next = current;
			}
			
			current = next;
		}
		
		// update the front reference.
		front = sorted;
		
	}
	
	public void myOddEven() {

		boolean isSorted = false;
		
		while (!isSorted) {
			isSorted = true;
			E temp;
			ListNode<E> odd = front.next;  // initial first node for odd case
			ListNode<E> even = front;  // initial first node for even case
			
			// Perform Bubble sort on odd indexed element
//			System.out.println(odd.data);
			for (int i = 1; i < size; i+=2) {
//				System.out.println("odd:" + odd.data + "odd.next:" + odd.next.data);
				if (odd.data.compareTo(odd.next.data) > 0) {
					temp = odd.data;
					odd.data = odd.next.data;
					odd.next.data = temp;
					isSorted = false;
				}
				odd = odd.next.next;
//				System.out.println(odd.data);
			}
			
			// Perform Bubble sort on even indexed element
//			System.out.println("WOWO");
			for (int i = 0; i < size; i+=2) {
//				System.out.println("even:" + even.data + "even.next:" + even.next.data);
				if (even.data.compareTo(even.next.data) > 0) {
					temp = even.data;
					even.data = even.next.data;
					even.next.data = temp;
					isSorted = false;
				}
				even = even.next.next;
			}
			
			
			
			
		}
		
		
	}
    
    

    /*********************************************
     * Iterator list class / methods follow
     *********************************************/
    
    /**
     * Returns an iterator for this list.
     * 
     * @return an iterator for the list.
     */
    public Iterator<E> iterator() {
        return new LinkedIterator();
    }

    /**
     * Represents a list node.
     * @author Building Java Programs 3rd ed.
     *
     * @param <E> is of any object type
     */
    private static class ListNode<E> {

        /**
         * Data stored in this node.
         */
        public E data; 

        /**
         * Link to next node in the list.
         */
        public ListNode<E> next;  

       
        /**
         * Constructs a node with given data and a null link.
         * @param data assigned
         */
        public ListNode(E data) {
            this(data, null);
        }

        /**
         * Constructs a node with given data and given link.
         * @param data assigned
         * @param next assigned
         */
        public ListNode(E data, ListNode<E> next) {
            this.data = data;
            this.next = next;
        }
    }

    /**
     * Represents an iterator for the list.
     * 
     * @author modified from BuildingJavaPrograms 3rd Edition
     */
    private class LinkedIterator implements Iterator<E> {
        
        /**
         * Location of current value to return.
         */
        private ListNode<E> current; 

        /**
         * flag that indicates whether list element can be removed.
         */
        private boolean removeOK; 
        
        /**
         * Location of the prior value in case of removal.
         */
        private ListNode<E> prior;

        /**
         * Constructs an iterator for the given list.
         */
        public LinkedIterator() {
            current = front;
            removeOK = false;
            prior = null;
        }

        /**
         * Returns whether there are more list elements.
         * 
         * @return true if there are more elements left, false otherwise
         * @see java.util.Iterator#hasNext()
         */
        public boolean hasNext() {
            return current != null;
        }

        /**
         * Returns the next element in the iteration.
         * 
         * @throws NoSuchElementException if no more elements.
         * @return the next element in the iteration.
         * @see java.util.Iterator#next()
         */
        public E next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            prior = current;
            E result = current.data;
            current = current.next;
            removeOK = true;
            return result;
        }

        /**
         * Removes the last element returned by the iterator.
         * 
         * @throws IllegalStateException if a call to next has not been made
         *             before call to remove.
         * @see java.util.Iterator#remove()
         */
        public void remove() {
            if (!removeOK) {
                throw new IllegalStateException();
            }
            LinkedListUnsorted.this.remove(prior.data);
            removeOK = false;
        }
    }

    
}

