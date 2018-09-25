package mysetpackage;

/**
 * Represents basic sorted array-based set.
 * 
 * @author richardyang
 * @version 1.21
 * @param <E> is of any comparable object type
 */
public class ArraySetSorted<E extends Comparable<? super E>> extends AbstractArraySet<E> {
    
	/**
     * Constructs an empty list of default capacity.
     */
    public ArraySetSorted() {
    		super();
    }
    
    /**
     * Constructs an empty list of the given capacity.
     * 
     * @param capacity > 0
     * @throws IllegalArgumentException if capacity <= 0
     */
    @SuppressWarnings("unchecked")
    public ArraySetSorted(int capacity) {
    		if (capacity <= 0) {
            throw new IllegalArgumentException("capacity: " + capacity);
        }
        elementData = (E[]) new Comparable[capacity];
        size = -1;
    }
    
    /**
     * helper function for binary search.
     * 
     * @param value
     * @return integer array, first index is 
     */
    private int binarySearch(E value) {
    		int start = 0;
    		int end = size;
    		int result;
    		while (start <= end) {
    			int middle = (start + end) / 2;
    			if (elementData[middle] == (value)) {
    				result = middle;
    				return result;
    			}
    			if (elementData[middle].compareTo(value) > 0) {
    				end = middle - 1;
    			} else {
    				start = middle + 1;
    			}
    			
    		}
    		
    		result = start;
    		return result;

    }
	
	@Override
    public void insert(E value) {
    		// if the value is not contained, it will be added; otherwise, do not add.
    		if (!contains(value)) {
    			if (size == -1) {
    				size++;
    				elementData[size] = value;
    			} else {
    				ensureCapacity(size + 2);
    				
    				int result = binarySearch(value);
    				size++;
    				int index = result;
    				for (int i = size; i > index ; i--) {
    					elementData[i] = elementData[i - 1];
    				}
    				
    				elementData[index] = value;
    			}
    		}	
    }
    
	@Override
	public void remove(E value) {
		int index = getIndex(value);
		if (size >= 0 && index >= 0) {
			for (int i = index; i < size; i++) {
				elementData[i] = elementData[i + 1];
			}
			size--;
		}
	}

    /*********************************************
     * Index list methods follow
     *********************************************/

	@Override
    public void set(int index, E value) {
		int realIndex = binarySearch(value);
		
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }
        if (index == 0) {
        		elementData[index] = value;
        } else if (realIndex != index) {
        		throw new IllegalArgumentException();
        }
        elementData[index] = value;
    }
	
	@Override
	public void removeAtIndex(int index) {
		if (index < 0 || index > size) {
			throw new IndexOutOfBoundsException();
		}
		for (int i = index; i < size; i++)
			elementData[i] = elementData[i + 1];
		size--;
		
	}
	

    /*********************************************
     * Test
     *********************************************/
    
    public static void main(String[] args) {
        
        ArraySetSorted<String> a1 = new ArraySetSorted<String>(3);
        for (int i = 100; i < 300; i++) {
			a1.insert("str" + i);
        }
        
        a1.remove("str201");
        
//        a1.insert("str99");
//        a1.insert("str98");
//        a1.insert("str97");
//        a1.insert("str0");
        
        System.out.println(a1);
        
    }
    
    
}
