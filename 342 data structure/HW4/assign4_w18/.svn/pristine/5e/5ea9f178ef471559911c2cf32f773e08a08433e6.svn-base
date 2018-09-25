package mymaps;

import java.io.Serializable;
import java.util.Collection;
import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * HashSet implementation.
 * Matches are based on equals; and hashCode must be consistently defined.
 */
public class HashTable<AnyKey, AnyValue> implements MyMap<AnyKey, AnyValue> {
	
	private static final int DEFAULT_TABLE_SIZE = 101;
    
    private int currentSize = 0;
    private int occupied = 0;
    private int modCount = 0;
    private HashEntry [ ] array;
	
    /**
     * Construct an empty HashSet.
     */
    public HashTable( )
    {
        allocateArray( DEFAULT_TABLE_SIZE );
        clear( );
    }
    
    /**
     * Construct a HashSet from any collection.
     */
//    public HashSet( Collection<? extends AnyKey> other)
//    {
//        allocateArray( nextPrime( other.size( ) * 2 ) );
//        clear( );
//        
//        for( AnyKey val : other )
//            add( val );    
//    }
    
    /**
     * Returns the number of items in this collection.
     * @return the number of items in this collection.
     */
    public int size( )
    {
        return currentSize;
    }
    
    /**
     * This method is not part of standard Java.
     * Like contains, it checks if x is in the set.
     * If it is, it returns the reference to the matching
     * object; otherwise it returns null.
     * @param x the object to search for.
     * @return if contains(x) is false, the return value is null;
     * otherwise, the return value is the object that causes
     * contains(x) to return true.
     */
    public AnyKey getMatch( AnyKey x )
    {
        int currentPos = findPos( x );

        if( isActive( array, currentPos ) )
            return (AnyKey) array[ currentPos ].key;
        return null;
    }
    
    /**
     * Tests if some item is in this collection.
     * @param x any object.
     * @return true if this collection contains an item equal to x.
     */
    public boolean contains( AnyKey x )
    {
        return isActive( array, findPos( x ) );
    }
    
    /**
     * Tests if item in pos is active.
     * @param pos a position in the hash table.
     * @param arr the HashEntry array (can be oldArray during rehash).
     * @return true if this position is active.
     */
    private static boolean isActive( HashEntry [ ] arr, int pos )
    {
        return arr[ pos ] != null && arr[ pos ].isActive;
    }
    
    /**
     * Adds an item to this collection.
     * helper function for put method
     * @param x any object.
     */
    public void put( AnyKey x, AnyValue y )
    {
        int currentPos = findPos( x );
        if( !isActive( array, currentPos ) ) {
       
        		if( array[ currentPos ] == null ) 
        			occupied++;
        		array[ currentPos ] = new HashEntry( x, y, true );
        		currentSize++;
        		modCount++;
        
        		if( occupied > array.length / 2 )        
        			rehash( );
        } else {
        		array[currentPos].element = y;
        }
    }
    
//    @Override
//	public void put(AnyKey x, AnyValue y) {
//		if (contains(x)) {
//			int currentPos = findPos(x);
//			array[currentPos].element = y;
//		} else {
//			add(x ,y);
//		}
//	}

	@Override
	public AnyValue get(AnyKey x) {
		if (contains(x)) {
			int currentPos = findPos(x);
			return (AnyValue) array[currentPos].element;
		} else {
			return null;
		}
	}
	
	@Override
	public String toString() {
		
		Iterator<AnyKey> ltr1 = iterator();
		Iterator<AnyKey> ltr2 = iterator();
		String result = "{" + ltr1.next() + "=" + get(ltr2.next());
		while (ltr1.hasNext() && ltr2.hasNext()) {
//			AnyValue data = get(ltr.next());
			result += ", " + ltr1.next() + "=" + get(ltr2.next());
		}
		result += "}";
		
		return result;
	}
    
    /**
     * Private routine to perform rehashing.
     * Can be called by both add and remove.
     */
    private void rehash( )
    {
        HashEntry [ ] oldArray = array;
        
            // Create a new, empty table
        allocateArray( nextPrime( 4 * size( ) ) );
        currentSize = 0;
        occupied = 0;
        
            // Copy table over
        for( int i = 0; i < oldArray.length; i++ )
            if( isActive( oldArray, i ) ) 
                put( (AnyKey) oldArray[ i ].key, (AnyValue) oldArray[ i ].element );
    }
    
