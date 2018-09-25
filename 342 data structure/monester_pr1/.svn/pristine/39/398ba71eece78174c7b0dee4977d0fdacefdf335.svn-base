package mysetpackage;

/**
 * Represents basic unsorted array-based set.
 * 
 * @author richardyang.
 * @version 1.21
 * @param <E> is of any object type
 */
public class ArraySetUnsorted<E> extends AbstractArraySet<E> {

    /**
     * Constructs an empty list of default capacity.
     */
    public ArraySetUnsorted() {
        super();
    }

    /**
     * Constructs an empty list of the given capacity.
     * 
     * @param capacity > 0
     * @throws IllegalArgumentException if capacity <= 0
     */
    public ArraySetUnsorted(int capacity) {
        super(capacity);
    }

    @Override
    public void remove(E value) {
        int index = getIndex(value);
        if (size >= 0 && index >= 0) {
        		elementData[index] = elementData[size];
            size--;
        }
    }

    /*********************************************
     * Index list methods follow
     *********************************************/
    
    @Override
    public void set(int index, E value) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }
        if (contains(value)) {
        		throw new IllegalArgumentException();
        }
        elementData[index] = value;
    }

    @Override
    public void removeAtIndex(int index) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }
        elementData[index] = elementData[size];
        size--;
    }
    

    /*********************************************
     * Test
     *********************************************/
//    
//    public static void main(String[] args) {
//
//    		ArraySetUnsorted<String> a1 = new ArraySetUnsorted<String>();
////  		for (int i = 0; i < 205; i++)
////			a1.insert("str" + i);
////		Iterator<String> itr = a1.iterator();
////		String str = "[" + itr.next();
////		while (itr.hasNext()) {
////			str += ", " + itr.next();
////		}
//    		a1.insert("aaa");
//		a1.insert("bbb");
//		a1.insert("ccc");
//		a1.clear();
//  		System.out.println(a1);
//    }

}
