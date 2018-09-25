package mysetpackage;

import java.util.Iterator;

/**
 * Represents MySet interface.
 * 
 * @author Monika
 * @version Dec 2017
 * @param <Type> is of any object type.
 */
public interface MySet<Type> {

    /**
     * Returns the current number of elements in the set.
     * 
     * @return the current number of elements in the set >= 0
     */
    public int getSize();

    /**
     * Returns whether the set is empty.
     * 
     * @return true if set is empty, false otherwise.
     */
    public boolean isEmpty();

    /**
     * Returns whether value is in the set.
     * 
     * @param value assigned
     * @return true if value in the set, false otherwise.
     */
    public boolean contains(Type value);

    /**
     * Inserts a unique element into the set.
     * 
     * @param value assigned
     */
    public void insert(Type value);

    
    /**
     * Clears the set.
     */
    public void clear();
    
    /**
     * Returns a string representation of set contents.
     * 
     * @return a string representation of set contents.
     * @see Object#toString()
     */
    @Override
    public String toString();
    
    /**
     * Removes element occurrence from the set.
     * 
     * @param value assigned
     */
    public void remove(Type value);
    
    /*********************************************
     * Index set methods follow
     *********************************************/

    /**
     * Returns the index of value.
     * 
     * @param value assigned.
     * @return index of value if in the set, -1 otherwise.
     */
    public int getIndex(Type value);

    
    /**
     * Removes value at the given index.
     * 
     * @param  0 <= index < number of elements
     * @throws IndexOutOfBoundsException if index < 0 or index >= number of elements
     */
    public void removeAtIndex (int index);
    
    /**
     * Replaces the value at the given index with the given value.
     * 
     * @param 0 <= index < number of elements
     * @value is assigned
     * @throws IndexOutOfBoundsException if index < 0 or index >= number of elements
     */
    public void set(int index, Type value);
    
    /**
     * Returns the value at the given index in the set.
     * 
     * @param index 0 <= index < number of elements
     * @throws IndexOutOfBoundsException if index < 0 or index >= number of elements
     * @return the value at the given index in the set.
     */
    
    public Type get(int index);
    
    /*********************************************
     * Index set methods end
     *********************************************/

    /*********************************************
     * Iterator set class / methods follow
     *********************************************/

    /**
     * Returns an iterator for this set.
     * 
     * @return an iterator for the set.
     */
    public Iterator<Type> iterator();

    /*********************************************
     * Iterator set class / methods end
     *********************************************/
    
    

}