    /**
     * Removes an item from this collection.
     * @param x any object.
     * @return true if this item was removed from the collection.
     */
    public void remove( Object x )
    {
        int currentPos = findPos( x );
        if( isActive( array, currentPos ) ) {
        		array[ currentPos ].isActive = false;
        		currentSize--;
        		modCount++;    

        		if( currentSize < array.length / 8 )
        			rehash( );
        }
        
    }
    
    /**
     * Change the size of this collection to zero.
     */
    public void clear( )
    {
        currentSize = occupied = 0;
        modCount++;
        for( int i = 0; i < array.length; i++ )
            array[ i ] = null;
    }
    
    /**
     * Obtains an Iterator object used to traverse the collection.
     * @return an iterator positioned prior to the first element.
     */
    public Iterator<AnyKey> iterator( )
    {
        return new HashSetIterator( );
    }
    
    /**
     * This is the implementation of the HashSetIterator.
     * It maintains a notion of a current position and of
     * course the implicit reference to the HashSet.
     */
    private class HashSetIterator implements Iterator<AnyKey>
    {
        private int expectedModCount = modCount;
        private int currentPos = -1;
        private int visited = 0;       
        
        public boolean hasNext( )
        {
            if( expectedModCount != modCount )
                throw new ConcurrentModificationException( );
            
            return visited != size( );    
        }
        
        public AnyKey next( )
        {
            if( !hasNext( ) )
                throw new NoSuchElementException( );
                          
            do
            {
                currentPos++;
            } while( currentPos < array.length && !isActive( array, currentPos ) );
                            
            visited++;
            return (AnyKey) array[ currentPos ].key;    
        }
        
        public void remove( )
        {
            if( expectedModCount != modCount )
                throw new ConcurrentModificationException( );              
            if( currentPos == -1 || !isActive( array, currentPos ) )
                throw new IllegalStateException( );
    
            array[ currentPos ].isActive = false;
            currentSize--;
            visited--;
            modCount++;
            expectedModCount++;
        }
    }
    
    private static class HashEntry<AnyKey, AnyValue> implements Serializable
    {
        public AnyKey  key;   // the key
        public AnyValue element;  // the element
        public boolean isActive;  // false if marked deleted

        public HashEntry( AnyKey theKey, AnyValue theElement )
        {
            this( theKey, theElement, true );
        }

        public HashEntry( AnyKey theKey, AnyValue theElement, boolean i )
        {
            key  = theKey;
            element = theElement;
            isActive = i;
        }
    }
    
    
    /**
     * Method that performs quadratic probing resolution.
     * Assumes table is at least half-empty.
     * @param x the item to search for.
     * @return the position where the search terminates.
     */
    private int findPos( Object x )
    {
        int offset = 1;
        int currentPos = ( x == null ) ? 0 : Math.abs( x.hashCode( ) % array.length );

        while( array[ currentPos ] != null )
        {
            if( x == null )
            {
                if( array[ currentPos ].key == null )
                    break;
            }
            else if( x.equals( array[ currentPos ].key ) )   
                break; 
            
            currentPos += offset;                  // Compute ith probe
            offset += 2;
            if( currentPos >= array.length )       // Implement the mod
                currentPos -= array.length;
        }

        return currentPos;
    }
    
    
    /**
     * Internal method to allocate array.
     * @param arraySize the size of the array.
     */
    private void allocateArray( int arraySize )
    {
        array = new HashEntry[ nextPrime( arraySize ) ];
    }

    /**
     * Internal method to find a prime number at least as large as n.
     * @param n the starting number (must be positive).
     * @return a prime number larger than or equal to n.
     */
    private static int nextPrime( int n )
    {
        if( n % 2 == 0 )
            n++;

        for( ; !isPrime( n ); n += 2 )
            ;

        return n;
    }

    /**
     * Internal method to test if a number is prime.
     * Not an efficient algorithm.
     * @param n the number to test.
     * @return the result of the test.
     */
    private static boolean isPrime( int n )
    {
        if( n == 2 || n == 3 )
            return true;

        if( n == 1 || n % 2 == 0 )
            return false;

        for( int i = 3; i * i <= n; i += 2 )
            if( n % i == 0 )
                return false;

        return true;
    }
	
}
